#include <stdio.h>
#include <locale.h>
#include "arrayio.h"
#include "arrayf.h"

#define SIZE 18

int main()
{
    int B[SIZE];

    setlocale(0, "");

    printf("Массив B (размер %d):\n", SIZE);
    inputArray(B, SIZE);

    printf("Исходный массив: ");
    printArray(B, SIZE);

    swapMaxNegAndFirstPos(B, SIZE);

    printf("После замены: ");
    printArray(B, SIZE);

    return 0;
}