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

int *array_remove_dups_two(int *data, int *len)
{
    int *data_new = (int *)malloc(*len * sizeof(int));
    int i, j, c = 1, stop; // c - текущее количество элементов в новом массиве
    data_new[0] = data[0];
    for (i = 1; i <= *len - 1; ++i)
    {
        j = 0; stop = 0;
        while ((j <= c - 1) && (stop == 0))
        {
            if (data_new[j] == data[i])
            {
                stop = 1;
            }
            else {
                if (j == c - 1)
                {
                    data_new[c] = data[i];
                    c = c + 1;
                    stop = 1;
                }
            }
            j = j + 1;
        }
    }
    *len = c;
    return(data_new);
}

int main()
{
    int len;
    int *array = array_input(&len);
    printf("Исходный ряд чисел: ");
    array_print(array, len);

    clock_t start = 0, end = 0;
    start = clock();
    array = array_remove_dups_two(array, &len);
    end = clock();
    double t = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nНовый ряд чисел: ");
    array_print(array, len);

    printf("\nВремя выполниения: %lf секунд\n", t);
    return 0;
}
