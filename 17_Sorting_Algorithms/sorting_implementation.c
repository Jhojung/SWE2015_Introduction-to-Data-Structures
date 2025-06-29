#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void swap(int *a, int *b);
void SelectSort(int items[], int n);
void BubbleSort(int items[], int n);
void InsertSort(int items[], int n);
void HeapSort(int items[], int n);
void MergeSort(int items[], int n);
void QuickSort(int items[], int n);

int main() {
  int items1[6] = { 10, 21, 5, 8, 1, 12 };
  SelectSort(items1, 6);

  int items2[6] = { 10, 21, 5, 8, 1, 12 };
  BubbleSort(items2, 6);

  int items3[6] = { 10, 21, 5, 8, 1, 12 };
  InsertSort(items3, 6);

  int items4[7] = { 4, 9, 6, 5, 2, 8, 7 };
  HeapSort(items4, 7);

  int items5[8] = { 7, 4, 8, 1, 12, 11, 3, 9 };
  printf("Quick Sort --- \n");
  QuickSort(items5, 8);
  printf("\n");

  int items6[8] = { 7, 12, 8, 3, 1, 6, 5, 4 };
  printf("Merge Sort --- \n");
  MergeSort(items6, 8);
  printf("\n");
  return 0;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void SelectSort(int items[], int n) {
  // Write your own code
  int i, j, minIndex;
  printf("Selection Sort ---\n");
  for (i = 0; i < n; i ++) {
    minIndex = i;
    for (j = i+1; j < n; j ++)
      if (items[minIndex] > items[j])
        minIndex = j;
    swap(&items[minIndex], &items[i]);

    printf("%d-th iteration: ", i);
    for (j = 0; j < n; j ++) printf("%d ", items[j]);
    printf("\n");
  }
  printf("\n");
}

// To exclude last item(already sorted since the size is 1)
// use n-i-1
void BubbleSort(int items[], int n) {
  // Write your own code
  int i, j;
  printf("Bubble Sort ---\n");
  for (i = 0; i < n; i ++) {
    for (j = 0; j < n-i-1; j ++)
      if (items[j] > items[j+1])
        swap(&items[j], &items[j+1]);

    printf("%d-th iteration: ", i);
    for (j = 0; j < n; j ++) printf("%d ", items[j]);
    printf("\n");
  }
  printf("\n");
}

// To function correctly, declare i, j outside of the for-loop
// O(n) when already sorted.
void InsertSort(int items[], int n) {
  // Write your own code
  int i, j, value;
  printf("Insertion Sort ---\n");
  for (i = 0; i < n; i ++) {
    value = items[i];
    for (j = i-1; j >= 0; j --) {
      if (items[j] <= value) break;
      items[j+1] = items[j];
    }
    items[j+1] = value;

    printf("%d-th iteration: ", i);
    for (j = 0; j < n; j ++) printf("%d ", items[j]);
    printf("\n");
  }
  printf("\n");
}

void HeapSort(int items[], int n) {
  // Write your own code
  int i, j, k;

  // 0. Convert index range from (0, ..., n-1) to (1, ..., n)
  //    (1-based indexing is easier to implement heap)
  items --;
  
  // 1. Construct heap
  //    (you can use the item array directly without auxiliary arrays)
  for (i = 1; i <= n; i ++) {
    // TODO
    j = i;
    while (j > 1 && items[j] > items[j/2]) {
      swap(&items[j], &items[j/2]);
      j /= 2;
    }
  }

  // 2. Sort items using deletion operation of heap
  printf("Heap Sort ---\n");
  for (i = n; i >= 1; i --) {
    // (1) Swap the first and the last item
    swap(&items[1], &items[i]);

    // (2) Update heap in the top-down direction
    j = 1;
    while (j*2 <= i-1) {
      if (j*2+1 <= i-1 && items[j*2+1] > items[j*2]) k = j*2+1;
      else k = j*2;
      
      if (items[j] < items[k]) {
        swap(&items[j], &items[k]);
        j = k;
      }
      else break;
    }

    printf("%d-th iteration: ", n-i);
    for (j = 1; j <= n; j ++) printf("%d ", items[j]);
    printf("\n");
  }
  printf("\n");
}

void QuickSort(int items[], int n) {
  // Write your own code
  // 0. Select the first item [0] for the pivot
  // 1. Define left & right pointers
  int l = 1, r = n-1;
  if (n <= 1) return; // Corner Case **IMPORTANT in Quick Sort!
  // 2. Arrange items based on pivot
  while (l <= r) { // Stop when left pointer is placed after right pointer
    // Move the left pointer forward to find a larger item than pivot
    while (l < n && items[l] < items[0]) l ++;
    // Move the right pointer backward to find a smaller item than pivot
    while (r > 0 && items[r] > items[0]) r --;
    // If left pointer is placed before right pointer, swap them
    if (l < r) swap(&items[l], &items[r]);
  }
  // After the loop, items[1,...,r] <= pivot & items[r+1,...,n-1] >= pivot
  // 3. Swap the pivot and the right pointer
  swap(&items[0], &items[r]);
  // Then, you can split the original array into three parts
  // (1) the smaller part: items[0,...,r-1] <= pivot
  // (2) the pivot: items[r]
  // (3) the larger part: items[r+1,...,n-1] >= pivot
  // 4. Sort each part recursively
  QuickSort(items, r);
  QuickSort(&items[r+1], n-r-1);

  for (int i = 0; i < n; i ++) printf("%d ", items[i]);
  printf("\n");
}

void MergeSort(int items[], int n) {
  // Write your own code
  int i, j, k;
  if (n <= 1) return;
  int m = n/2; 
  
  // 0. Split the item array [0,...,n-1] into two parts [0,...,m-1] / [m,...,n-1]
  // 1. Sort each part recursively
  MergeSort(items, m);
  MergeSort(items+m, n-m);
  
  // 2. Combine them
  int *mergedItems = (int *)malloc(sizeof(int)*n);
  j = 0; // j is the index for the first part [0,...,m-1]
  k = m; // k is the index for the second part [m,...,n-1]
  for (i = 0; i < n; i ++) {
    if (j >= m) mergedItems[i] = items[k++];
    else if (k >= n) mergedItems[i] = items[j++];
    else {
      if (items[j] < items[k]) mergedItems[i] = items[j++];
      else mergedItems[i] = items[k++];
    }
  }
  for (i = 0; i < n; i ++) items[i] = mergedItems[i];
  free(mergedItems);

  for (int i = 0; i < n; i ++) printf("%d ", items[i]);
  printf("\n");
}
