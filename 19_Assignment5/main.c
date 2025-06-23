#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 500000

typedef struct _Task {
    int id;
    int R, C, P;
} Task;

typedef struct _Heap {
    Task items[MAX_SIZE + 1];
    int size;
} Heap;

void swap(Task* a, Task* b);
void insert(Heap* heap, Task task);
void delete(Heap* heap);

int N;
Task Tasks[MAX_SIZE + 1];
Heap TaskBuffer;

int main() {
    TaskBuffer.size = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        Tasks[i].id = i;
        scanf("%d %d %d", &Tasks[i].R, &Tasks[i].C, &Tasks[i].P);
    }

    int time = 1, currIDX = 1, completionTask = 0;

    while (completionTask < N) {
        while (1) {
            if (Tasks[currIDX].R <= time && currIDX <= N) {
                insert(&TaskBuffer, Tasks[currIDX]);
                currIDX++;
            }
            else break;
        }

        if (TaskBuffer.size > 0) {
            printf("%d\n", TaskBuffer.items[1].id);
            time += TaskBuffer.items[1].C;
            delete(&TaskBuffer);
            completionTask++;
        }
    }

    return 0;
}

void swap(Task* a, Task* b) {
    Task tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert(Heap* heap, Task task) {
    if (heap->size == MAX_SIZE - 1) {
        perror("heap size maxed out");
        return;
    }

    if (heap == NULL) {
        perror("insertion failed");
        return;
    }

    heap->size++;
    heap->items[heap->size] = task;
    int i = heap->size;
    while (i > 1 && heap->items[i / 2].P < heap->items[i].P) {
        swap(&heap->items[i / 2], &heap->items[i]);
        i /= 2;
    }
}

void delete(Heap* heap) {
    if (heap == NULL) {
        perror("deletion failed");
        return;
    }

    swap(&heap->items[1], &heap->items[heap->size]);
    heap->size--;
    int i = 1, child;
    while (i * 2 <= heap->size) {
        if (i * 2 + 1 > heap->size || heap->items[i * 2].P > heap->items[i * 2 + 1].P) child = i * 2;
        else child = i * 2 + 1;
        if (heap->items[i].P >= heap->items[child].P) break;
        swap(&heap->items[i], &heap->items[child]);
        i = child;
    }
}