CC = gcc -g
DB = gdb

SRC = $(shell find . -name '*.c' ! -name 'temp*.c')
SRC_O = $(SRC:.c=.o)

TEMP_SRC = $(shell find . -name 'temp*.c')

INC_DIRS = $(dir $(shell find . -name "*.h"))
INC = $(addprefix -I ,$(INC_DIRS))



all : main

main : main_cc
	./main.out

mdb : main_cc
	$(DB) ./main.out

main_cc: $(SRC_O)
	$(CC) $^ -o main.out

%.o: %.c
	$(CC) -c $< -o $@ $(INC)



temp : temp_cc
	./temp.out

tdb : temp_cc
	lldb ./temp.out

temp_cc:
	$(CC) $(TEMP_SRC) -o temp.out -I $(HEAD)



clean :
	rm -rf *.out *.dSYM main *.o $(SRC_O)
