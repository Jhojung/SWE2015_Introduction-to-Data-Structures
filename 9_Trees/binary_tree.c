#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
  char item;
  struct _Node *left, *right;
} Node;

Node *root;

Node* createNode(char item, Node *left, Node *right);
void removeNode(Node *node);
void removeLeftChild(Node *node);
void removeRightChild(Node *node);
int computeHeight(Node *node);

void traverseInOrder(Node *node);
void traversePreOrder(Node *node);
void traversePostOrder(Node *node);
void traverseLevelOrder(Node *root);

int main() {
  Node *J = createNode('J', NULL, NULL);
  Node *I = createNode('I', NULL, NULL);
  Node *H = createNode('H', NULL, NULL);
  Node *G = createNode('G', NULL, NULL);
  Node *F = createNode('F', NULL, J);
  Node *E = createNode('E', NULL, NULL);
  Node *D = createNode('D', H, I);
  Node *C = createNode('C', F, G);
  Node *B = createNode('B', D, E);
  Node *A = createNode('A', B, C);
  root = A;

  printf("Height: %d\n", computeHeight(root));

  printf("In-order traversal: ");
  traverseInOrder(root);
  printf("\n");

  printf("Pre-order traversal: ");
  traversePreOrder(root);
  printf("\n");

  printf("Post-order traversal: ");
  traversePostOrder(root);
  printf("\n");

  printf("Level-order traversal: ");
  traverseLevelOrder(root);
  printf("\n");

  printf("\n");
  printf("Remove the left child of B ...\n");
  removeLeftChild(B);

  printf("Remove the right child of F ...\n");
  removeRightChild(F);

  printf("Height: %d\n", computeHeight(root));

  printf("In-order traversal: ");
  traverseInOrder(root);
  printf("\n");

  printf("Pre-order traversal: ");
  traversePreOrder(root);
  printf("\n");

  printf("Post-order traversal: ");
  traversePostOrder(root);
  printf("\n");

  printf("Level-order traversal: ");
  traverseLevelOrder(root);
  printf("\n");

  removeNode(A);
  return 0;
}

Node* createNode(char item, Node *left, Node *right) {
  // write your own code
  Node *node = (Node *)malloc(sizeof(Node));
  node->item = item;
  node->left = left;
  node->right = right;
  return node;
}

int computeHeight(Node *node) {
  // write your own code
  if (node == NULL) return 0;
  int left_height = computeHeight(node->left);
  int right_height = computeHeight(node->right);
  if (left_height > right_height)
    return left_height + 1;
  else
    return right_height + 1;
}

void removeNode(Node *node) {
  // write your own code
  if (node == NULL) return;
  removeNode(node->left);
  removeNode(node->right);
  free(node);
}

void removeLeftChild(Node *node) {
  // write your own code
  removeNode(node->left);
  node->left = NULL;
}

void removeRightChild(Node *node) {
  // write your own code
  removeNode(node->right);
  node->right = NULL;
}

void traverseInOrder(Node *node) {
  // write your own code
  if (node == NULL) return;
  traverseInOrder(node->left);
  printf("%c ", node->item);
  traverseInOrder(node->right);
}

void traversePreOrder(Node *node) {
  // write your own code
  if (node == NULL) return;
  printf("%c ", node->item);
  traversePreOrder(node->left);
  traversePreOrder(node->right);
}

void traversePostOrder(Node *node) {
  // write your own code
  if (node == NULL) return;
  traversePostOrder(node->left);
  traversePostOrder(node->right);
  printf("%c ", node->item);
}

void traverseLevelOrder(Node *root) {
  // write your own code
  int front = 0, rear = 1;
  Node *queue[100] = { root, NULL, }, *node;
  while (front < rear) {
    node = queue[front++];
    printf("%c ", node->item);
    if (node->left != NULL) queue[rear++] = node->left;
    if (node->right != NULL) queue[rear++] = node->right;
  }
}
