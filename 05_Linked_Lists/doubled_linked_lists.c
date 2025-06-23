  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  typedef struct _Node {
    int item;
    struct _Node *prev, *next;
  } Node;

  typedef struct _LinkedList {
    Node *head, *tail;
  } LinkedList;

  LinkedList createLinkedList();
  void removeLinkedList(LinkedList *list);

  int getSize(LinkedList *list);
  Node *getNode(LinkedList *list, int index);
  void insert(LinkedList *list, int item, int index);
  void delete(LinkedList *list, int index);
  void deleteAll(LinkedList *list);
  void printItems(LinkedList *list);

  int main() {
    LinkedList list = createLinkedList();

    // 1. Insertion
    printf("1. Insertion:\n");
    insert(&list, 1, 0);
    printItems(&list); // 1 -> NULL

    insert(&list, 2, 1);
    printItems(&list); // 1 -> 2 -> NULL

    insert(&list, 3, 1);
    printItems(&list); // 1 -> 3 -> 2 -> NULL

    insert(&list, 4, 1);
    printItems(&list); // 1 -> 4 -> 3 -> 2 -> NULL

    insert(&list, 4, 6); // Error: index is out of range
    insert(&list, 4, -1); // Error: index is out of range

    // 2. Deletion
    printf("\n2. Deletion:\n");
    delete(&list, 0);
    printItems(&list); // 4 -> 3 -> 2 -> NULL

    delete(&list, 1);
    printItems(&list); // 4 -> 2 -> NULL

    delete(&list, -1); // Error: index is out of range
    delete(&list, 2); // Error: index is out of range

    deleteAll(&list);
    printItems(&list); // NULL

    removeLinkedList(&list);
    return 0;
  }

  LinkedList createLinkedList() {
    LinkedList newList;
    newList.head = (Node *)malloc(sizeof(Node));
    newList.tail = (Node *)malloc(sizeof(Node));
    newList.head->next = newList.tail;
    newList.head->prev = NULL;
    newList.tail->next = NULL;
    newList.tail->prev = newList.head;
    return newList;
  }

  void removeLinkedList(LinkedList *list) {
    deleteAll(list);
    free(list->head);
    free(list->tail);
  }

  int getSize(LinkedList *list) {
    // Starting from the head, count non-dummy nodes
    Node *node = list->head->next;
    int size = 0;

    while (node != list -> tail) {
      size++;
      node = node->next;
    }

    return size;
  }

  Node* getNode(LinkedList *list, int index) {
    // starting from the head, find the index-th element (not including dummy nodes)
    // return head if index < 0
    // return tail if index >= getSize(list)
    Node *node = list->head;

    while(index >=0 && node != list->tail) {
      node = node -> next;
      index--;
    }

    return node;
  }

  void insert(LinkedList *list, int item, int index) {
    Node *prevNode = getNode(list, index-1);
    if (index < 0 || prevNode == list->tail) {
      printf("Error: index is out of range\n");
      return;
    }
    Node *nextNode = prevNode->next;
    Node *currNode = (Node *)malloc(sizeof(Node));
    currNode->item = item;
    currNode -> item = item;
    prevNode -> next = currNode;
    nextNode -> prev = currNode;
    currNode -> prev = prevNode;
    currNode -> next = nextNode;
    

  }

  void delete(LinkedList *list, int index) {
    Node *currNode = getNode(list, index);
    if (currNode == list->head || currNode == list->tail) {
      printf("Error: index is out of range\n");
      return;
    }
    Node *prevNode = currNode -> prev;
    Node *nextNode = currNode -> next;
    prevNode -> next = nextNode;
    nextNode -> prev = prevNode;
    free(currNode);
  }

  void deleteAll(LinkedList *list) {
    while (list->head->next != list->tail) {
      delete(list, 0);
    }
  }

  void printItems(LinkedList *list) {
    Node *node = list->head->next;
    int size = 0;
    while (node != list->tail) {
      printf("%d -> ", node->item);
      node = node->next;
      size ++;
    }
    printf("NULL (size: %d)\n", size);
  }