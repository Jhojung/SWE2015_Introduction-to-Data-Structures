#include <stdio.h>

#define MAX_SIZE 1000

int N, M;
int A[MAX_SIZE][MAX_SIZE];
int S[MAX_SIZE][MAX_SIZE];

int main() {
    int i, j;
    int r0, r1, c0, c1;

    scanf("%d", &N);


    // Prefix Sum
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            S[i][j] = A[i][j];
            if (i > 0) S[i][j] += S[i-1][j];
            if (j > 0) S[i][j] += S[i][j-1];
            if (i > 0 && j > 0) S[i][j] -= S[i-1][j-1];
        }
    }

    scanf("%d", &M);

    for (i = 0; i < M; i++) {
        scanf("%d %d %d %d", &r0, &r1, &c0, &c1);
        
        int sum = S[r1-1][c1-1];
        if (r0 > 0) sum -= S[r0-1][c1-1];
        if (c0 > 0) sum -= S[r1-1][c0-1];
        if (r0 > 0 && c0 > 0) sum += S[r0-1][c0-1];

        printf("%d\n", sum);
    }

    return 0;
}
