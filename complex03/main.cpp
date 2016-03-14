#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "complex.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main(int argc, char const *argv[]){
	Complex a(0,0), b(2,-1), c(4,4), d(-5, 0);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << "Favor ingrese un complejo: ";
	cin >> d;

	cout << "La suma de " << a << " y " << d << " es: " << a + d << endl;

	return 0;
}

