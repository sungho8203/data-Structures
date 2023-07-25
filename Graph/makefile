SRC = $(shell find . -name '*.cpp' ! -name 'temp*.cpp')
HEAD = ./include

TEMP_SRC = $(shell find . -name 'temp*.cpp')

CC = g++ -std=c++11 -g

all : main

main : main_cc
	./main.out

mdb : main_cc
	lldb ./main.out

main_cc:
	$(CC) $(SRC) -o main.out -I $(HEAD)



temp : temp_cc
	./temp.out

tdb : temp_cc
	lldb ./temp.out

temp_cc:
	$(CC) $(TEMP_SRC) -o temp.out -I $(HEAD)


clean :
	rm -rf *.out *.dSYM main *.o
