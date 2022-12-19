#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "input.h"

int main()
{
    int c = 1;
    int len = 0, len1 = 0, n, t;
    double a;
    double *array = NULL, *array1 = NULL;
    while (c != 0)
    {
        printf("\nМеню:\n");
        printf("1. Инициализация массива (заполнение массива в цикле)\n");
        printf("2. Вставка нового элемента в массив по индексу\n");
        printf("3. Удаление элемента массива по индексу\n");
        printf("4. Функция\n");
        printf("5. Вывод текущего состояния массива\n");
        printf("6. Вывод массива, полученного после выполнения 4-ой команды\n");
        printf("0. Выход");
        printf("\n\nКоманда (0 - 6): ");
        t = inputInt(&c);
        if (t == -1) {
            if (len != 0) free(array);
            if (len1 != 0) free(array1);
            exit(1);
        }
        switch(c) {
        case 0: break;
        case 1:
            printf("\nИнициализация массива (заполнение массива в цикле)\n");
            printf("Вводите числа в формате XXXXX.YYYYY\n\n");
            array = array_input(&len);
            if (array == NULL) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            printf("\nМассив запонен\n");
            break; 
        case 2:
            printf("\nВставка нового элемента в массив по индексу\n");
            printf("\nВведите индекс элемента (>= 0): ");
            t = inputInt(&n);
            if (t == -1) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            printf("Введите значение элемента: ");
            t = inputlf(&a);
            if (t == -1) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            t = array_insert(&array, &len, n, a);
            if (t == 0) {
                printf("\nЭлемент добавлен\n");
            }
            if (t == 1) {
                printf("\nОшибка. Элемент не добавлен\n");
            }
            if (t == 2) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            break;
        case 3:
            printf("\nУдаление элемента массива по индексу");
            printf("\nВведите индекс элемента(>= 0): ");
            t = inputInt(&n);
            if (t == -1) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            t = array_delete(&array, &len, n);
            if (t == 0) {
                printf("\nЭлемент удалён\n");
            }
            if (t == 1) {
                printf("\nОшибка. Элемент не удалён\n");
            }
            if (t == 2) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            break; 
        case 4: 
            printf("\nФормирование нового массива из элементов\n");
            t = func(&array, &len, &len1, &array1);
            if (t == 0) {
                printf("\nНовый массив сформирован\n");
            }    
            if (t == 1) {
                printf("\nНеудача. Не из чего формировать массив\n");
            }
            if (t == 2) {
                if (len != 0) free(array);
                if (len1 != 0) free(array1);
                exit(1);
            }
            break;
        case 5:
            printf("\nВывод текущего состояния массива\n");
            array_print(array, len);
            break;
        case 6:
            printf("\nПолученный массив\n");
            array_print(array1, len1);
            break;
        default: printf("\nКоманды с таким номером не существует\n");
        }
    }
    if (len != 0) free(array);
    if (len1 != 0) free(array1);
    printf("\nПрограмма завершена\n\n");
    return 0;
}
