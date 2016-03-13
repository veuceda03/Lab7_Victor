main: Racional.o main.o
	g++ Racional.o main.o -o main

Racional.o:	Racional.h Racional.cpp
	g++ -c  Racional.cpp
	
main.o: main.cpp Racional.h
	g++ -c main.cpp
	
clean:
	rm *o main
