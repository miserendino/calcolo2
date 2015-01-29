#ifndef RANDOM
#define RANDOM
using namespace std;
#include <cmath>
#define TWO_PI 6.2831853071795864769252866


class Random{

  public:
    Random(unsigned int seed){ _seed=seed;}
    void setA(unsigned int a){ _a=a; }
    void setC(unsigned int c){ _c=c; }
    void setM(unsigned int m){ _m=m; }
    double Rand();
    double Rand01();
    void Randgauss(double a,double b,double max);
  private:
    unsigned int _a;
    unsigned int _m;
    unsigned int _c;
    unsigned int _seed;
};

double Random::Rand(){
  double risultato=((_a*_seed+_c)%_m);
  _seed=risultato;
  return risultato;
}

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
#endif
