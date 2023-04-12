all : main.o Stack.o
	g++ main.o Stack.o -o main.out
	rm *.o

main.o :
	g++ -c main.cpp

Stack.o :
	g++ -c Stack.cpp

clean :
	rm -rf main.out Stack.dSYM Stack
