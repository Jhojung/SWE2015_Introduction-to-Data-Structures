#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct _Node {
  int item;
  struct _Node *next;
} Node;

typedef struct _Queue {
  Node *front, *rear;
} Queue;

Queue createQueue();
void removeQueue(Queue *queue);

bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
int peek(Queue *queue);
void printItems(Queue *queue);

int main() {
  Queue queue;

  // Create a queue
  queue = createQueue();

  enqueue(&queue, 1);
  enqueue(&queue, 3);
  enqueue(&queue, 2);
  printItems(&queue);

  dequeue(&queue);
  enqueue(&queue, 4);
  printItems(&queue);

  printf("Front: %d\n", peek(&queue));
  enqueue(&queue, 10);
  printItems(&queue);

  // Remove the queue
  removeQueue(&queue);
  return 0;
}

Queue createQueue() {
  // Write your own code
  Queue newQueue;
  Node *dummy = (Node *)malloc(sizeof(Node));
  newQueue.front = dummy;
  newQueue.rear = dummy;
  dummy->next = NULL;
  return newQueue;
}

void removeQueue(Queue *queue) {
  // Write your own code
  while (!isEmpty(queue))
    dequeue(queue);
  free(queue->front);
}

bool isEmpty(Queue *queue) {
  // Write your own code
  return queue->front == queue->rear;
}

bool isFull(Queue *queue) {
  // Write your own code
  return false;
}

void enqueue(Queue *queue, int item) {
  // Write your own code
  if (isFull(queue)) {
    printf("Error: queue is already full\n");
    return;
  }
  Node *dummy = (Node *)malloc(sizeof(Node));
  dummy->next = NULL;

  queue->rear->item = item;
  queue->rear->next = dummy;
  queue->rear = dummy;
}

int dequeue(Queue *queue) {
  // Write your own code
  if (isEmpty(queue)) {
    printf("Error: queue is empty\n");
    return 0;
  }
  Node *orgFront = queue->front;
  int item = orgFront->item;
  queue->front = orgFront->next;
  free(orgFront);
  return item;
}

int peek(Queue *queue) {
  // Write your own code
  if (isEmpty(queue)) {
    printf("Error: queue is empty\n");
    return 0;
  }
  return queue->front->item;
}

void printItems(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue: empty\n");
    return;
  }

  printf("Queue: ");
  for (Node *node = queue->front; node != queue->rear; node = node->next) {
    printf("%d ", node->item);
  }
  printf("\n");
}
