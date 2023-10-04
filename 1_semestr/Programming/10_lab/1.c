#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    char input[MAX_WORDS * MAX_WORD_LENGTH];
    char prefix[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int count = 0;

    // Запрос ввода строки и приставки
    printf("Введите строку, содержащую слова, разделенные запятой: ");
    fgets(input, sizeof(input), stdin);
    printf("Введите приставку: ");
    scanf("%s", prefix);

    // Разбиваем строку на слова и сохраняем их в массиве
    char *word = strtok(input, ",");
    while (word != NULL && count < MAX_WORDS) {
        words[count++] = word;
        word = strtok(NULL, ",");
    }

    // Ищем слова, начинающиеся с заданной приставки и выводим их
    printf("Слова, начинающиеся с приставки \"%s\":\n", prefix);
    for (int i = 0; i < count; i++) {
        if (strncmp(words[i], prefix, strlen(prefix)) == 0) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}