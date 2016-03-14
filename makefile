main: polynomial.o main.o
	g++ polynomial.o main.o -o main

polynimial.o:	polynomial.h polynomial.cpp
	g++ -c  polynomial.cpp
	
main.o: main.cpp polynomial.h
	g++ -c main.cpp
	
clean:
	rm *o main main
