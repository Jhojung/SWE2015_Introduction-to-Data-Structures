#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _Node {
    int item;
    struct _Node *next;
} Node;

typedef struct _Stack {
    Node *top;
} Stack;

Stack createStack();
void removeStack(Stack *stack);

bool isEmpty(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
void printItems(Stack *stack);

int main() {
    Stack stack;

    stack = createStack();

    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 2);
    printItems(&stack);

    printf("Pop: %d\n", pop(&stack));
    printItems(&stack);

    push(&stack, 4);
    printItems(&stack);

    return 0;
}

Stack createStack() {
    Stack newStack;
    newStack.top = NULL;
    return newStack;
}

void removeStack(Stack *stack) {
    // Nothing to do
}

bool isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for push\n");
        return;
    }

    newNode->item = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: stack is empty, cannot pop\n");
        return INT_MIN;
    }

    Node *temp = stack->top;
    int item = temp->item;
    stack->top = stack->top->next;
    free(temp);
    return item;
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: stack is empty, cannot peek\n");
        return INT_MIN;
    }
    return stack->top->item;
}

void printItems(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack: empty\n");
        return;
    }

    printf("Stack:\n");
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->item);
        current = current->next;
    }
    printf("\n");
}