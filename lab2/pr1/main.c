#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "func.h"

long double main()
{
	long double a; int n, i;
	printf("Введите число а, корень n-ой степени из которого Вы хотите посчитать:\n");
    a = inputLf();
	printf("Введите число n - натуральный степенной показатель корня из %Lg:\n",a);
    n = inputNatural();
    if ((a < 0) && (n % 2 == 0)) {
        printf("\nОшибка. Нельзя посчитать корень чётной степени из отрицательного числа\n");
        exit(1);
    }
	printf("Введите натуральное число i - количество итераций для вычисления корня %d-ой степени из %Lg по итерационной формуле:\n",n,a);
	i = inputNatural();
	long double x = radical(a, n, i);
	printf("\nКорень %d-ой степени из %Lg: %.19Lf\n", n, a, x);
    long double res = powl(fabsl(a), 1.0 / n);
    if (a < 0) {
        res = - res;
    }
    printf("\nЗначение корня, полученное с помощью библиотечной функции: %.19Lf\n", res);
	return 0;
}
