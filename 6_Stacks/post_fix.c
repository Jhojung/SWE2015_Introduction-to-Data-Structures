#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct _Stack {
  int top;
  int items[MAX_SIZE+10];
} Stack;

Stack createStack();
void removeStack(Stack *stack);

bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);

int evaluatePostfix(char str[]);

int main() {
  char str[MAX_SIZE+10];
  Stack stack = createStack();

  scanf("%s", str);
  printf("%d\n", evaluatePostfix(str));
}

int evaluatePostfix(char str[]) {
  // Write your own code
  int i, result;
  int a, b;
  Stack stack = createStack();
  for (i = 0; str[i] != '\0'; i ++) {
    if ('0' <= str[i] && str[i] <= '9')
      push(&stack, str[i]-'0');
    else {
      a = pop(&stack);
      b = pop(&stack);
      if (str[i] == '+') push(&stack, b+a);
      else if (str[i] == '-') push(&stack, b-a);
      else if (str[i] == '*') push(&stack, b*a);
      else if (str[i] == '/') push(&stack, b/a);
    }
  }
  result = pop(&stack);
  removeStack(&stack);
  return result;
}

Stack createStack() {
  Stack newStack;
  newStack.top = -1;
  return newStack;
}

void removeStack(Stack *stack) {
  // Nothing to do
}

bool isEmpty(Stack *stack) {
  return stack->top == -1;
}

bool isFull(Stack *stack) {
  return stack->top == MAX_SIZE-1;
}

void push(Stack *stack, int item) {
  if (isFull(stack)) {
    return;
  }
  stack->items[++(stack->top)] = item;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    return 0;
  }
  return stack->items[(stack->top)--];
}

int peek(Stack *stack) {
  if (isEmpty(stack)) {
    return 0;
  }
  return stack->items[stack->top];
}
