#include "polynomial.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

Polynomial::Polynomial(int){

}

Polynomial::Polynomial(const Polynomial&){

}

Polynomial::~Polynomial(){

}

string Polynomial::toString()const{

}

const Polynomial Polynomial::operator()()const{

} // derivada
double Polynomial::operator()(double)const{

}// evaluacion
double Polynomial::operator()(double, double)const{

}// integral definida
void Polynomial::set(int, double){
	
}

ostream& operator<<(ostream&, const Polynomial&){

}
istream& operator>>(istream&, Polynomial&){

}
