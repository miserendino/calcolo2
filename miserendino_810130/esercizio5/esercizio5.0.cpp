#include <iostream>
#define M 5.972E24
#include <memory>
#define R 6.371
#include "posizione.hpp"
int main(int argc, char ** argv){

particella *a =new particella(1.,2.);
particella *b =new elettrone();
particella *c=new corpoceleste("Terra",M,R);

a->print();
b->print();
c->print();

delete a,b,c;

	return 0;
}
