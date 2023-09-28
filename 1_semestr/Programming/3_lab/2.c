#include <stdio.h>
#include <math.h>
 
int main() {
    int n;
    
    do {
        printf("n = "); scanf("%d", &n);
    } while (n < -9 || n > 9);
    
    if(n < 0) {
        printf("минус ");
        n = -n;
    }
    
    switch (n) {
        case 0: printf("ноль");     break;
        case 1: printf("один");     break;
        case 2: printf("два");      break;
        case 3: printf("три");      break;
        case 4: printf("четыре");   break;
        case 5: printf("пять");     break;
        case 6: printf("шесть");    break;
        case 7: printf("семь");     break;
        case 8: printf("веосемь");  break;
        case 9: printf("девять");   break;
    }
    return 0;
}