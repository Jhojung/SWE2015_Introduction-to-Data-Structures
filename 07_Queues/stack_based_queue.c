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

void enqueue(Stack *stack1, Stack *stack2, int item);
int dequeue(Stack *stack1, Stack *stack2);

int main() {
  Stack stack1, stack2;

  stack1 = createStack();
  stack2 = createStack();

  enqueue(&stack1, &stack2, 4);
  enqueue(&stack1, &stack2, 1);
  enqueue(&stack1, &stack2, 2);
  printf("%d\n", dequeue(&stack1, &stack2));
  enqueue(&stack1, &stack2, 3);
  printf("%d\n", dequeue(&stack1, &stack2));
  printf("%d\n", dequeue(&stack1, &stack2));
  printf("%d\n", dequeue(&stack1, &stack2));

  removeStack(&stack1);
  removeStack(&stack2);
  return 0;
}

void enqueue(Stack *stack1, Stack *stack2, int item) {
  // Write your own code
  push(stack1, item);
}

int dequeue(Stack *stack1, Stack *stack2) {
  // Write your own code
  if(isEmpty(stack2)) {
    while(!isEmpty(stack1)) push(stack2, pop(stack1));
  }

  return pop(stack2);
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