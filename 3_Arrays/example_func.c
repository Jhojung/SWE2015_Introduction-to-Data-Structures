#include <stdio.h>

int insert(int *arr, int size, int item, int position) {
    // 1. Push elements from the position index
    for(int i = size-1; i >= position; i--) arr[i+1] = arr[i];

    // 2. Put item into the position index
    arr[position] = item;

    // 3. Increase Size
    size += 1;
    return size;
}

int delete(int *arr, int size, int position) {
    if(size <= 0 || position < 0 || position >= size) return -1; //Corner cases

    // 1. Pull elements util the position index
    for(int i = position; i < size-1; i++) arr[i] = arr[i+1];

    // 2. Decrease Size
    size -= 1;
    return size;
}


// Can use the binary search to improve solution.
int find(int *arr, int size, int val) {
    for(int i=0; i<size; i++) {
        if(arr[i] == val) return i;
    }
    return -1; // Not Found.
}

