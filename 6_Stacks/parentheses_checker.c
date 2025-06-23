#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct _Stack {
  int top;
  char items[MAX_SIZE+10];
} Stack;

Stack createStack();
void removeStack(Stack *stack);

bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, char item);
char pop(Stack *stack);
char peek(Stack *stack);

bool checkParentheses(char str[]);

int main() {
  char str[MAX_SIZE+10];
  Stack stack = createStack();

  scanf("%s", str);

  if (checkParentheses(str)) printf("VALID\n");
  else printf("NOT VALID\n");
}

bool checkParentheses(char str[]) {
    int i;
    char open_bracket;
    Stack stack = createStack();
  
    for (i = 0; str[i] != '\0'; i++) {
      char current_char = str[i];
  
      if (current_char == '{' || current_char == '(' || current_char == '[') {
        if (isFull(&stack)) {
            return false;
        }
        push(&stack, current_char);
      }
      else if (current_char == '}' || current_char == ')' || current_char == ']') {
        if (isEmpty(&stack)) {
          return false;
        }
  
        open_bracket = pop(&stack);
  
        if (!((open_bracket == '{' && current_char == '}') ||
              (open_bracket == '(' && current_char == ')') ||
              (open_bracket == '[' && current_char == ']'))) {
          return false;
        }
      }
    }
  
    bool validity = isEmpty(&stack);
    return validity;
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

void push(Stack *stack, char item) {
  if (isFull(stack)) {
    return;
  }
  stack->items[++(stack->top)] = item;
}

char pop(Stack *stack) {
  if (isEmpty(stack)) {
    return 0;
  }
  return stack->items[(stack->top)--];
}

char peek(Stack *stack) {
  if (isEmpty(stack)) {
    return 0;
  }
  return stack->items[stack->top];
}
