#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
  char item;
  struct _Node *left_child, *right_sibling;
} Node;

Node *root;

void printChildren(Node *node);
void printSubtree(Node *node, bool is_root);

int main() {
  Node *A = (Node *)malloc(sizeof(Node));
  Node *B = (Node *)malloc(sizeof(Node));
  Node *C = (Node *)malloc(sizeof(Node));
  Node *D = (Node *)malloc(sizeof(Node));
  Node *E = (Node *)malloc(sizeof(Node));
  Node *F = (Node *)malloc(sizeof(Node));
  Node *G = (Node *)malloc(sizeof(Node));
  Node *H = (Node *)malloc(sizeof(Node));
  Node *I = (Node *)malloc(sizeof(Node));
  Node *J = (Node *)malloc(sizeof(Node));
  Node *K = (Node *)malloc(sizeof(Node));
  Node *L = (Node *)malloc(sizeof(Node));

  A->item = 'A';
  B->item = 'B';
  C->item = 'C';
  D->item = 'D';
  E->item = 'E';
  F->item = 'F';
  G->item = 'G';
  H->item = 'H';
  I->item = 'I';
  J->item = 'J';
  K->item = 'K';
  L->item = 'L';

  root = A;
  A->left_child = B;    A->right_sibling = NULL;
  B->left_child = E;    B->right_sibling = C;
  C->left_child = G;    C->right_sibling = D;
  D->left_child = H;    D->right_sibling = NULL;
  E->left_child = J;    E->right_sibling = F;
  F->left_child = NULL;  F->right_sibling = NULL;
  G->left_child = NULL;  G->right_sibling = NULL;
  H->left_child = L;    H->right_sibling = I;
  I->left_child = NULL;   I->right_sibling = NULL;
  J->left_child = NULL;  J->right_sibling = K;
  K->left_child = NULL;  K->right_sibling = NULL;
  L->left_child = NULL;  L->right_sibling = NULL;

  printChildren(A);
  printChildren(C);
  printChildren(D);
  printChildren(H);

  printf("A's subtree: ");
  printSubtree(A, true);
  printf("\n");

  printf("B's subtree: ");
  printSubtree(B, true);
  printf("\n");

  free(A);
  free(B);
  free(C);
  free(D);
  free(E);
  free(F);
  free(G);
  free(H);
  free(I);
  free(J);
  free(K);
  free(L);
  return 0;
}

void printChildren(Node *node) {
    printf("%c's children: ", node->item);
    for (Node *child = node->left_child; child != NULL; child = child->right_sibling)
      printf("%c ", child->item);
    printf("\n");
}
  
void printSubtree(Node *node, bool is_root) {
    if (node == NULL) return;
    printf("%c ", node->item);
    printSubtree(node->left_child, false);
    if (!is_root) printSubtree(node->right_sibling, false);
}
