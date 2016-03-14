#include <iostream>
#include "polynomial.h"

using std::cin;
using std::cout;
using std::endl;

void desplegarMenu();

int main(int argc,char* argv[]){
    bool continuar=true;
    do{
        int opcion;
        desplegarMenu();
        cin >> opcion;
        Polynomial evaluando;
        if(opcion!=11){
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> evaluando;
            cout << evaluando << endl;
        }
        if(opcion==1){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl;
            cout << evaluando << " + (" << operando << ") = " <<evaluando+operando << endl; 
        }else if(opcion==2){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl << evaluando;
            evaluando+=operando;
            cout <<" += (" << operando << ") = " <<evaluando<< endl;
        }else if(opcion==3){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl;
            cout << evaluando << " + (" << operando << ") = " <<evaluando-operando << endl; 
        }else if(opcion==4){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl << evaluando;
            evaluando-=operando;
            cout <<" += (" << operando << ") = " <<evaluando<< endl;        
        }else if(opcion==5){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl;
            cout << evaluando << " * (" << operando << ") = " <<evaluando*operando << endl;        
        }else if(opcion==6){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl << evaluando;
            evaluando*=operando;
            cout <<" *= (" << operando << ") = " <<evaluando<< endl;
        }else if(opcion==7){
            cout<<"Ingrese el número a evaluar: ";
            int x;
            cin >> x;
            cout <<"F("<<x<<")= "<<evaluando(x) << endl;        
        }else if(opcion==8){
            cout <<"F'(x)= " <<evaluando() << endl;
        }else if(opcion==9){
            int a,b;
            cout << "Ingrese el límite superior: ";
            cin >> a;
            do{
                cout << "Ingrese el límite inferior: ";
                cin >> b;
                if(b>=a){
                    cout << "Debe ingresar un número menor" << endl;
                }
            }while(b>a);
            cout<< "La integral definida de " << evaluando << " de "<< a << " hasta " << b<< " es: ";
            cout << evaluando(a,b) << endl; 
        }else if(opcion==10){
            Polynomial operando;
            cout << "Ingrese el polinomio: grado coef1 coef2 ...."<<endl;
            cin >> operando;
            cout << operando << endl << "Operación: " << endl;
            cout << evaluando << " = (" << operando << ") = ";
            evaluando=operando;
            cout<<evaluando<< endl;
        }else{
            continuar=false;
        }
    }while(continuar==true);
    return 0;
}

void desplegarMenu(){
    cout << "Bienvenido, ingrese una opción: "<< endl
         << "1: Suma +" << endl
         << "2: Adición +=" << endl
         << "3: Resta - " << endl
         << "4: Sustracción -=" << endl
         << "5: Multiplicación *" << endl
         << "6: Producto *=" << endl
         << "7: Evaluar " << endl
         << "8: Derivar " << endl
         << "9: Integral definida" << endl
         << "10: Igualarlo " << endl
         << "11: Salir" << endl;
}
