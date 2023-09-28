#include <stdio.h>
#include <math.h>

int main(void) {
    //S= tg2 + tg4 +...+ tg(N*2); N = enter from keyboard ( if N=19 S=1)
    float s = 0;
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        s += tan(2*i);
    }
    printf("The sum of the tangents is s = %.2f", round(s));
    return 0;
}