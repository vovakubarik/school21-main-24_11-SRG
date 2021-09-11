// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>

int input(int **buffer, int *length);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n = 10;
    int *data;
    int f = 1;
    if (!input(&data, &n)) f = 0;
    if (f == 1) {
        sort(data, n);
        output(data, n);
    }
    free(data);
    return 0;
}

int input(int **buffer, int *length) {
    int f = 1;
    if (scanf("%d", length) != 1 || *length < 0) {
        printf("n/a");
        f = 0;
    } else {
        *buffer = (int*)malloc(*length * sizeof(int));
        if (!buffer) {
            printf("n/a");
        } else {
        for (int *p = *buffer; p - *buffer < *length; p++) {
        if (scanf("%d", p) != 1 && f!= 0) {
            printf("n/a");
            f = 0;
            }
        }
    }
    }
    return f;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
}

void sort(int *a, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
            int c = a[j];
            a[j] = a[j+1];
            a[j+1] = c;
            }
        }
    }
}
