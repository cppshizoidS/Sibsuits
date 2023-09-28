#include <stdio.h>

int main()
{
    int diff[4];
    for (int i = 0; i < 4; i++) scanf("%d", &diff[i]);
    for (int j = 0; j < 4; j++)
        for (int i = j + 1; i < 4; ++i)
            if (diff[j] < diff[i])
            {
                int bar = diff[i];
                diff[i] = diff[j];
                diff[j] = bar;
            }
    printf("And result is -=%d, %d=-\n", diff[0], diff[1]);
    return 0;
}