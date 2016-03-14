#include "vector.h"
#include <iostream>
using std::cout;
using std::endl;

void wapa(Vector, char);
int main(int argc, char* argv[]){
	cout << "Iniciando el main" << endl;
	
	Vector a(3), b(3), c(2);
	a.set(2.5,0);
	a.set(-4,1);
	a.set(0,2);
	b.set(5,0);
	b.set(2,1);
	b.set(-1.1,2);

	cout << a.toString() << endl << b.toString() << endl << c.toString() << endl;
	wapa(a, 'a');
	wapa(b, 'b');
	wapa(c, 'c');
	c.assign(a.suma(b));

	Vector d(a);


	cout << a.toString() << endl << b.toString() << endl << c.toString() << endl;


	return 0;
}

void wapa(Vector v, char var){
	cout << "Entrando a wapa con variable: " << var << endl;
	cout << v.toString() << endl;
}
