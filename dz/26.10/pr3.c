#include <stdio.h>
#include <stdlib.h>

void *array_print(int *data, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", data[i]);
    }
}

int *func(int *array, int *len, int n, int a)
{
    if (n > *len - 1)
    {
    int *array1 = (int *)malloc((n + 1) * sizeof(int));
    for (int k = 0; k < *len; ++k)
    {
        array1[k] = array[k];
    }
    free(array);
    array = array1;
    for (int i = *len; i <= n; ++i)
    {
        array[i] = 0;
    }
    *len = n + 1;
    }
    if (array[n] == 0 )
    {
        array[n] = a;
    }
    else
    {
        int *array2 = (int *)malloc((*len+1) * sizeof(int));
        for (int k = 0; k < *len; ++k)
        {
            array2[k] = array[k];
        }
        free(array);
        array = array2;
        *len = *len + 1;
        for (int j = *len - 1; j > n; --j)
        {
            array[j] = array[j-1];
        }
        array[n] = a;
    }
    return array;
}

int main()
{
    printf("Вводите по 2 числа: первое - номер элемента, второе - его значение\n");
    printf("(0 на второй позиции - признак конца ввода)\n");
    int n, a = 1, len = 1;
    int *array = (int*)malloc(sizeof(int));
    *array = 0;
    while (a != 0)
    {
        scanf("%d%d", &n, &a);
        if (a != 0) {
            array = func(array, &len, n, a);
        }
    }
    printf("\nПолученный массив: ");
    array_print(array, len);
    printf("\n\n");
}
