// Copyright 2021, gsherley. All rights reserved.
#include <stdio.h>
#include <math.h>

float calc(float x);

float calc(float x) {
    return 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1/3) - 1e3) * x + 3) / (x * x / 2) - x * pow(10+x, 2/x) - 1.01;
}

int main() {
    printf("Enter float number: ");
    float y, x;
    char c;
    if (scanf("%f", &x) == 1 && x == (float)x) {
        scanf("%c", &c);
        if (c == '\n' || c == '\0' || c == ' ') {
            y = calc(x);
            printf("Function value %.1f", y);   }
    else
    printf("n/a"); }
    else
    printf("n/a");
    return 0;
}
