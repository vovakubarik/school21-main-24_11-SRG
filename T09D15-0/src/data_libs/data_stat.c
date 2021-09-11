#include "data_stat.h"

double max(double *arr, int n) {
    double max = *arr;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double min(double *arr, int n) {
    double min = *arr;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double mean(double *data, int n) {
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    return mean/(double) n;
}

double variance(double *data, int n, double mean) {
    double var = 0;
    for (int i = 0; i < n; i++) {
        var += ((data[i] - mean) * (data[i] - mean));
    }
    return var/(double)n;
}

void sort(double *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
            int c = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = c;
            }
        }
    }
}
