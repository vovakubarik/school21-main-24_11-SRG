#include <stdio.h>
#include <math.h>

void Agnesi_Func();
void QuadHyperbola_Func();
void lemnisBernoulli_Func();

int main() {
    double pi = 3.141592653589793238;
    for (double x = -pi; x <= pi; x += 2*pi / 41) {
        printf("%.7lf | ", x);
        Agnesi_Func(x);
        lemnisBernoulli_Func(x);
        QuadHyperbola_Func(x);
    }

    return 0;
}

void Agnesi_Func(double x) {
    double y = 1 / (1 + x * x);
    if (y != y) {
        printf("- | ");
    } else {
        printf("%.7lf | ", y);
    }
}

void lemnisBernoulli_Func(double x) {
    double y = (double)sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    if (y != y) {
        printf("- | ");
    } else {
        printf("%.7lf | ", y);
    }
}
void QuadHyperbola_Func(double x) {
    double y = 1 / (x * x);
    if (y != y) {
        printf("-\n");
    } else {
        printf("%.7lf\n", y);
    }
}
