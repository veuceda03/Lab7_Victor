main: main.o complex.o
	g++ main.o complex.o -o complex 
	
main.o:	main.cpp complex.h
	g++ -c main.cpp 

complex.o:	complex.cpp complex.h
	g++ -c complex.cpp 
