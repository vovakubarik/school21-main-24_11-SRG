#include <stdio.h>
#include "data_io.h"


int input(double *arr, int n) {
    if (!scanf("%d", &n) || n < 1) return 0;
    for (int i = 0; i < n; i++) {
        if (!scanf("%lf", &arr[i])) {
                return 0;
            }
    }
    return 1;
}

void output(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", arr[i]);
        if (i != n-1) printf(" ");
    }
}
