// Copyright 2021 gsherley
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
void cycle_shift(int *a, int n, int c);

int main() {
    int n, data[NMAX], c;
    int f = 1;
    if (!input(data, &n, &c)) f = 0;
    if (f == 1) {
        cycle_shift(data, n, c);
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n, int *c) {
    int f = 1;
    if (scanf("%d", n) != 1 || *n > NMAX || *n < 1) {
        printf("n/a");
        f = 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1 && f!= 0) {
            printf("n/a");
            f = 0;
            }
        }
        if (scanf("%d", c) != 1 && f != 0) {
            printf("n/a");
            f = 0;
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

void cycle_shift(int *a, int n, int c) {
    if (c > 0) {
        for (int i = c-1; i > -1; i--) {
            for (int j = 0; j < n-c; j++) {
                int tmp = a[i+j];
                a[i+j] = a[i+j+1];
                a[i+j+1] = tmp;
            }
        }
    } else {
        c = -c;
        for (int i = -1; i < c-1; i++) {
            for (int j = n-c; j > 0; j--) {
                int tmp = a[j+i];
                a[j+i] = a[j+i+1];
                a[j+i+1] = tmp;
            }
        }
    }
}
