#include "polynomial.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

using std::stringstream;
using std::string;
using std::showpos;
using std::noshowpos;
using std::ostream;
using std::istream;

Polynomial::Polynomial(int grado){
    this->degree=grado;
    this->coeficientes=new double[grado+1]; 
}

Polynomial::Polynomial(){
    this ->degree=1;
    this->coeficientes=new double[1]; 
}

Polynomial::Polynomial(const Polynomial& copia){
    this->degree=copia.degree;
    if (!coeficientes){
		throw "Not Enough Memory";
	}
    coeficientes = new double[degree+1];
	for (int i=0; i<=degree; i++){
		coeficientes[i] = copia.coeficientes[i];
	}
}

Polynomial::~Polynomial(){
    if (coeficientes)
	    delete[] coeficientes;
}

string Polynomial::toString()const{
    stringstream ss;
    for(int i=degree;i>=0;i--){
        if(i==0){
            ss << showpos <<coeficientes[i];
        }else if(i==1){
            ss << showpos <<coeficientes[i] << "x";
        }else if(coeficientes[i]==1){
            ss << "+ x^" <<noshowpos<<i;
        }else if(coeficientes[i]==-1){
            ss << "- x^" <<noshowpos<<i;
        }else{
            ss << showpos << coeficientes[i] << "x^" << noshowpos << i;
        }
    }
    ss << noshowpos;
    return ss.str();
}

const Polynomial Polynomial::operator()()const{
    Polynomial z=Polynomial(degree-1);

    int temp=0;
    for(int i=1;i<=degree;i++){
        if(i==1){
            z.set(temp,coeficientes[i]);
        }else{
            double coef=0;
            coef=coeficientes[i]*i;
            z.set(temp,coef);
        }
        temp++;
    }
    return z;
} // derivada

double Polynomial::operator()(double base)const{
    double total=0;
    for(int i=0;i<=degree;i++){
        total+=coeficientes[i]*(pow(base,i));
    }
    return total;
}// evaluacion

double Polynomial::operator()(double a, double b)const{
    double total=0;
    for(int i=0;i<=degree;i++){
        total+=coeficientes[i]*(pow(a,i+1))*(1.0/(i+1.0));
    }
    for(int i=0;i<=degree;i++){
        total-= coeficientes[i] * (pow(b,i+1)) * (1.0/(i+1.0));
    }
    return total;
}// integral definida

const Polynomial Polynomial::operator*(const Polynomial& operando)const{
    int grado=degree+operando.degree;
    Polynomial temp=Polynomial(grado);
    for(int i=0;i<=operando.degree;i++){
        for(int j=0;j<=degree;j++){
            double coef=temp.coeficientes[i+j]+operando.coeficientes[i]*coeficientes[j];
            temp.set(i+j,coef);
        }
    }
    return temp;
}
const Polynomial Polynomial::operator*=(const Polynomial& operando){
    int grado=degree+operando.degree;
    Polynomial temp=Polynomial(grado);
    for(int i=0;i<=operando.degree;i++){
        for(int j=0;j<=degree;j++){
            double coef=temp.coeficientes[i+j]+operando.coeficientes[i]*coeficientes[j];
            temp.set(i+j,coef);
        }
    }
    this->assign(temp);
    return *this;
}
		
const Polynomial Polynomial::operator+(const Polynomial& operando)const{
    int menor,mayor;
    if(degree < operando.degree){
        menor=degree;
        mayor=operando.degree;
    }else{
        menor=operando.degree;
        mayor=degree;
    }
    Polynomial temp=Polynomial(mayor);
    if(degree < operando.degree){
        double t;
        for(int i=0;i<=mayor;i++){
            t=operando.coeficientes[i];
            if(i<=menor){
                t+=coeficientes[i];
            }
            temp.set(i,t);
            t=0;
        }
    }else{
        double t;
        for(int i=0;i<=mayor;i++){
            t=coeficientes[i];
            if(i<=menor){
                t+=operando.coeficientes[i];
            }
            temp.set(i,t);
            t=0;
        }
    }
    return temp;
}
const Polynomial Polynomial::operator-(const Polynomial& operando)const{
    int menor,mayor;
    if(degree < operando.degree){
        menor=degree;
        mayor=operando.degree;
    }else{
        menor=operando.degree;
        mayor=degree;
    }
    Polynomial temp=Polynomial(mayor);
    if(degree < operando.degree){
        double t;
        for(int i=0;i<=mayor;i++){
            t=operando.coeficientes[i];
            if(i<=menor){
                t-=coeficientes[i];
            }
            temp.set(i,t);
            t=0;
        }
    }else{
        double t;
        for(int i=0;i<=mayor;i++){
            t=coeficientes[i];
            if(i<=menor){
                t-=operando.coeficientes[i];
            }
            temp.set(i,t);
            t=0;
        }
    }
    return temp;
}

const Polynomial& Polynomial::assign(const Polynomial& nuevo){
	if (degree != nuevo.degree){
		delete[] coeficientes;
		degree = nuevo.degree;
		coeficientes = new double[degree+1];
	}
	for (int i=0; i<=degree; i++)
		coeficientes[i] = nuevo.coeficientes[i];
	return *this;
}

const Polynomial Polynomial::operator+=(const Polynomial& operando){
    Polynomial temp;
    int menor,mayor;
    if(degree < operando.degree){
        menor=degree;
        mayor=operando.degree;
        temp.assign(*this);
        this->assign(operando);
    }else{
        menor=operando.degree;
        mayor=degree;
        temp.assign(operando);
    }
    double t;
    for(int i=0;i<=menor;i++){
        t=coeficientes[i];
        t+=temp.coeficientes[i];
        this->set(i,t);
    }
    return *this;
}
const Polynomial Polynomial::operator-=(const Polynomial& operando){
    Polynomial temp;
    Polynomial operar;
    operar.assign(operando);
    minus(operar);
    double t;
    int menor,mayor;
    if(degree < operando.degree){
        mayor=operando.degree;
        menor=degree;
        temp.assign(*this);
        this->assign(operar);
    }else{
        menor=operando.degree;
        mayor=degree;
        temp.assign(operar);
    }

    for(int i=0;i<=menor;i++){
        t=coeficientes[i];
        t+=temp.coeficientes[i];
        this->set(i,t);
    }
    return *this;
}

void Polynomial::minus(Polynomial& operando){
    for(int i=0;i<=operando.degree;i++){
        double t=operando.coeficientes[i]*-1;
        operando.set(i,t);
    }
}

void Polynomial::set(int posicion, double coeficiente){
    if(posicion>=0 && posicion<=degree){
        this->coeficientes[posicion]=coeficiente;
    }
}

const Polynomial Polynomial::operator=(const Polynomial& nuevo){
	if (degree != nuevo.degree){
		delete[] coeficientes;
		degree = nuevo.degree;
		coeficientes = new double[degree+1];
	}
	for (int i=0; i<=nuevo.degree; i++)
		coeficientes[i] = nuevo.coeficientes[i];
	return *this;
}

ostream& operator << (ostream& output, const Polynomial& salida){
    for(int i=salida.degree;i>=0;i--){
        if(i==0){
            if(salida.coeficientes[i]==1){
                output <<"+1";
            }else if(salida.coeficientes[i]==-1){
                output <<"-1";
            }else if(salida.coeficientes[i]==0){
                
            }else{
                output << showpos <<salida.coeficientes[i];            
            }
        }else if(i==1){
            if(salida.coeficientes[i]==0){

            }else{
                output << showpos <<salida.coeficientes[i] << "x";            
            }
        }else if(salida.coeficientes[i]==1){
            output << "+ x^" <<noshowpos<<i;
        }else if(salida.coeficientes[i]==-1){
            output << "- x^" <<noshowpos<<i;
        }else{
            output << showpos << salida.coeficientes[i] << "x^" << noshowpos << i;
        }
    }
    output << noshowpos;
    return output;
}

istream& operator>>(istream& input, Polynomial& ingreso){
    input >> ingreso.degree;
    for(int i=ingreso.degree;i>=0;i--){
        input >> ingreso.coeficientes[i];
    }
	return input;
}
