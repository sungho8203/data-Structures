dataStruct = Queue

all : main.o $(dataStruct).o
	g++ main.o $(dataStruct).o -o main.out
	rm *.o

main.o :
	g++ -c main.cpp

$(dataStruct).o :
	g++ -c $(dataStruct).cpp

clean :
	rm -rf main.out *.dSYM $(dataStruct) main
