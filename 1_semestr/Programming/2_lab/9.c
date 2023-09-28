#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int arr[3];
    printf("Input 3 numbers: ");
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    int max = arr[0], min = arr[0];
    for(int i = 1; i < 3; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        else if(arr[i] < min)
            min = arr[i];
    }
    for(int i = 0; i < 3; i++)
    {
        if(arr[i] == max)
            arr[i] = min;
        else if(arr[i] == min)
            arr[i] = max;
    }
    for(int i = 0; i < 3; i++)
        printf("%d ", arr[i]);
    
    return 0;
}