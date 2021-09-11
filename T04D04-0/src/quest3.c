// Copyright 2021, gsherley. All rights reserved.
#include <stdio.h>
#include <math.h>

int fi(int N) {
    if (N <= 1)
    return N;
    else
    return fi(N - 1) + fi(N - 2);
}
int main() {
  float a; char c;
  printf("Enter the number of fibonacci number: ");

    if (scanf("%f", &a) == 1 && a == (int)a) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            printf("Result is %d", fi(a));
        } else {
        printf("n/a");}
    } else {
    printf("n/a");}
  return 0;
}
