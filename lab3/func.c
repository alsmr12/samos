#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "input.h"
#include "func.h"

double *array_input(int *len)
{
    int t;
    printf("Введите длину массива: ");
    t = inputInt(len);
    if (t == -1) return NULL;
    double *data = (double *)malloc(*len * sizeof(double));
    if (data == NULL) {
        printf("\nError.");
        return NULL;
    }
    printf("\nВведите массив из %d элементов:\n\n", *len);
    for (int i = 0; i < *len; ++i)
    {
        printf("Элемент %d: ", i+1);
        t = inputlf(data + i);
        if (t == -1) return NULL;
    }
    return data;
}

int array_insert(double **array, int *len, int n, double a)
{
    if (n < 0) {
        return 1;    
    }
    if (n > *len) {
        n = *len;
    }
    *array = (double *)realloc(*array, (*len + 1) * sizeof(double));
    if (*array == NULL) {
        printf("\nError.");
        return 2;
    }
    *len = *len + 1;
    for (int j = *len - 1; j > n; --j)
    {
        (*array)[j] = (*array)[j-1];
    }
    (*array)[n] = a;
    return 0;
}

void *array_print(double *data, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%5.5lf ", *(data + i));
    }
}

int array_delete(double **array, int *len, int n)
{
    if ((n < 0) || (n >= *len) || (len == 0)) {
        return 1;
    }
    for (int i = n; i < *len - 1; ++i)
    {
        (*array)[i] = (*array)[i + 1];
    }
    *len = *len - 1;
    *array = (double *)realloc(*array, *len * sizeof(double));
    return 0;
}

int func(double **array, int *len, int *len1, double **array1)
{
    if (*len == 0) {
        if (*len1 != 0) {
            free(*array1);
            *len1 = 0;
        }
        return 1;
    }
    if (*len1 != 0) free(*array1);
    *array1 = (double *)malloc(*len * sizeof(double));
    if (*array1 == NULL) {
        printf("\nError.");
        return 2;
    }
    double b, y, x;
    *len1 = 0;
    for (int i = 0; i < *len; ++i)
    {
        b = (*array)[i];
        y = modf(b, &x);
        x = x / pow(10, N);
        x = fabsl(x);
        y = fabsl(y);
        if (x < y)
        {
            (*array1)[*len1] = (*array)[i];
            *len1 = *len1 + 1;
            int t = array_delete(array, len, i);
            i = i - 1;
        }
    }
    *array1 = (double *)realloc(*array1, *len1 * sizeof(double));
    return 0;
}
