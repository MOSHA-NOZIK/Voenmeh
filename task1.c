#include <stdio.h>
#include <locale.h>

int main()
{
    int A, B;
    int sum = 0;
    int i;

    setlocale(0, "");

    printf("Введите A и B: ");
    scanf("%d %d", &A, &B);

    if (A > B)
    {
        printf("Ошибка: A > B");
        return 0;
    }

    for (i = A; i <= B; i++)
    {
        if (i > 0 && i % 4 == 0)
        {
            sum += i;
        }
    }

    printf("Сумма положительных чисел, кратных 4: %d\n", sum);
    return 0;
}
