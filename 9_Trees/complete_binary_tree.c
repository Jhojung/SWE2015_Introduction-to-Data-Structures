#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N;
char completeTree[100];

void printNodeInfo(char tree[], int n);
void printParent(char tree[], int n);
void printChildren(char tree[], int n);
void printSibling(char tree[], int n);
void printAncestors(char tree[], int n);
void printDescendants(char tree[], int n);

int main() {
  N = 12;
  completeTree[1] = 'A';
  completeTree[2] = 'X';
  completeTree[3] = 'Z';
  completeTree[4] = 'S';
  completeTree[5] = 'C';
  completeTree[6] = 'I';
  completeTree[7] = 'G';
  completeTree[8] = 'T';
  completeTree[9] = 'O';
  completeTree[10] = 'D';
  completeTree[11] = 'F';
  completeTree[12] = 'Y';

  int n = 2;
  printNodeInfo(completeTree, n);
  return 0;
}

void printNodeInfo(char tree[], int n) {
  printf("%c's parent: ", tree[n]);
  printParent(tree, n);
  printf("\n");

  printf("%c's children: ", tree[n]);
  printChildren(tree, n);
  printf("\n");

  printf("%c's sibling: ", tree[n]);
  printSibling(tree, n);
  printf("\n");

  printf("%c's ancestors: ", tree[n]);
  // To exculde the current node, traversal starts from its parent, n/2
  printAncestors(tree, n/2);
  printf("\n");

  printf("%c's descendants: ", tree[n]);
  // To exculde the current node, traversal starts from its children, n*2, n*2+1
  printDescendants(tree, n*2);
  printDescendants(tree, n*2+1);
  printf("\n");
}

void printParent(char tree[], int n) {
  // write your own code
  if (n > 1) printf("%c", tree[n/2]);
}

void printChildren(char tree[], int n) {
  // write your own code
  if (n*2 <= N)  printf("%c ", tree[n*2]);
  if (n*2+1 <= N) printf("%c ", tree[n*2+1]);
}

void printSibling(char tree[], int n) {
  // write your own code
  if (n % 2 == 0 && n+1 <= N) printf("%c", tree[n+1]);
  if (n % 2 == 1) printf("%c", tree[n-1]);
}

void printAncestors(char tree[], int n) {
  // write your own code
  // NOTE: This function prints the current node & all ancestors
  while (n > 0) {
    printf("%c ", tree[n]);
    n /= 2;
  }
}

void printDescendants(char tree[], int n) {
  // write your own code
  // NOTE: This function prints the current node & all descendants
  if (n > N) return;
  printf("%c ", tree[n]);
  printDescendants(tree, n*2);
  printDescendants(tree, n*2+1);
}
