#include <iostream>

using namespace std;

int main()
{
    int a,b;
    char c,d;
    int *p,**pp;
    char *q;

    a=1;
    b=2;

    c='A';
    d='E';
    p=&a;
    q=&c;
    pp=&p;

    cout <<"El valor de a es: "<<a<<" y la direccion de a es: "<<&a << endl;
    cout <<"El puntero p apunta a: "<<p<<" y su contenido es: "<<*p << endl;
    cout <<"El valor de c es: "<<c<<" y la direccion de c es: "<<&c << endl;
    cout <<"El puntero q apunta a: "<<q<<" y su contenido es: "<<*q << endl;
    *q=d;
    cout <<"El valor de c ahora es: "<<c<<" y la direccion de c es: "<<&c << endl;

    *pp=&b;
    cout <<"El puntero p ahora apunta a: "<<p<<" y su contenido ahora es: "<<*p << endl;
    cout <<"La direccion de pp es: "<< &pp<<endl;
    cout <<"el contenido de pp es: "<< *pp<<endl;
    cout <<"La contenido del contenido de pp es: "<< **pp<<endl;


}