#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Complex{
	double real, imag;
public:
//	Complex(double, double);
	explicit Complex(double=0, double=0);
	string toString() const;
	const Complex& operator=(const Complex&);
	const Complex operator-() const;
	const Complex& operator+=(const Complex&);
	const Complex& operator-=(const Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};

const Complex operator+(const Complex&, const Complex&);
const Complex operator-(const Complex&, const Complex&);
