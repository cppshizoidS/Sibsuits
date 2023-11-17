///<summury>
///Реализовать метод int Function27(int[,] array2d, int n), который возвращает номер
///строки в котором находится наибольшее количество элементов кратных n. n считать с клавиатуры
///Метод не должны использовать ввод/вывод (терминал, файлы и т.д.). Для метода, возвращающих
///число, возвращаемое значение по умолчанию — ноль, для метода, возвращающих массивы — пустой
///массив.
///</summury>

using System;

int[] Function27(int[,] array2d, int n)
{
    int rows = array2d.GetLength(0);
    int cols = array2d.GetLength(1);
    int[] counts = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array2d[i, j] % n == 0)
            {
                counts[i]++;
            }
        }
    }

    int maxCount = counts.Max();
    int[] result = Enumerable
        .Range(0, rows)
        .Where(i => counts[i] == maxCount)
        .Select(i => i + 1)
        .ToArray();

    return result;
}

int[,] array2d = new int[,]
{
    { 2, 6, 9 },
    { 9, 15, 18 },
    { 20, 25, 30 }
};

int n = 3;

int[] result = Function27(array2d, n);

Console.WriteLine("Number line(s) with the largest count of elements divisible by {0}:", n);
Console.WriteLine(string.Join(", ", result));
