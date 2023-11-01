SRC = $(shell find . -name '*.c' ! -name 'temp*.c')
HEAD = ./include
SRC_O = $(SRC:.c=.o)
TEMP_SRC = $(shell find . -name 'temp*.c')

CC = gcc -g

all : main

main : main_cc
	./main.out

mdb : main_cc
	lldb ./main.out

main_cc: $(SRC_O)
	$(CC) $^ -o main.out -I $(HEAD)

%.o: %.c
	$(CC) -c $<


temp : temp_cc
	./temp.out

tdb : temp_cc
	lldb ./temp.out

temp_cc:
	$(CC) $(TEMP_SRC) -o temp.out -I $(HEAD)


clean :
	rm -rf *.out *.dSYM main *.o
