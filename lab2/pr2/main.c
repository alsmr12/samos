#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "func.h"

long double main()
{
    long double a, i; int n, t;
    printf("Введите число а, корень n-ой степени из которого Вы хотите посчитать:\n");
    a = inputLf();
    printf("Введите число n - натуральный степенной показатель корня из %Lg:\n",a);
    n = inputNatural();
    if ((a < 0) && (n % 2 == 0)) {
        printf("\nОшибка. Нельзя посчитать корень чётной степени из отрицательного числа\n");
        exit(1);
    }
    printf("Введите число (>0) i - точность, с которой необходимо вычислить корень %d-ой степени из %Lg:\n",n,a);
    i = inputLf_positive();
    int c = 0;
    long double x = radical1(a, n, i, &c);
    printf("\nКорень %d-ой степени из %Lg: %.19Lf\n", n, a, x);
    printf("Количество итераций: %d\n", c);
    long double res = powl(fabsl(a), 1.0 / n);
    if (a < 0) {
        res = - res;
    }
    printf("\nЗначение полученное с использованием библиотечной функции: %.19Lf\n", res);
    return 0;
}
