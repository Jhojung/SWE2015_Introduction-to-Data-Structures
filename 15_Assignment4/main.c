#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  int key, height;
  struct _Node *left, *right;
  int count;
} Node;

Node* createLeaf(int key);
void removeTree(Node *root);
int getHeight(Node *node);
void updateNode(Node *node);

Node* insertNode(int key, Node *root);
Node* deleteNode(int key, Node *root);
int findLargest(int k, Node *root);
int findSmallest(int k, Node *root);
int countNodes(Node *root);

Node* rotate(Node *root);
Node* LLRotation(Node *root);
Node* RRRotation(Node *root);
Node* LRRotation(Node *root);
Node* RLRotation(Node *root);

int checkRange(int k, Node *root);

int main() {
  Node* root = NULL;
  int N, query;
  char operation[10];

  scanf("%d", &N);
  for (int i = 0; i < N; i ++) {
    scanf("%s%d", operation, &query);
    if (strcmp(operation, "insert") == 0) {
      root = insertNode(query, root);
      printf("%d\n", countNodes(root));
    }
    else if (strcmp(operation, "delete") == 0) {
      root = deleteNode(query, root);
      printf("%d\n", countNodes(root));
    }
    else if (strcmp(operation, "largest") == 0) {
      if(checkRange(query, root)) printf("%d\n", findLargest(query, root));
      else printf("out of range\n");
    }
    else if (strcmp(operation, "smallest") == 0) {
      if(checkRange(query, root)) printf("%d\n", findSmallest(query, root));
      else printf("out of range\n");
    }
    else {
      // not reachable
    }
  }
  removeTree(root);
  return 0;
}

Node* createLeaf(int key) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->key = key;
  node->height = 1;
  node->count = 1;
  node->left = node->right = NULL;
  return node;
}

void removeTree(Node *root) {
  if (root == NULL) return;
  removeTree(root->left);
  removeTree(root->right);
  free(root);
}

int getHeight(Node *node) {
    if(node == NULL) return 0;
    return node->height;
}

void updateNode(Node *node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;

    int leftCount = (node->left != NULL) ? node->left->count : 0;
    int rightCount = (node->right != NULL) ? node->right->count : 0;
    node->count = 1 + leftCount + rightCount;
}

int countNodes(Node *root) {
    if(root == NULL) return 0;
    else return root->count;
}

int findLargest(int k, Node *root) {
    Node *current = root;
    while(current != NULL) {
        int rightCount = countNodes(current->right);

        if(k <= rightCount) current = current -> right;
        else if(k == rightCount + 1) return current -> key;
        else if(k > rightCount + 1) {
            k = k - (rightCount + 1);
            current = current -> left;
        }
    }
}

int findSmallest(int k, Node *root) {
    Node *current = root;
    while(current != NULL) {
        int leftCount = countNodes(current->left);

        if(k <= leftCount) current = current -> left;
        else if(k == leftCount + 1) return current -> key;
        else if(k > leftCount + 1) {
            k = k - (leftCount + 1);
            current = current -> right;
        }
    }
}

Node* insertNode(int key, Node *root) {
  if (root == NULL) return createLeaf(key);
  if (key == root->key) return root;
  else if (key < root->key) root->left = insertNode(key, root->left);
  else root->right = insertNode(key, root->right);

  updateNode(root);
  return rotate(root);
}

Node* deleteNode(int key, Node *root) {
  if (root == NULL) return NULL;
  if (key < root->key) root->left = deleteNode(key, root->left);
  else if (key > root->key) root->right = deleteNode(key, root->right);
  else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    else if (root->left == NULL || root->right == NULL) {
      Node *child = root->left != NULL ? root->left : root->right;
      free(root);
      root = child;
    }
    else {
      Node *successor = root->right;
      while (successor->left != NULL)
        successor = successor->left;
      root->key = successor->key;
      root->right = deleteNode(successor->key, root->right);
    }
  }

  updateNode(root);
  return rotate(root);
}

Node* rotate(Node *root) {
  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);
  int rootBalance = leftHeight - rightHeight;
  if (rootBalance == 2) {
    int leftBalance = getHeight(root->left->left) - getHeight(root->left->right);
    if (leftBalance >= 0) root = LLRotation(root);
    else if (leftBalance == -1) root = LRRotation(root);
    else printf("Error!\n");
  }
  else if (rootBalance == -2) {
    int rightBalance = getHeight(root->right->left) - getHeight(root->right->right);
    if (rightBalance <= 0) root = RRRotation(root);
    else if (rightBalance == 1) root = RLRotation(root);
    else printf("Error!\n");
  }
  return root;
}

Node* LLRotation(Node *root) {
  Node *left = root->left;
  root->left = left->right;
  left->right = root;
  updateNode(root);
  updateNode(left);
  return left;
}

Node* RRRotation(Node *root) {
  Node *right = root->right;
  root->right = right->left;
  right->left = root;
  updateNode(root);
  updateNode(right);
  return right;
}

Node* LRRotation(Node *root) {
  Node *left = root->left;
  Node *leftright = left->right;
  root->left = leftright->right;
  left->right = leftright->left;
  leftright->left = left;
  leftright->right = root;
  updateNode(left);
  updateNode(root);
  updateNode(leftright);
  return leftright;
}

Node* RLRotation(Node *root) {
  Node *right = root->right;
  Node *rightleft = right->left;
  root->right = rightleft->left;
  right->left = rightleft->right;
  rightleft->left = root;
  rightleft->right = right;
  updateNode(root);
  updateNode(right);
  updateNode(rightleft);
  return rightleft;
}

int checkRange(int k, Node *root) {
    if(root == NULL || k <= 0 || k > countNodes(root)) return 0;
    else return 1;
}