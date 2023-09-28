#include <stdio.h>

int main(){
    int age;

    printf("Введите ваш возраст: ");
    scanf("%d", &age);

    if (age > 0 && age <=6) {
        printf("Вас пустят только на мультфильм");
    }
    else if (age > 6 && age <= 16) {
        printf("Вас пустят на все, кроме  18+");
    } else if (age >= 18) {
        printf("18+");
    }
    else {
        printf("Error");
    }
    return 0;
}