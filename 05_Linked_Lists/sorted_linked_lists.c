#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _Node {
  int item;
  struct _Node *next;
} Node;

typedef struct _SortedList {
  Node *head;
} SortedList;

SortedList createSortedList();
void removeSortedList(SortedList *list);

void insert(SortedList *list, int item);
void delete(SortedList *list, int item);
void deleteAll(SortedList *list);
void printItems(SortedList *list);

int main() {
  SortedList list = createSortedList();

  // 1. Insertion
  printf("1. Insertion:\n");
  insert(&list, 2);
  printItems(&list); // INT_MIN -> 2 -> INT_MAX -> NULL

  insert(&list, 5);
  printItems(&list); // INT_MIN -> 2 -> 5 -> INT_MAX -> NULL

  insert(&list, 1);
  printItems(&list); // INT_MIN -> 1 -> 2 -> 5 -> INT_MAX -> NULL

  insert(&list, 3);
  printItems(&list); // INT_MIN -> 1 -> 2 -> 3 -> 5 -> INT_MAX -> NULL

  insert(&list, 4);
  printItems(&list); // INT_MIN -> 1 -> 2 -> 3 -> 4 -> 5 -> INT_MAX -> NULL

  // 2. Deletion
  printf("\n2. Deletion:\n");
  delete(&list, 4);
  printItems(&list); // INT_MIN -> 1 -> 2 -> 3 -> 5 -> INT_MAX -> NULL

  delete(&list, 6);
  printItems(&list); // INT_MIN -> 1 -> 2 -> 3 -> 5 -> INT_MAX -> NULL

  deleteAll(&list);
  printItems(&list); // INT_MIN -> INT_MAX -> NULL

  removeSortedList(&list);
  return 0;
}

SortedList createSortedList() {
  SortedList newList;
  Node *minNode = (Node *)malloc(sizeof(Node));
  Node *maxNode = (Node *)malloc(sizeof(Node));
  minNode->item = INT_MIN;
  minNode->next = maxNode;
  maxNode->item = INT_MAX;
  maxNode->next = NULL;
  newList.head = minNode;
  return newList;
}

void removeSortedList(SortedList *list) {
  deleteAll(list);
  free(list->head->next);
  free(list->head);
}

void insert(SortedList *list, int item) {
  Node *prevNode = list->head;
  Node *nextNode;
  Node *currNode = (Node *)malloc(sizeof(Node));
  currNode->item = item;
  
  while(prevNode != NULL) {
    nextNode = prevNode -> next;
    if(nextNode -> item > item) {
        prevNode -> next = currNode;
        currNode -> next = nextNode;
        return;
    }
    prevNode = nextNode;
  }
}

void delete(SortedList *list, int item) {
  Node *prevNode = list->head;
  Node *nextNode;

  while(prevNode != NULL) {
    nextNode = prevNode -> next;
    if(nextNode -> item == item) {
        prevNode -> next = nextNode -> next;
        free(nextNode);
        return;
    }
    if(nextNode -> item > item) {
        return;
    }
    prevNode = nextNode;
  }
}

void deleteAll(SortedList *list) {
  while (list->head->next->next != NULL) {
    delete(list, list->head->next->item);
  }
}

void printItems(SortedList *list) {
  Node *node = list->head;
  int size = 0;
  while (node != NULL) {
    printf("%d -> ", node->item);
    node = node->next;
    size ++;
  }
  printf("NULL (size: %d)\n", size);
}