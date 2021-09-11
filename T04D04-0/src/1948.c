// Copyright 2021, gsherley. All rights reserved.
#include <stdio.h>
#include <math.h>

int div(int n, int a);
int simple(int a);

int main() {
    float num;
    int maxdiv, i;
    char c;
    printf("Enter number:");

    if (scanf("%f", &num) == 1 && num == (int)num) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            if (num < 0) num = -num;
            maxdiv = 1;
            for (i = 2; i <= num; i++) {
                if (div(num, i) && simple(i)) {
                    maxdiv = i;
                }
            }
            printf("%d", maxdiv); }
            else
    printf("n/a"); }
    else
    printf("n/a");
    return 0;
}

int div(int n, int a) {
    int d = n;
    while (d >= 0) {
        d -= a;
    }
    if (d + a == 0) return 1;
    else
    return 0;
}

int simple(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (div(a, i)) return 0;
    }
    return 1;
}
