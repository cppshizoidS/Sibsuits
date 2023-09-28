#include <stdio.h>

const unsigned char M[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    unsigned char day, month;
    unsigned int year, from_begin_of_year;
    unsigned char i;
    
    printf("День:  ");
    scanf("%hhu", &day);
    printf("Месяц: ");
    scanf("%hhu", &month);
    printf("Год:   ");
    scanf("%u", &year);
    
    from_begin_of_year = 0;
    for (i = 0; i < month-1; i++) {
        from_begin_of_year += M[i];
    }
    from_begin_of_year += day;
    
    if (month > 2) {
        if (year % 4 == 0) {
            if ((year % 100 == 0) && (year % 400 != 0)) {
                from_begin_of_year = from_begin_of_year;
            } else {
                from_begin_of_year += 1;
            }
        }
    }
    
    printf("Номер дня с начала года: %u\n", from_begin_of_year);
    
    return 0;
}