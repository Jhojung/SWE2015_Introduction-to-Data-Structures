#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_SIZE 10  // Maximum size of our array structure

typedef struct _IntArray { // Array structure for integer values
  int items[MAX_SIZE];
  int size;
} IntArray;

// IntArray operations:
void printItems(IntArray *arr);
bool isFull(IntArray *arr);
bool isEmpty(IntArray *arr);
void insert(IntArray *arr, int value, int index);
void delete(IntArray *arr, int index);
int find(IntArray *arr, int value);

int main() {
  IntArray arr = { { 2, 1, 3, 8, 6, 7, 5, 10 }, 8 };
  
  printItems(&arr);
  
  insert(&arr, 9, 4);
  printItems(&arr);

  insert(&arr, 4, 7);
  printItems(&arr);

  insert(&arr, 0, 9);
  printItems(&arr);

  delete(&arr, 1);
  printItems(&arr);

  delete(&arr, find(&arr, 10));
  printItems(&arr);
  return 0;
}

void printItems(IntArray *arr) {
  for (int i = 0; i < arr->size; i ++)
    printf("%d ", arr->items[i]);
  printf("\n");
}

bool isFull(IntArray *arr) {
  if(arr->size >= MAX_SIZE) return 1;
  return 0;
}

bool isEmpty(IntArray *arr) {
  if(arr->size == 0) return 1;
  return 0;
}

void insert(IntArray *arr, int value, int index) {
  if (isFull(arr)) {
    printf("Error: you cannot insert new item into full array\n");
    return;
  }
  if (index < 0 || index > arr->size) {
    printf("Error: index is invalid\n");
    return;
  }
  for(int i = arr->size-1; i >= index; i--) arr->items[i+1] = arr->items[i];
  arr->items[index] = value;
  arr->size += 1;
}

void delete(IntArray *arr, int index) {
  if (isEmpty(arr)) {
    printf("Error: you cannot delete an item from empty array\n");
    return;
  }
  if (index < 0 || index >= arr->size) {
    printf("Error: index is invalid\n");
    return;
  }
  for(int i = index; i < arr->size-1; i++) arr->items[i] = arr->items[i+1];
  arr->size -= 1;
}

int find(IntArray *arr, int value) {
    for(int i=0; i<arr->size; i++) {
        if(arr->items[i] == value) return i;
    }
    return -1; // Not Found.
}
