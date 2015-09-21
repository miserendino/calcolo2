#ifndef RANDOM_HPP
#define RANDOM_HPP
using namespace std;
#include <iostream>
#include "funzione.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
#define TWO_PI 6.2831853071795864769252866


// Occhio che in questo le lettere sono maiuscole!!! 

class Random{

  public:
    Random(unsigned int seed){ _seed=seed;}
    void setA(unsigned int a){ _a=a; }
    void setC(unsigned int c){ _c=c; }
    void setM(unsigned int m){ _m=m; }
    double esponenziale(double );
   	double BoxMuller(double , double );
    double Rand01();
   // void Randgauss(double a,double b,double max);
  private:
    unsigned int _a;
    unsigned int _m;
    unsigned int _c;
    unsigned int _seed;
};

double Random::Rand01(){                  // metodo per generare numeri casuali tra 0 e 1
  double risultato=((_a*(_seed)+_c)%_m);
  _seed=risultato;
  return risultato/(_m-1);
}
#if 0
void Random::Randgauss(double a,double b,double max){               // metodo per generare numeri distribuiti gaussianamente
  double x1=Rand01(),y1=Rand01();
  x_gauss = sqrt((-2)*log(x1))*cos(TWO_PI*x1);
   y_gauss = sqrt((-2)*log(y1))*sin(TWO_PI*y1);             // metodo di Box-Muller base per gaussiana di media 0 deviazione standard 1 
  x = a + (b-a)*Rand01(); 
   y = max*Rand01(); 
 }
#endif
class acceptreject {
public:
	double Rand();
	~acceptreject();
	acceptreject(funzionebase *, double , double , double );	
private:
	funzionebase* _f;
	double _a;
	double _b;
	double _max;
	Random* s;
	Random* t;
	};

//questo metodo della classa setta i parametri di Random() in modo da avere un generatore di numeri casuali tra 0 e 1, per poi applicare il metodo dell'accept-reject

acceptreject::acceptreject(funzionebase * f, double a, double b,double max) {
 /* initialize random seed: */
srand (time(NULL));
	_a=a;
	_b=b;
	_f=f;
	_max=max;
	s = new Random (rand() % 10 + 1);			// i semi vengono generati casualmente	
	t = new Random (rand() % 10 + 1);			 	
	s->setA(1664525);
	s->setC(1013904223);
	s->setM(pow(2,31));     // setto i valori dei due Random che ho definito dinamicamente
	t->setA(1664525);
	t->setC(1013904223);
	t->setM(pow(2,31));
	}

acceptreject::~acceptreject(){
	delete s;
	delete t;   // distruttori dei valori creati dinamicamente ---> evito memory leak
	}

// applicazione del metodo accept-reject

double acceptreject::Rand(){
	double x, y, Y;
	do {
		x=_a+(_b-_a)*s->Rand01();
		y=_max*t->Rand01();
		Y=_f->eval(x);      // continua a tirare un numero casuale finchè non trovi una y che sia inferiore del massimo valore assunto dalla funzione in quel punto
		} while(y>=Y);
	return x;
	}

double Random::esponenziale(double rate){

   double s;
   s = Rand01();

   return -rate*log(s);

}


double Random::BoxMuller(double mean, double sigma){

   double s = this->Rand01();
   double t = this->Rand01();
   double g = sqrt(-2*log(s))*cos(2*M_PI*t);

   return mean + sigma*g;

}

#endif    //RANDOM_HPP
