#include "funzione.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#ifndef __INTEGRATORE_HPP__
#define __INTEGRATORE_HPP__

class integral {
	public:
		integral(double a, double b, funzionebase *f);
		double midpoint(int nstep);
		//double simpson(int nstep);
	private:
		double Ma, Mb, Msum, Mh, Mintegral;
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

#endif
