#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 50

int main() {
    char input[MAX_NAMES * MAX_NAME_LENGTH];
    char *names[MAX_NAMES];
    int num_names = 0;

    // Запрос ввода списка фамилий
    printf("Введите список фамилий, разделенных запятой: ");
    fgets(input, sizeof(input), stdin);

    // Разбиваем строку на фамилии и сохраняем их в массиве
    char *name = strtok(input, ",");
    while (name != NULL && num_names < MAX_NAMES) {
        names[num_names] = name;
        num_names++;
        name = strtok(NULL, ",");
    }

    // Сортируем фамилии по алфавиту
    for (int i = 0; i < num_names - 1; i++) {
        for (int j = i + 1; j < num_names; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    // Выводим отсортированный список фамилий
    printf("Отсортированный список фамилий:\n");
    for (int i = 0; i < num_names; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}