#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Hype.h"

// Функция для вычисления суммы цифр числа
int DigitSum(int n)
{
    int sum = 0;
    n = abs(n); // Работаем с модулем числа
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Функция для перестановки двух строк в матрице
void SwapRows(int **matrix, int row1, int row2, int cols)
{
    for (int j = 0; j < cols; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

// Функция для вычисления суммы цифр элемента предпоследнего столбца в строке
int SumPrelast(int *row, int cols)
{
    if (cols < 2) // Если столбцов меньше 2, предпоследнего нет
    {
        return 0;
    }

    return DigitSum(row[cols - 2]); // cols-2 - предпоследний столбец
}

// Функция для сортировки строк по возрастанию суммы цифр предпоследнего столбца
void SortMatrix(int **matrix, int rows, int cols)
{
    int *sums = (int*)malloc(rows * sizeof(int));

    // Вычисляем суммы для каждой строки
    for (int i = 0; i < rows; i++)
    {
        sums[i] = SumPrelast(matrix[i], cols);
    }

    // Сортировка пузырьком по возрастанию сумм
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            if (sums[j] > sums[j + 1])
            {
                // Меняем суммы местами
                int temp_sum = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = temp_sum;

                // Меняем строки матрицы местами
                SwapRows(matrix, j, j + 1, cols);
            }
        }
    }

    free(sums);
}

int main()
{
    int M, N;

    // Ввод размеров матрицы
    printf("M=");
    scanf("%d", &M);

    printf("N=");
    scanf("%d", &N);

    if (M <= 0 || N <= 0)
    {
        printf("Error\n");
        return 1;
    }

    if (N < 2)
    {
        printf("Error\n");
        return 1;
    }

    // Ввод матрицы
    printf("\nMatrix input:\n");
    int **matrix = (int**)CreateMatrix(M, N, sizeof(int));

    InputIntMatrix(matrix, M, N);

    // Вывод исходной матрицы
    printf("\nOld matrix:\n");
    PrintIntMatrix(matrix, M, N);

    // Сортировка матрицы
    SortMatrix(matrix, M, N);

    // Вывод отсортированной матрицы
    printf("\nSorted matrix:\n");
    PrintIntMatrix(matrix, M, N);

    // Освобождение памяти
    FreeMatrix((void**)matrix, M);

    return 0;
}
