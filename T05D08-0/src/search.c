// Coryright 2021, gsherley. All rights reserved.
#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n, double mean);
void search(int *a, int n);

int main() {
    int n, data[NMAX];
    int f = 1;
    if (!input(data, &n)) f = 0;
    if (f == 1) {
        search(data, n);
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

void search(int *a, int n) {
    int f = 0;
    double meanv = mean(a, n);
    double sigma = meanv + 3 * sqrt(variance(a, n, meanv));
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= meanv && a[i] <= sigma && a[i] != 0 && f != 1) {
            printf("%d", a[i]);
            f = 1;
        }
    }
    if (f == 0) printf("0");
}
