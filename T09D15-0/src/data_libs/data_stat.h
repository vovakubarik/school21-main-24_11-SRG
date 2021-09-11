#ifndef SRC_DATA_LIBS_DATA_STAT_H_
#define SRC_DATA_LIBS_DATA_STAT_H_

double max(double *arr, int n);
double min(double *arr, int n);
double mean(double *data, int n);
double variance(double *data, int n, double mean);
void sort(double *arr, int n);

#endif  // SRC_DATA_LIBS_DATA_STAT_H_
