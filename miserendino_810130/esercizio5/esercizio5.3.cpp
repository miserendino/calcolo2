#include <iostream>
#include <cmath>
#include "funzione.hpp"
#define   M_PI   3.14159265358979323846 /* pi */
using namespace std;

int main(){

double a, b,v;
for (int i=1; i<21;i++){
     a=i*M_PI;
     b=i*M_PI+M_PI/2;
     std::cout << a << " " << b << std::endl;
     funzionebase *f=new sinusoide ();
#ifdef DEBUG
     v=f->eval(a);
     std::cout << v << std::endl;
     v=f->eval(b);
     std::cout << v << std::endl;
#endif    
     ricerca x(a,b,10E-6);
       x.cercazeri(a,b,f);
       x.print();
       }
        return 0;
}

