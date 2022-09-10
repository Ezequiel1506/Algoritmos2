#include <iostream>

using namespace std;

int main()
{
    int a,b;
    int *p,*q;

    a=10;
    b=20;

    p=&a;
    q=&b;

    cout <<"El valor de a es: "<<a<<" y la direccion de a es: "<<&a << endl;
    cout <<"El valor de b es: "<<b<<" y la direccion de b es: "<<&b << endl;

    cout <<"El puntero p apunta a: "<<p<<" y su contenido es: "<<*p << endl;
    cout <<"El puntero q apunta a: "<<q<<" y su contenido es: "<<*q << endl;

    *p+=1;
    cout <<"El puntero p apunta a: "<<p<<" y su contenido ahora es: "<<*p << endl;
    cout <<"La direccion de p es: "<< &p<<endl;

}