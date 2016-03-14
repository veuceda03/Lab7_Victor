#pragma once
#include <string>
using std::string;

class Vector{
	int size;
	double* data;
  public:
	Vector(int);
	Vector(const Vector&);
	~Vector();
	string toString()const;
	const Vector suma(const Vector&)const;
	const Vector& assign(const Vector&);
	const Vector mult(double)const;
	void set(double, int);

};
