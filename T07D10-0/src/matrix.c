// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>
#define STR 100
#define CLM 100

int input_1(int *key, int *strings, int *columns);
int input_2(int** arr_matrix, int strings, int columns);
void output(int** arr_matrix, int strings, int columns);
int menu(int*** arr, int key, int strings, int columns);
int** stat_malloc(int *f, int strings, int columns);
int** dyn_malloc_1(int* f, int strings, int columns);
int** dyn_malloc_2(int* f, int strings, int columns);
int** dyn_malloc_3(int* f, int strings, int columns);

int main() {
    int **data = NULL;
    int key, str, clm;
    int f = 1;
    if (!input_1(&key, &str, &clm)) f = 0;
    if (f == 1) {
        if (!menu(&data, key, str, clm)) f = 0;
        if (f == 1) {
                output(data, str, clm);
                if (key == 2) {
                    for (int i = 0; i < str; i++) {
                        free(data[i]);
                    }
                } else if (key != 1) {
                    free(data);
                }
            }
    }
    if (f == 0) printf("n/a");
    return 0;
}

int input_1(int *key, int *strings, int *columns) {
    int f = 1;
    if (!scanf("%d", key) || (*key < 1) || (*key > 4)) f = 0;
    if (scanf("%d%d", strings, columns) != 2 ||
    (*strings < 1) || (*columns < 1)) f = 0;
    return f;
}

int input_2(int** arr_matrix, int strings, int columns) {
    int f = 1;
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < columns; j++) {
            if (!scanf("%d", &arr_matrix[i][j])) {
                f = 0;
                break;
            }
        }
        if (f == 0) break;
    }
    return f;
}

void output(int** arr_matrix, int strings, int columns) {
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d", arr_matrix[i][j]);
            if (j != columns-1) printf(" ");
        }
            if (i != strings-1) printf("\n");
    }
}

int menu(int*** arr_matrix, int key, int strings, int columns) {
    int f = 1;
    switch (key) {
    case 1:
        *arr_matrix = stat_malloc(&f, strings, columns);
        break;
    case 2:
        *arr_matrix = dyn_malloc_1(&f, strings, columns);
        break;
    case 3:
        *arr_matrix = dyn_malloc_2(&f, strings, columns);
        break;
    case 4:
        *arr_matrix = dyn_malloc_3(&f, strings, columns);
        break;
    default:
        f = 0;
        break;
    }
    if (f == 1) f = input_2(*arr_matrix, strings, columns);
    return f;
}

int** stat_malloc(int *f, int strings, int columns) {
    static int* arr_matrix[STR];
    if (strings > STR || columns > CLM) *f = 0;
    if (*f == 1) {
        int arr[STR][CLM];
        for (int i = 0; i < STR; i++) {
            arr_matrix[i] = (int*)arr[0] + i*CLM;
        }
    }
    return arr_matrix;
}

int** dyn_malloc_1(int* f, int strings, int columns) {
    int** arr_matrix = (int**)malloc(strings * sizeof(int*));
    if (!arr_matrix) *f = 0;
    if (*f == 1) {
        for (int i = 0; i < strings; i++) {
            arr_matrix[i] = (int*)malloc(columns * sizeof(int));
            if (!arr_matrix[i]) *f = 0;
        }
    }
    return arr_matrix;
}

int** dyn_malloc_2(int* f, int strings, int columns) {
    int** arr_matrix = (int**)malloc(strings * sizeof(int*));
    if (!arr_matrix) *f = 0;
    if (*f == 1) {
        int* arr = (int*)malloc(strings * columns * sizeof(int));
        if (!arr) *f = 0;
        if (*f == 1) {
            for (int i = 0; i < strings; i++) {
                arr_matrix[i] = &arr[i * columns];
            }
        }
        free(arr);
    }
    return arr_matrix;
}

int** dyn_malloc_3(int* f, int strings, int columns) {
    int** arr_matrix = (int**)malloc(strings * sizeof(int*) +
    strings * columns * sizeof(int));
    if (!arr_matrix) *f = 0;
    if (*f == 1) {
        int* pointer = (int*)(arr_matrix + strings);
        for (int i = 0; i < strings; i++) {
            arr_matrix[i] = (pointer + columns * i);
        }
    }
    return arr_matrix;
}
