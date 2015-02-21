#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "integratore.hpp"
#define M_PI 3.14159265358979323846

using namespace std;

int main(int argc, char**argv){
	if(argc!=2){
		std::cerr << "Istruzioni: "<< argv[0]<< " precisione richiesta" << endl;
		return -1;
	}

	double a=0;
	double b=M_PI;

	double precisione=atof(argv[1]);
	if(precisione<=1e-15){
		std::cerr << "La precisione richiesta e` inferiore a quella minima tollerata dalla macchina (1e-15). Inserire un valore maggiore." << endl;
		return -1;
	}

	funzionebase* s = new seno();
	integral* integrale=new integral(a, b, precisione, s);

	std::cout << "Il valore dell'integrale della funzione seno tra " << a << " e " << b << " con precisione " << precisione << " vale " << setprecision(precisione) << integrale->trapezi() << endl;

	delete s;
	delete integrale;

	return 0;
}
