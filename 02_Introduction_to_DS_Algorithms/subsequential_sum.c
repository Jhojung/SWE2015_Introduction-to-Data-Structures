#include <stdio.h>

int main() {
    int arr[5] = {2,1,4,3,0},a,b;
    scanf("%d %d", &a, &b);

    int sum = 0;
    for(int i=a; i<=b; i++) {
        sum+= arr[i];
    }

    printf("%d", sum);
    return 0;
}