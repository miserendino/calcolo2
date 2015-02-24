#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "funzione.hpp"
#include "integratore.hpp"

using namespace std;

int main (int argc, char**argv){

   double raggio = 1.;
   int dim = 3;
   double ris;
   int l = 100;
   double somma,media,sommadev,dev;

   TApplication app("app",0,0);

   TH1F a("Sn/Rn 1", "10000 punti", 25, 0.512, 0.535);
   TH1F b("Sn/Rn 2", "40000 punti", 25, 0.518, 0.53);
   TH1F c("Sn/Rn 3", "90000 punti", 25, 0.518, 0.53);
   TH1F d("Sn/Rn 4", "160000 punti", 25, 0.518, 0.53);

   funzionebase *f = new caratteristica(raggio);         // definizione di una funzione caratteristica con raggio uguale a 1
   integral *integrale = new integral(-raggio,raggio,f); 


   integrale->setdim(dim);

//10000 punti
   somma = 0.;
   sommadev = 0.; 

   for (unsigned int i=0; i<l; i++){

      ris = (integrale->montecarlo(10000)) / pow(2*raggio,dim); // = Sn/Rn
      somma = somma + ris;
      a.Fill(ris);
      sommadev = sommadev + ris*ris;

   }
   
   media = somma/l;
   dev = sqrt((sommadev/l) - media*media);

   cout << endl << "  Con 10000 punti e ripetendo " << l << " volte ho Sn/Rn = " << setprecision(4) << media << " e RMS =  " << setprecision(2) << dev;
   cout << endl;

   //40000 punti
   somma = 0.;
   sommadev = 0.; 

   for (unsigned int i=0; i<l; i++){

      ris = (integrale->montecarlo(40000)) / pow(2*raggio,dim); // = Sn/Rn
      somma = somma + ris;
      b.Fill(ris);
      sommadev = sommadev + ris*ris;

   }

   media = somma/l;
   dev = sqrt((sommadev/l) - media*media);

   cout << endl << "  Con 40000 punti e ripetendo " << l << " volte ho Sn/Rn = " << setprecision(4) << media << " e RMS =  " << setprecision(2) << dev;
   cout << endl;

//90000 punti
   somma = 0.;
   sommadev = 0.; 

   for (unsigned int i=0; i<l; i++){

      ris = (integrale->montecarlo(90000)) / pow(2*raggio,dim); // = Sn/Rn
      somma = somma + ris;
      c.Fill(ris);
      sommadev = sommadev + ris*ris;

   }

   media = somma/l;

   dev = sqrt((sommadev/l) - media*media);

   cout << endl << "  Con 90000 punti e ripetendo " << l << " volte ho Sn/Rn = " << setprecision(4) << media << " e RMS =  " << setprecision(2) << dev;
   cout << endl;

//160000 punti
   somma = 0.;
   sommadev = 0.; 

   for (unsigned int i=0; i<l; i++){

      ris = (integrale->montecarlo(160000)) / pow(2*raggio,dim); // = Sn/Rn
      somma = somma + ris;
      d.Fill(ris);
      sommadev = sommadev + ris*ris;

   }

   media = somma/l;

   dev = sqrt((sommadev/l) - media*media);

   cout << endl << "  Con 160000 punti e ripetendo " << l << " volte ho Sn/Rn = " << setprecision(4) << media << " e RMS =  " << setprecision(2) << dev;
   cout << endl << endl;

 cout << endl << "Calcolo di Sn/Rn a diverse dimensioni" << endl;

   for(dim=2; dim<=5; dim++){

      integrale->setdim(dim);

      ris = (integrale->montecarlo(500000)) / pow(2*raggio,dim); // = Sn/Rn

      cout << endl << "  Sn/Rn (a dim = " << dim << " ) : " << setprecision(5) << ris << endl;
      cout << "  Sn/Rn esatto (a dim = " << dim << " ) : " << setprecision(5) << (pow(M_PI,dim/2.)/(tgamma(dim*0.5+1)))/pow(2.,dim);
      cout << endl;   

   }

   cout << endl;

   delete f;
   delete integrale;

   TCanvas *c1 = new TCanvas("c1","c1",800,800);
   c1->Divide(2,2);

   a.SetTitle("Dimensione 3, 10000 punti");
   b.SetTitle("Dimensione 3, 40000 punti");
   c.SetTitle("Dimensione 3, 90000 punti");
   d.SetTitle("Dimensione 3, 160000 punti");

   c1->cd(1);
   a.Draw();

   c1->cd(2);
   b.Draw();

   c1->cd(3);
   c.Draw();

   c1->cd(4);
   d.Draw();

   app.Run();
   c1->Close();

   return 0;
}
