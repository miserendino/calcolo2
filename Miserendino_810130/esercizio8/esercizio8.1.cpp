#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "random.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
   
  TApplication app("app",0,0);

  double a;
  std::cout << "Inserisci la larghezza in sigma in cui visualizzare l'istogramma: " << std::endl;
  std::cin >> a;
// geenrazione delle due funzioni gaussiane a partire dalla classe funzionebase
	gaussiana g1(1.,1.);          // gaussiana(media, varianza)
	gaussiana g2(0.,2.);
// apppicazione del metodo accept reject con i vari argomenti passati al costruttore
	acceptreject r1 (&g1, 1.-a,1.+ a, 1.);      // acceptreject(funzione,estremo inferiore,estremo superiore,max della f)
	acceptreject r2 (&g2, -2.*a,2*a, 1.);


	TH1F h1("Istogramma1","mu=sigma=1",100,1.-a,1.+a);
	TH1F h2("Istogramma2","mu=0, sigma=2",100,-2.*a,2*a);

	double n;
	for (int i=0; i<1000000; i++){
		n=r1.Rand();
		h1.Fill(n);
		n=r2.Rand();
		h2.Fill(n);
		}

	TCanvas *c1 = new TCanvas ("c1","c1");
	c1->cd();
	h1.Draw();

	TCanvas *c2 = new TCanvas ("c2","c2");
	c2->cd();
	h2.Draw();


	app.Run();
  c1->Close();
  c1->Close();

	return 0;
	}
