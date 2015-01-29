#include <iostream>
#include "funzione.hpp"
#include <utility>
using namespace std;

int main(){
	double a, b, prec;

	cout<<"Inserisci i due estremi dell'intervallo:"<<endl;
	cin >>a;
	cin >>b;

	if (a>b)
		swap(a,b);

	cout<<"L'intervallo di ricerca è ["<<a<<","<<b<<"]"<<endl;
	cout<<"Inserisci la precisione:"<<endl;
	cin >>prec;

	funzionebase *f=new parabola (3.,5.,-2.);

	ricerca x(a,b,prec);
	x.cercazeri(a,b,f);

	x.print();
delete f;
	return 0;
}
