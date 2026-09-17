#include "arrayf.h"

void swapMaxNegAndFirstPos(int arr[], int size)
{
    int maxNegIdx = -1;
    int firstPosIdx = -1;
    int i;

    // Находим первый положительный
    for (i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            firstPosIdx = i;
            break;
        }
    }

    // Находим максимальный отрицательный
    int maxNeg = 0; // Временное значение
    for (i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (maxNegIdx == -1 || arr[i] > maxNeg)
            {
                maxNegIdx = i;
                maxNeg = arr[i];
            }
        }
    }

    // Если оба найдены, меняем местами
    if (maxNegIdx != -1 && firstPosIdx != -1)
    {
        int tmp = arr[maxNegIdx];
        arr[maxNegIdx] = arr[firstPosIdx];
        arr[firstPosIdx] = tmp;
    }
}

void insertZeroInMiddle(int arr[], int size)
{
    if (size < 11) return;
    for (int i = size - 1; i > 10; i--)
    {
        arr[i] = arr[i - 1]; // Сдвигаем на 1 вправо
    }
    arr[10] = 0;
}