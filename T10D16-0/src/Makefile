FLAGS = -Wall -Wextra -Werror
.PHONY: all clean rebuild

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: s21_string_test s21_string
	gcc -D Quest_1 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_1 s21_string_test.o s21_string.o main.o 
strcmp_tests: s21_string_test s21_string
	gcc -D Quest_2 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_2 s21_string_test.o s21_string.o main.o
strcpy_tests: s21_string_test s21_string
	gcc -D Quest_3 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_3 s21_string_test.o s21_string.o main.o
strcat_tests: s21_string_test s21_string
	gcc -D Quest_4 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_4 s21_string_test.o s21_string.o main.o
strchr_tests: s21_string_test s21_string
	gcc -D Quest_5 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_5 s21_string_test.o s21_string.o main.o
strstr_tests: s21_string_test s21_string
	gcc -D Quest_6 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_6 s21_string_test.o s21_string.o main.o
strtok_tests: s21_string_test s21_string
	gcc -D Quest_7 -c main.c -o main.o
	gcc $(FLAGS) -o ../build/Quest_7 s21_string_test.o s21_string.o main.o
s21_string_test: s21_string_test.c
	gcc $(FLAGS) -c s21_string_test.c -o s21_string_test.o
s21_string: s21_string.c
	gcc $(FLAGS) -c s21_string.c -o s21_string.o
main: main.c
	gcc $(FLAGS) -c main.c -o main.o

clean:
	rm -rf *.o ../build/*

rebuild:
	$(MAKE) clean
	$(MAKE) all