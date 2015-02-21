#include "funzione.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>
using namespace std;
#ifndef __INTEGRATORE_HPP__
#define __INTEGRATORE_HPP__

class integral {
	public:
		integral(double a, double b, funzionebase *f);
		integral(double , double , double , funzionebase* );
		double midpoint(int nstep);
		double trapezi();
		double simpson(int nstep);
	private:
		double Ma, Mb, Msum, Mh, Mintegral,Mprecision;
		int Msign;
		funzionebase *Mintegrand;
};


integral::integral(double a,double b,funzionebase *f){
	Mintegrand=f;
	Ma=min(a,b);
	Mb=max(a,b);
	if (a>b) Msign=-1;
	else Msign=1;
}


integral::integral(double a, double b, double prec, funzionebase* f){
	Mintegrand=f;
	Ma=min(a,b);
	Mb=max(a,b);
	if(a>b) Msign=-1;
	else Msign=1;
	Mprecision=prec;
}

double integral::midpoint(int nstep){
	Msum=0.;
	Mh=(Mb-Ma)/nstep;
	for (int i=0; i<nstep; i++){
		double x=Ma+(i+0.5)*Mh;
		Msum +=Mintegrand->eval(x);
	}
	Mintegral=Msign*Msum*Mh;
	return Mintegral;
}

double integral::simpson(int nstep){
  if(nstep%2!=0){
    std::cout << "Il numero di passi richiesto non è pari (come prevede il metodo Simpson)." << std::endl;
  return -1;
  }
Msum=0.;
Mh=(Mb-Ma)/nstep;
  for(int k=1; k<nstep-2; k=k+2){
double x=Ma+k*Mh;
    Msum+=4./3.*Mintegrand->eval(x)+2./3.*Mintegrand->eval(x+Mh);
  }
    Msum+=4./3.*Mintegrand->eval(Mb-Mh)+1./3.*(Mintegrand->eval(Ma)+Mintegrand->eval(Mb));
      Mintegral=Msign*Msum*Mh;
        return Mintegral;
}

double integral::trapezi(){
	double delta=INT_MAX;
	for(unsigned int k=0; delta>Mprecision; k++){
		if(k==0){
			Msum=(Mintegrand->eval(Ma)+Mintegrand->eval(Mb))/2.;
			Mintegral=Msign*Msum*(Mb-Ma);
		}
		else{
			Mh=(Mb-Ma)/(pow(2, k-1));
			double sum_f, x;
			double x_1=Ma+Mh/2.;
			for(unsigned int i=1; i<=(pow(2, k-1)); i++){
				if(i==1) sum_f=Mintegrand->eval(x_1);
				else{
					if(i==(pow(2, k-1))) x=Mb-Mh/2.;
					else x=x_1+(i-1)*Mh;
					sum_f=sum_f+Mintegrand->eval(x);
				}
			}
			Msum=Msum+sum_f;
			double I_new=Msign*Msum*(Mb-Ma)/(pow(2, k));
			delta=abs(I_new-Mintegral);
			Mintegral=I_new;
		}
	}
	return Mintegral;
}


#endif
