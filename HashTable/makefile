dataStruct = HashTable

all : main.o $(dataStruct).o
	g++ main.o $(dataStruct).o -o main.out
	rm *.o

debug : main.o $(dataStruct).o
	g++ -g main.o $(dataStruct).o -o debug.out
	rm *.o

main.o :
	g++ -c main.cpp

$(dataStruct).o :
	g++ -c $(dataStruct).cpp

clean :
	rm -rf *.out *.dSYM $(dataStruct) main *.o
