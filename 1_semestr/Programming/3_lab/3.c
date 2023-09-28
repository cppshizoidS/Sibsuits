#include <locale.h>
#include <stdio.h>
int main()
    {
        int y;
        printf("Введите год от 1996 до 2008: ");
        scanf("%d",&y);
        if ((y<1996)|(y>2008))
            printf("Вы ввели неверное значение!");
        else
            switch(y)
                {
            case 1996: printf("Год крысы!"); break;
            case 1997: printf("Год коровы!"); break;
            case 1998: printf("Год тигра!"); break;
            case 1999: printf("Год зайца!"); break;
            case 2000: printf("Год дракона!"); break;
            case 2001: printf("Год змеи!"); break;
            case 2002: printf("Год лошади!"); break;
            case 2003: printf("Год овцы!"); break;
            case 2004: printf("Год обезьяны!"); break;
            case 2005: printf("Год петуха!"); break;
            case 2006: printf("Год собаки!"); break;
            case 2007: printf("Год свиньи!"); break;
            }
}