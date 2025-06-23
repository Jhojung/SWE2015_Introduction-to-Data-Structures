#include <stdio.h>
#include <limits.h>

// Array operations:
int getSum(int *arr, int n);
int getMin(int *arr, int n);
int getMax(int *arr, int n);

int main() {
  int i;
  int N, items[100];

  // Step 1: read N numbers from user input
  scanf("%d", &N);
  for (i = 0; i < N; i ++) scanf("%d", &items[i]);

  // Step 2: print array statistics (sum/min/max)
  printf("%d\n", getSum(items, N));
  printf("%d\n", getMin(items, N));
  printf("%d\n", getMax(items, N));
  return 0;
}

int getSum(int *arr, int n) {
  int sum;
  for(int i = 0; i<n; i++) sum += arr[i];
  return sum;
}

int getMin(int *arr, int n) {
  int min = arr[0];
  for(int i=1; i<n; i++) {
    if(arr[i] < min) min = arr[i];
  }
  return min;
}

int getMax(int *arr, int n) {
  int max = arr[0];
  for(int i=1; i<n; i++) {
    if(arr[i] > max) max = arr[i];
  }
  return max;
}
