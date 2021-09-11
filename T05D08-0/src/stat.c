// Coryright 2021, gsherley. All rights reserved.
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n, double mean);
void output_result(int max_v,
                   int min_v,
                   double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    int f = 1;
    if (!input(data, &n)) f = 0;
    if (f == 1) {
    output(data, n);
    printf("\n");
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n, mean(data, n)));
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

int max(int *a, int n) {
    int max = *a;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double mean(int *a, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += a[i];
    }
    return mean/(double) n;
}

double variance(int *a, int n, double mean) {
    double var = 0;
    for (int i = 0; i < n; i++) {
        var += ((a[i] - mean) * (a[i] - mean));
    }
    return var/(double)n;
}

void output_result(int max_v,
                   int min_v,
                   double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
