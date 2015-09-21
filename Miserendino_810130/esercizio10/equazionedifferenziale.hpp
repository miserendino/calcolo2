#ifndef EQUAZIONEDIFFERENZIALEBASE_HPP
#define EQUAZIONEDIFFERENZIALEBASE_HPP
#include "vettore.hpp"
#include "vettorelineare.hpp"
#include <iostream>
#include <cmath>

class equazionedifferenzialebase {

public:
	virtual vettorelineare passo(double, vettorelineare & , double, funzionevettorialebase *)=0;

};

class eulero : public equazionedifferenzialebase {
	public:
  eulero() {}
    vettorelineare passo(double t,vettorelineare& v, double h,funzionevettorialebase *f){
    vettorelineare a(v.getsize()); 
      a = v + f->eval(t,v)*h;  // x(t+h) = x(t) + x'*h, v(t+h) = v(t) + v'*h ---> è un'eqauzione vettoriale
    return a;    
    }
};


class runge_kutta: public equazionedifferenzialebase {
  public:
    runge_kutta(){}
    vettorelineare passo(double t,vettorelineare& x, double h,funzionevettorialebase *f){
      vettorelineare k1(x.getsize()),k2(x.getsize()),k3(x.getsize()),k4(x.getsize());
   k1 = f->eval(t,x);
   k2 = f->eval(t+h/2,x+k1*(h/2));
   k3 = f->eval(t+h/2,x+k2*(h/2));
   k4 = f->eval(t+h,x+k3*h);
      return x + (k1+ k2*2+k3*2 + k4)*(h/6);
    }
};


#endif
