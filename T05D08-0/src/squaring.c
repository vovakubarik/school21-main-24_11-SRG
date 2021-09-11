// Coryright 2021, gsherley. All rights reserved.
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int f = 1;
    if (!input(data, &n)) f = 0;
    if (f == 1) {
        squaring(data, n);
        output(data, n);
    }
    return 0;
}

int input(int *a, int *n) {
    int f = 1;
    if (scanf("%d", n) != 1 || *n > NMAX || *n < 1) {
        printf("n/a");
        f = 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1 && f != 0) {
            printf("n/a");
            f = 0;
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

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
