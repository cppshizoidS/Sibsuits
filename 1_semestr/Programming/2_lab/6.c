#include <stdio.h>

int Max(int a,int b)
{
    return a>b?a:b;
}

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int a,b,c,d;
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);
    scanf("%i",&d);
    int max = Max(Max(a,b),Max(c,d));
    int min = Min(Min(a,b),Min(c,d));
    printf("Max = %i\nMin = %i\nMax - Min = %i\n",max,min,max-min);
    return 0;
}