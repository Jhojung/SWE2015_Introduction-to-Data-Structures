// Need to be Fixed as instruction

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    arr[0] = 1;
    if (N > 1) arr[1] = 1;
    for (int i = 2; i < N; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    
    return 0;
}