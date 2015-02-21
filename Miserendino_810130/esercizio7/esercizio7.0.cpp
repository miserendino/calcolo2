#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "integratore.hpp"
using namespace std;

int main (int argc, const char **argv){
	if (argc!=2){
		cout<<"Errore, digita: "<<argv[0]<<" <nstep>"<<endl;
		return -1;
	}

	double a=0.;
	double b=M_PI;
	int nstep=atoi(argv[1]);

	funzionebase *s=new seno();
	integral *integrale=new integral(a,b,s);

	cout<<setprecision(12)<<integrale->midpoint(nstep)<<endl;

	return 0;
}
