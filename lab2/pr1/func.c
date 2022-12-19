#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inputInt()
{
    int x, t;
    char ch = 'a';
    t = scanf("%d%c", &x, &ch);
    while (ch != '\n')
    {
        if (t == -1) {
            printf("\nОШИБКА ВВОДА\n");
            exit(1);
        }
        printf("Некорректное значение. Повторите ввод:\n");
        scanf("%*[^\n]");
        t = scanf("%d%c", &x, &ch);
    }
    return x;
}

int inputNatural()
{
    int x;
    x = inputInt();
    while (x <= 0) {
        printf("Некорректное значение. Повторите ввод:\n");
        x = inputInt();
    }
    return x;
}

long double inputLf()
{
    long double x;
    int t;
    char ch = 'a';
    t = scanf("%Lf%c", &x, &ch);
    while (ch != '\n')
    {
        if (t == -1) {
            printf("\nОШИБКА ВВОДА\n");
            exit(1);
        }
        printf("Некорректное значение. Повторите ввод:\n");
        scanf("%*[^\n]");
        t = scanf("%Lf%c", &x, &ch);
    }
    return x;
}

long double radical(long double a, int n, int i)
{
	long double y = a;
	for (int j = 1; j <= i; ++j)
	{
		y = (1.0 / n) * ((n - 1) * y + (a / powl(y, n-1)));
	}
	return y;
}
