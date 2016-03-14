#include "complex.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::ostream;
using std::istream;
using std::showpos;
using std::noshowpos;

Complex::Complex(double real, double imag):real(real), imag(imag){
}


const Complex& Complex::operator=(const Complex& r){
	real = r.real;
	imag = r.imag;
	return *this;
}

string Complex::toString() const{
	stringstream ss;
	ss << real << " + " << imag << "i";
	return ss.str();
}

const Complex operator+(const Complex& lhs, const Complex& rhs){
	Complex retVal = lhs;
	retVal += rhs;
	return retVal;
}
const Complex operator-(const Complex& lhs, const Complex& rhs){
	Complex retVal = lhs;
	retVal -= rhs;
	return retVal;
}
/*
const Complex Complex::operator+(const Complex& r) const{
   return Complex(real + r.real, imag + r.imag);
}

const Complex Complex::operator-(const Complex& r) const{
   return Complex(real - r.real, imag - r.imag);
}
*/
const Complex Complex::operator-() const{
   return Complex(-real, -imag);
}

const Complex& Complex::operator+=(const Complex& r){
   real += r.real;
   imag += r.imag;
   return *this;
}

const Complex& Complex::operator-=(const Complex& r){
   return *this += -r;
}

ostream& operator<<(ostream& output, const Complex& c){
	if (c.real == 0){
		if (c.imag == 0){
			output << 0.0;
		}else{
			if (c.imag == 1)
				output << "i";
			else if (c.imag == -1)
				output << "-i";
			else
				output << c.imag << "i";
		}
	}else{
		if (c.imag == 0)
			output << c.real;
		else
			if (c.imag == 1)
				output << c.real << "i";
			else if (c.imag == -1)
				output << c.real << "-i";
			else	
				output << c.real << showpos << c.imag << "i";
	}
	output << noshowpos;
	return output;
}
istream& operator>>(istream& input, Complex& c){
	input >> c.real >> c.imag;
	return input;
}
