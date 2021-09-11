// Copyright 2021 gsherley
/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers, int* k);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
    int array_in[NMAX], n, m;
    int f = 1;
    if (!input(array_in, &n)) f = 0;
    if (f == 1) {
        int array_out[NMAX];
        int sum = sum_numbers(array_in, n);
        f = find_numbers(array_in, n, sum, array_out, &m);
            if (f == 1) {
            printf("%d\n", sum);
            output(array_out, m);
        }
    }
    if (f == 0) {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    int f = 1;
    if (scanf("%d", length) != 1 || *length > NMAX || *length < 1) {
        f = 0;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
        if (scanf("%d", p) != 1 && f!= 0) {
            f = 0;
            }
        }
    }
    return f;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i != length - 1) printf(" ");
    }
}
/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
        sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers, int* k) {
    int f = 0;
    *k = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[(*k)++] = buffer[i];
            f = 1;
        }
    }
    return f;
}
