#include <iostream>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "integratore.hpp"
#define M_PI 3.14159265358979323846
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

  std::ofstream stampa;
	stampa.open("tabella.txt");

	cout << "Dopo " << nstep << " passi la stima dell'integrale della funzione sin(x) tra " << a << " e " << b << " vale " << integrale->simpson(nstep) << endl;
	//valutazione dell'errore all'aumentare del numero di passi
	stampa << "Metodo di integrazione alla Simpson: valutazione dell'errore al crescere del numero di passi" << endl;
	stampa << setw(8) << "nstep" << setw(15) << "errore" << endl;
	for(int n=10; n<pow(2, 15)*10 && n<INT_MAX; n=n*2)
		stampa << setw(8) << n << setw(15) << abs(2-integrale->simpson(n)) << endl;
	cout << "Il file tabella.txt contiene la tabella con l'errore al variare del numero dei passi." << endl; 

	stampa.close();
	delete s;
	delete integrale;


	return 0;
}
