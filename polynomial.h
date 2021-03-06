#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Polynomial{
	int degree;
	double* coeficientes;
  public:
	explicit Polynomial(int);
	explicit Polynomial();
	Polynomial(const Polynomial&);
	~Polynomial();
	string toString()const;
	void set(int, double);
	const Polynomial operator()()const; // derivada
	double operator()(double)const; // evaluacion
	double operator()(double, double)const; // integral definida
	const Polynomial operator*(const Polynomial&)const;
	const Polynomial operator*=(const Polynomial&);
	const Polynomial& assign(const Polynomial&);
	const Polynomial operator+(const Polynomial&)const;
	const Polynomial operator-(const Polynomial&)const;
	const Polynomial operator+=(const Polynomial&);
	const Polynomial operator-=(const Polynomial&);
	const Polynomial operator=(const Polynomial&);
    void minus(Polynomial& operando);

	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
};

