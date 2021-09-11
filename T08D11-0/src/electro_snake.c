// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int *arr, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int *arr, int n, int m, int **result_matrix);

/*
    7 8 9
    6 1 2
    5 4 3
*/
void sort_spiral(int *arr, int n, int m, int **result_matrix);

void input(int ***matrix, int *n, int *m, int* f);
void input_matrix(int **matrix, int n, int m, int* f);
void output(int **matrix, int n, int m);
int** dyn_malloc(int* f, int n, int m);
void newArr(int n, int m, int** matrix, int **arr);
void sort(int* array, int len);


int main() {
    int **matrix = NULL, **result = NULL, *array;
    int n, m, f = 1;
    input(&matrix, &n, &m, &f);
    result = dyn_malloc(&f, n, m);
    input_matrix(matrix, n, m, &f);
    printf("\n\n");
    newArr(n, m, matrix, &array);
    sort_vertical(array, n, m, result);
    output(result, n, m);
    printf("\n\n");
    sort_horizontal(array, n, m, result);
    output(result, n, m);
    printf("\n\n");
    sort_spiral(array, n, m, result);
    output(result, n, m);
    return 0;
}

void input_matrix(int **matrix, int n, int m, int* f) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!scanf("%d", &matrix[i][j])) {
                *f = 0;
                break;
            }
        }
        if (*f == 0) break;
    }
}

void input(int ***matrix, int *n, int *m, int* f) {
    if (scanf("%d%d", n, m) != 2 || (*n < 1) || (*m < 1)) *f = 0;
    *matrix = dyn_malloc(f, *n, *m);
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m-1) printf(" ");
        }
            if (i != n-1) printf("\n");
    }
}

int** dyn_malloc(int* f, int n, int m) {
    int** arr_matrix = (int**)malloc(n * sizeof(int*));
    if (!arr_matrix) *f = 0;
    if (*f == 1) {
        for (int i = 0; i < n; i++) {
            arr_matrix[i] = (int*)malloc(m * sizeof(int));
            if (!arr_matrix[i]) *f = 0;
        }
    }
    return arr_matrix;
}

void newArr(int n, int m, int** matrix, int **arr) {
    int *arr_2 = (int*)malloc(n*m * sizeof(int));
    int k = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr_2[++k] = matrix[i][j];
        }
    }
    sort(arr_2, n*m);
    *arr = arr_2;
}

void sort(int* array, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                        int tmp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = tmp;
            }
        }
    }
}

void sort_vertical(int *arr, int n, int m, int **result_matrix) {
    int k = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[j][i] = arr[k++];
            }
        } else {
            for (int j = n-1; j >= 0; j--) {
                result_matrix[j][i] = arr[k++];
            }
        }
    }
}

void sort_horizontal(int *arr, int n, int m, int **result_matrix) {
    int k = -1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = arr[++k];
            }
        } else {
            for (int j = m-1; j >= 0; j--) {
                result_matrix[i][j] = arr[++k];
            }
        }
    }
}

void sort_spiral(int* arr, int n, int m, int** result_matrix) {
    int p = 0;
    int i, j, k, l;
    int centre_x = (m - 1) / 2;
    int centre_y = (n - 1) / 2;
    for (i = centre_x; i < m; i++) {
        result_matrix[centre_y][i] = arr[p++];
    }
        for (j = centre_y; j >= 0; j--) {
            result_matrix[j][i] = arr[p++];
        }
            for (k = i-1; k >= 0; k--) {
                result_matrix[j+1][k] = arr[p++];
            }
                for (l = j + 1; l < n; l++) {
                    result_matrix[l][k+1] = arr[p++];
                }
}
