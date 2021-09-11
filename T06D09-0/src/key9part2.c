// Copyright 2021, gsherley. All rights reserved.

#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2,
int *result, int *result_length);
int sub(int *buff1, int len1, int *buff2, int len2,
int *result, int *result_length);
int input(int *a, int *n);
void output(int *a, int n);

int main() {
    int l1, l2, l3, a1[LEN], f = 1;
    f = input(a1, &l1);
    if (f == 1) {
        int a2[LEN];
        f = input(a2, &l2);
        if (f == 1) {
            int a3[LEN];
            sum(a1, l1, a2, l2, a3, &l3);
            output(a3, l3);
            printf("\n");
            f = sub(a1, l1, a2, l2, a3, &l3);
            if (f == 1) {
            output(a3, l3);}
        }
    }
    if (f == 0) {
        printf("n/a");}
}

int input(int *r, int *n) {
  int f = 1;
  char c = ' ';
  *n = -1;
  while (1) {
    if (f == 0) {
        break;}
    scanf("%c", &c);
    if (c == '\n') {
        break;}
    if (c == ' ') {
        continue;}
    int a = c - '0';
    if (a < 0 || a > 9) {
        f = 0;}
    (*n)++;
    if (*n >= LEN) {
        f = 0;}
    r[*n] = a;
  }
  return f;
}

void output(int *a, int n) {
    int f = 1, out = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0 && f == 1) {
            continue;}
        if (a[i] != 0) {
            f = 0;}
        printf("%d", a[i]);
        out = 1;
        if (i != 0) {
            printf(" ");}
    }
        if (out == 0) {
            printf("0");
        }
}

void sum(int *buff1, int len1, int *buff2, int len2,
int *result, int *result_length) {
  int f = 0;
  *result_length = 0;
  int i, j;
  for (i = len1, j = len2; i >= 0 && j >= 0; i--, j--) {
    if (f == 0) result[*result_length] = buff1[i] + buff2[j];
    if (f == 1) {
      f = 0;
      result[*result_length] += buff1[i] + buff2[j];
    }
    if (result[*result_length] > 9) {
      f = 1;
      result[*result_length + 1] = result[*result_length] / 10;
      result[*result_length] %= 10;
    }
    (*result_length)++;
  }
  if (i < 0) {
    for (int k = j; k >= 0; k--) {
      result[(*result_length)++] = buff2[k];
    }
  }
  if (j < 0) {
    for (int k = i; k >= 0; k--) {
      result[(*result_length)++] = buff1[k];
    }
  }
}

int sub(int *buff1, int len1, int *buff2, int len2,
int *result, int *result_length) {
    int f = 0, out = 1;
      *result_length = 0;
      int i, j;

      for (i = len1, j = len2; i >= 0 && j >= 0; i--, j--) {
        if (out == 0) {
            break; }
        if (f == 0) {
            result[*result_length] = buff1[i] - buff2[j];}
        if (f == 1) {
          f = 0;
          result[*result_length] += buff1[i] - buff2[j];}
        if (result[*result_length] < 0) {
          if (*result_length >= len1) {
              out = 0;}
          f = 1;
          result[*result_length + 1] = -1;
          result[*result_length] += 10;
        }
        (*result_length)++;
      }

      if (i < 0 && i != j) {
          out = 0;}
      if (j < 0 && out == 1) {
        for (int k = i; k >= 0; k--) {
          if (f == 0) result[(*result_length)++] = buff1[k];
          if (f == 1) {
            f = 0;
            result[(*result_length)++] += buff1[k];
          }
        }
      }
      return out;
}
