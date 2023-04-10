all : main.o LinkdList.o
	g++ -o main.out main.o LinkdList.o
	rm *.o

main.o :
	g++ -c main.cpp

LinkdList.o :
	g++ -c LinkdList.cpp

clean :
	rm -rf *.out LinkdList LinkdList.dSYM
