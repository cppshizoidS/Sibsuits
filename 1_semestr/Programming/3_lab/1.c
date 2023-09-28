#include <stdio.h>
int main(){
    int a;
    printf("Enter number of month \n");
    scanf("%d", &a);
    switch(a) {
        case 1: case 2:  case 12: printf("Это зима!\n");  break;
        case 3: case 4:  case 5:  printf("Это весна!\n"); break;
        case 6: case 7:  case 8:  printf("Это лето!\n");  break;
        case 9: case 10: case 11: printf("Это осень!\n"); break;
    }
    switch (a) {
      case 1: case 2: case 3: printf("Первый квартал\n"); break;
      case 4: case 5: case 6: printf("Второй квартал\n"); break;
      case 7: case 8: case 9: printf("Третий квартал\n"); break;
      case 10: case 11: case 12: printf("Четвертый квартал\n"); break;
    }
    //system("pause>>void");
}