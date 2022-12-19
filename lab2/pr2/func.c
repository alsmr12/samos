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

long double inputLf_positive()
{
    long double x;
    x = inputLf();
    while (x <= 0) {
        printf("Некорректное значение. Повторите ввод:\n");
        x = inputLf();
    }
    return x;
}

long double radical1(long double a, int n, long double i, int *c)
{
    long double y = a;
    long double y1 = 2*a+10;
    while (fabsl(y1 - y) > i) 
	{
        y1 = y;
        y = (1.0 / n) * ((n - 1) * y + (a / powl(y, n-1)));
        *c += 1;
    }
    return y;
}
