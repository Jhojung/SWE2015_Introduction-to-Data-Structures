#include <stdio.h>
#define MAX_SIZE 1000000

int N;
int Heights[MAX_SIZE+10];
int MaxArea;
int Stack[MAX_SIZE+1];


int main() 
{
    int i, area;
    
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &Heights[i]);
    
    int Width, curHeight;
    int right_bound = 1;
    int top = 0;  
    
    MaxArea = 0;

    Stack[0] = 0;
    Heights[N + 1] = 0; 
    
    while(right_bound <= N + 1)
    {
        while(top > 0 && Heights[right_bound] < Heights[Stack[top]])
        {
            curHeight = Heights[Stack[top--]];  
            if (top == 0) Width = right_bound - 1;  
            else Width = (right_bound-1) - Stack[top]; 
            
            area = curHeight * Width;  
            MaxArea= area > MaxArea ? area : MaxArea;
        }
        Stack[++top] = right_bound;
        right_bound++;
    }

    printf("%d", MaxArea);
    return 0;
}