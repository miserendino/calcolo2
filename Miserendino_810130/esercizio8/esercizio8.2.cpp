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

   Random random(47);

   random.setA(1664525); 
   random.setC(1013904223);
   random.setM(pow(2,31));
  double a,u;
  std::cout << "Inserisci la larghezza in sigma in cui visualizzare l'istogramma: " << std::endl;
  std::cin >> a;
// geenrazione delle due funzioni gaussiane a partire dalla classe funzionebase
// apppicazione del metodo accept reject con i vari argomenti passati al costruttore

   TH1F h("Istogramma1","Distribuzione gaussiana",100,-a*1.,a*1.);
   TH1F g("Istogramma2","Distribuzione esponenziale",250,0,0.1*a);

   for(unsigned int i=0; i<100000; i++){
      u = random.BoxMuller(0.,1.);
      h.Fill(u);
      u = random.esponenziale(0.1);
      g.Fill(u);
   }


   TCanvas *c1 = new TCanvas("c1","c1");
   TCanvas *c2 = new TCanvas("c2","c2");

   c1->cd();
   h.Draw();

   c2->cd();
   g.Draw();
   
   app.Run(true);
    c1->Close();
    c2->Close();
   return 0;
   }
