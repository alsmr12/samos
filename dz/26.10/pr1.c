#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *array_input(int *len)
{
    printf("Введите длину ряда целых чисел: ");
    scanf("%d", len);
    int *data = (int *)malloc(*len * sizeof(int));
    if (!data){
        printf("Error.");
        return NULL;
    }
    printf("Введите ряд целых чисел из %d элементов:\n", *len);
    for (int i = 0; i < *len; ++i)
    {
        scanf("%d", data + i);
    }
    return data;
}

void *array_print(int *data, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", *(data + i));
    }
}

void array_remove_dups(int *data, int *len)
{
    int i, j, k;
    for (i = 0; i < *len -1; ++i)
    {
        for (j = i + 1; j < *len; ++j)
        {
            if (data[i] == data[j])
            {
                for (k = j; k < *len - 1; ++k)
                {
                    data[k] = data[k + 1];
                }
                --*len;
                --j;
            }
        }
    }
}

int main()
{
    int len;
    int *array = array_input(&len);
    printf("Исходный ряд чисел: ");
    array_print(array, len);

    clock_t start = 0, end = 0;
    start = clock();
    array_remove_dups(array, &len);
    end = clock();
    double t = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nНовый ряд чисел: ");
    array_print(array, len);

    printf("\nВремя выполниения: %lf секунд\n", t);
    return 0;
}
