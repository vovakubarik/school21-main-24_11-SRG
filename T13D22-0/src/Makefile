FLAGS = -Wall -Wextra -Werror
.PHONY: all clean rebuild

all: cipher

cipher: cipher.c
	gcc $(FLAGS) cipher.c -o ../build/cipher

clean:
	rm -rf *.o ../build/*

check:
	python3 cpplint.py --extensions=c,h *
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
rebuild:
	$(MAKE) clean
	$(MAKE) all