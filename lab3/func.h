#ifndef func_H
#define func_H

#define N 5

int array_delete(double **array, int *len, int n);
int array_insert(double **array, int *len, int n, double a);
void *array_print(double *data, int len);
double *array_input(int *len);
int func(double **array, int *len, int *len1, double **array1);

#endif
