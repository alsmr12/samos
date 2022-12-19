#include <stdio.h>
#include <stdlib.h>

int inputInt(int *x)
{
    int t;
    char ch = 'a';
    t = scanf("%d%c", x, &ch);
    while (ch != '\n')
    {
        if (t == -1) {
            printf("\n\nОШИБКА ВВОДА\n\n");
            return -1;
        }
        printf("Некоректное значение. Повторите ввод:\n");
        scanf("%*[^\n]");
        t = scanf("%d%c", x, &ch);
    }
    return 0;
}

int inputlf(double *x)
{
    int t;
    char ch = 'a';
    t = scanf("%lf%c", x, &ch);
    while (ch != '\n')
    {
        if (t == -1) {
            printf("\n\nОШИБКА ВВОДА\n\n");
            return -1;
        }
        printf("Некоректное значение. Повторите ввод:\n");
        scanf("%*[^\n]");
        t = scanf("%lf%c", x, &ch);
    }
    return 0;
}
