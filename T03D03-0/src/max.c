// Copyright 2021, gsherley. All rights reserved.
#include <stdio.h>

int Max(int a, int b);

int Max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    printf("Enter two integer numbers: ");
    int num1, num2;
    char c;
    if (scanf("%d", &num1) == 1 && scanf("%d", &num2) == 1) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            int max = Max(num1, num2);
            printf("%d", max);}
            else
            printf("n/a");}
            else
        printf("n/a");
    return 0;
}
