#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct _Stack {
  int top;
  int items[MAX_SIZE];
} Stack;

Stack createStack();
void removeStack(Stack *stack);

bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
void printItems(Stack *stack);

int main() {
  Stack stack;

  // Create a stack
  stack = createStack();

  push(&stack, 1);
  push(&stack, 3);
  push(&stack, 2);
  printItems(&stack);

  printf("Pop: %d\n", pop(&stack));
  printItems(&stack);

  push(&stack, 4);
  printItems(&stack);

  // Remove the stack
  removeStack(&stack);
  return 0;
}

Stack createStack() {
  // Write your own code
  Stack newStack;
  newStack.top = -1;
  return newStack;
}

void removeStack(Stack *stack) {
  // Nothing to do
}

bool isEmpty(Stack *stack) {
  // Write your own code
  return stack -> top == -1;
}

bool isFull(Stack *stack) {
  // Write your own code
  return stack -> top == MAX_SIZE-1;
}

void push(Stack *stack, int item) {
  // Write your own code
  if (isFull(stack)) {
    printf("Error: stack is already full\n");
    return;
  }

  (stack -> top)++;
  stack -> items[stack->top] = item;
}

int pop(Stack *stack) {
  // Write your own code
  if (isEmpty(stack)) {
    printf("Error: stack is empty\n");
    return 0;
  }

  int item = stack->items[stack->top];
  (stack -> top)--;
  return item;
}

int peek(Stack *stack) {
  // Write your own code
  if (isEmpty(stack)) {
    printf("Error: stack is empty\n");
    return 0;
  }

  return stack -> items[stack -> top];
}

void printItems(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack: empty\n");
    return;
  }

  printf("Stack:\n");
  for (int i = stack->top; i >= 0; i --) {
    printf("%d\n", stack->items[i]);
  }
  printf("\n");
}