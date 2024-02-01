/**
 * @brief Программа для ввода и рекурсивного вывода положительных чисел.
 */

#include <stdio.h>

/**
 * @brief Рекурсивно вводит и выводит положительные числа до ввода 0.
 *
 * Данная функция запрашивает от пользователя ввод целого числа и выводит его, если оно положительное.
 * Затем функция рекурсивно вызывает саму себя до тех пор, пока пользователь не введет 0 для завершения последовательности.
 *
 * @note Функция завершает выполнение, когда пользователь вводит 0.
 */
void printPositiveNumbers() {
    int num; /**< Переменная для хранения введенного числа. */

    // Ввод числа от пользователя
    scanf("%d", &num);

    // Проверка, что введенное число не равно 0
    if (num != 0) {
        // Проверка, что введенное число положительное
        if (num > 0) {
            // Вывод положительного числа
            printf("%d\n", num);
        }

        // Рекурсивный вызов для продолжения ввода и вывода
        printPositiveNumbers();
    }
}

/**
 * @brief Основная функция для выполнения программы.
 *
 * Предлагает пользователю ввести последовательность чисел и вызывает функцию
 * printPositiveNumbers для вывода положительных чисел в последовательности.
 *
 * @return 0 при успешном выполнении программы.
 */
int main() {
    // Приглашение пользователя ввести последовательность чисел
    printf("Введите последовательность чисел (0 для завершения):\n");

    // Вызов функции для ввода и вывода положительных чисел
    printPositiveNumbers();

    // Возвращаем 0 для указания успешного выполнения
    return 0;
}
