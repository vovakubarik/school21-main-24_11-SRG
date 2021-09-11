TARGET = ../../build/Quest_3
FLAGS = -Wall -Wextra -Werror
.PHONY: all clean rebuild

all: $(TARGET) 

$(TARGET): mainmodule.o io.o stat.o process.o decision.o
	gcc $(FLAGS) -o $(TARGET) mainmodule.o io.o stat.o process.o decision.o 

mainmodule.o: main_executable_module.c
	gcc $(FLAGS) -c main_executable_module.c -o mainmodule.o
io.o: ../data_libs/data_io.c
	gcc $(FLAGS) -c ../data_libs/data_io.c -o io.o
stat.o: ../data_libs/data_stat.c
	gcc $(FLAGS) -c ../data_libs/data_stat.c -o stat.o
process.o: ../data_module/data_process.c
	gcc $(FLAGS) -c ../data_module/data_process.c -o process.o
decision.o: ../yet_another_decision_module/decision.c
	gcc $(FLAGS) -c ../yet_another_decision_module/decision.c -o decision.o
data_stat.a: stat.o
	ar rc libdata_stat.a stat.o
	ranlib libdata_stat.a
build_with_static: mainmodule.o io.o data_stat.a process.o decision.o
	gcc $(FLAGS) -o ../../build/Quest_5 mainmodule.o io.o process.o decision.o -L. -ldata_stat  
data_process.so: ../data_module/data_process.c stat.o
	gcc $(FLAGS) -fPIC -c ../data_module/data_process.c
	gcc $(FLAGS) -shared -o libdata_process.so data_process.o stat.o
build_with_dynamic: mainmodule.o io.o stat.o data_process.so decision.o process.o
	gcc $(FLAGS) -o ../../build/Quest_6 mainmodule.o io.o decision.o process.o  -L. -ldata_process

clean:
	rm -rf *.o *.a *.so ../../build/Quest_3 ../../build/Quest_5 ../../build/Quest_6

rebuild:
	$(MAKE) clean
	$(MAKE) all