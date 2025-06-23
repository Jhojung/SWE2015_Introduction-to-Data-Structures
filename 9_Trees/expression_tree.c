#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000

typedef struct _Node {
  char item;
  struct _Node *left, *right;
} Node;

Node *root;

Node* constructTree(char *exp);
void removeTree(Node *root);
void printInfix(Node *node);
int evaluate(Node *node);

int main() {
  char expression[MAX_LEN];
  printf("Postfix Expression: ");
  scanf("%s", expression);

  root = constructTree(expression);

  printf("Infix Expression: ");
  printInfix(root);
  printf("\nEvaluation Result = %d\n", evaluate(root));

  removeTree(root);
  return 0;
}

Node* constructTree(char exp[]) {
  // write your own code
  Node *stack[MAX_LEN], *left, *right;
  int top = -1;
  for (int i = 0; exp[i] != '\0'; i ++) {
    if ('0' <= exp[i] && exp[i] <= '9') {
      left = NULL;
      right = NULL;
    }
    else {
      right = stack[top--];
      left = stack[top--];
    }
    top ++ ;
    stack[top] = (Node *)malloc(sizeof(Node));
    stack[top]->item = exp[i];
    stack[top]->left = left;
    stack[top]->right = right;
  }
  return stack[0];
}

void removeTree(Node *root) {
  // write your own code
  if (root == NULL) return;
  removeTree(root->left);
  removeTree(root->right);
  free(root);
}

void printInfix(Node *node) {
  // write your own code
  if (node->left == NULL) {
    printf("%c", node->item);
    return;
  }
  printf("(");
  printInfix(node->left);
  printf("%c", node->item);
  printInfix(node->right);
  printf(")");
}

int evaluate(Node *node) {
  // write your own code
  if (node->left == NULL) {
    return node->item - '0';
  }
  int left = evaluate(node->left);
  int right = evaluate(node->right);
  if (node->item == '+') return left + right;
  if (node->item == '-') return left - right;
  if (node->item == '*') return left * right;
  if (node->item == '/') return left / right;
  return 0;
}
