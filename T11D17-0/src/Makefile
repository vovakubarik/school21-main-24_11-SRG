FLAGS = -Wall -Wextra -Werror
.PHONY: all clean rebuild

all: door_struct stack_test

door_struct: dmanager_module.c
	gcc $(FLAGS) -c dmanager_module.c -o dmanager_module.o
	gcc $(FLAGS) -o ../build/Quest_1 dmanager_module.o
stack_test: stack stack_tests
	gcc $(FLAGS) -o ../build/Quest_3 stack.o stack_test.o
stack: stack.c
	gcc $(FLAGS) -c stack.c -o stack.o
stack_tests: stack_test.c
	gcc $(FLAGS) -c stack_test.c -o stack_test.o
clean:
	rm -rf *.o ../build/*

rebuild:
	$(MAKE) clean
	$(MAKE) all