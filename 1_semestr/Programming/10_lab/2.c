#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    char input[MAX_WORDS * MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int count[MAX_WORDS] = {0};
    int num_words = 0;

    // Запрос ввода строки
    printf("Введите строку, содержащую слова, разделенные запятой: ");
    fgets(input, sizeof(input), stdin);

    // Разбиваем строку на слова и сохраняем их в массиве
    char *word = strtok(input, ",");
    while (word != NULL && num_words < MAX_WORDS) {
        // Проверяем, есть ли это слово уже в массиве
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i], word) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        // Если слово не найдено, добавляем его в массив
        if (!found) {
            words[num_words] = word;
            count[num_words] = 1;
            num_words++;
        }
        word = strtok(NULL, ",");
    }

    // Выводим количество повторений каждого слова
    printf("Количество повторений каждого слова:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}