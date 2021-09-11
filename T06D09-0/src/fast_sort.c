// Copyright 2021 gsherley
#include <stdio.h>

int input(int *a, int* n);
void output(int *a, int n);
void fast_sort(int *a, int left, int right);
void heap_sort(int *a, int n);
void swap(int *a, int *b);
void copy(int* arr1, int* arr2, int n);

int main() {
    int n = 10, data1[n];
    int f = 1;
    if (!input(data1, &n)) f = 0;
    if (f == 1) {
        int data2[10];
        copy(data1, data2, n);
        fast_sort(data1, 0, n-1);
        output(data1, n);
        printf("\n");
        heap_sort(data2, n);
        output(data2, n);
    }
    return 0;
}

int input(int *a, int *n) {
    int f = 1;
        for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1 && f != 0) {
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

void copy(int* arr1, int* arr2, int n) {
    for (int* p = arr1; p - arr1 < n; p++) {
        *(p + (arr2 - arr1)) = *p;
    }
}

void fast_sort(int *arr, int left, int right) {
    int p;
    int left_b = left;
    int right_b = right;
    p = arr[left];
    while (left < right) {
    while ((arr[right] >= p) && (left < right))
    right--;
    if (left != right) {
      arr[left] = arr[right];
      left++;
    }
    while ((left < right) && (arr[left] <= p))
      left++;
    if (left != right) {
      arr[right] = arr[left];
      right--;
    }
  }
  arr[left] = p;
  p = left;
  left = left_b;
  right = right_b;
  if (left < p)
    fast_sort(arr, left, p - 1);
  if (right > p)
    fast_sort(arr, p + 1, right);
}

void heap_sort(int *a, int n) {
    int i, sh = 0;
    while (1) {
    int b = 0;
    for (i = 0; i < n; ++i) {
      if (i*2 + 2 + sh < n) {
        if (a[i+sh] > a[i*2 + 1 + sh] || a[i + sh] > a[i*2 + 2 + sh]) {
            if (a[i*2+1+sh] < a[i*2+2+sh]) {
        swap(&a[i+sh], &a[i*2+1+sh]);
        b = 1;
      } else if (a[i*2+2+sh] < a[i*2+1+sh]) {
        swap(&a[i+sh], &a[i*2+2+sh]);
        b = 1;
    }
       }
    } else if (i * 2 + 1 + sh < n) {
        if (a[i+sh] > a[i*2+1+sh]) {
            swap(&a[i+sh], &a[i*2+1+sh]);
            b = 1;
            }
        }
    }
    if (!b) sh++;
    if (sh+2 == n)
      break;
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
