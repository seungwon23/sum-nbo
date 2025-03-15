#Makefile
all: nbo-test

nbo-test: main.o nbo.o
	g++ -o nbo-test main.o nbo.o

main.o: nbo.h main.cpp
	g++ -c -o main.o main.cpp

nbo.o: nbo.h nbo.cpp
	g++ -c -o nbo.o nbo.cpp

clean: 
	rm -f nbo-test
	rm -f *.o
