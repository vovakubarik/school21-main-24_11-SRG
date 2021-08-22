// Copyright 2021, gsherley. All rights reserved.
#include <stdio.h>

int main() {
    printf("Enter two numbers:");
    float num1, num2; int sum, diff, prod, quot;
    char c;

    if (scanf("%f", &num1) == 1 && num1 == (int)num1 && scanf("%f", &num2) == 1 && num2 == (int)num2) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1*num2;

    if (num2 == 0) quot = -1;
    else  quot = num1/num2;
    if (quot == -1) printf("%d %d %d n/a", sum, diff, prod);
    else
    printf("%d %d %d %d", sum, diff, prod, quot); }
    else
    printf("n/a"); }
    else
    printf("n/a");
    return 0;
}
