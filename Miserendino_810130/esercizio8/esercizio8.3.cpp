//Verifica del Teorema del Limite Centrale

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "random.hpp"

using namespace std;

int main (int argc, char**argv){
   
   if(argc!=3){
      cerr << "Non hai inserito informazioni sufficienti (numero di elementi della serie ed elementi per la somma)." << endl;
      return -1;
    }


   int ng = atoi(argv[1]);
   int es = atoi(argv[2]);

   int i,j;
   double u, median, medias, varn, vars, t;
   double* v = new double [ng];
   double* vsomma = new double [ng-(ng%es)];

   Random random(21);

   random.setA(1664525); 
   random.setC(1013904223);     // assegno i vari numeri da dare in pasto al generatore di numeri casuali
   random.setM(pow(2,31));


   TApplication app("app",0,0);


   TH1F h("Istogramma1","Distribuzione dei numeri generati",100,0,1);
   TH1F g("Istogramma2","Distribuzione delle somme",100,0.,es);




//Creazione della serie di numeri

   for(i=0; i<ng; i++){
      u = random.Rand01();
      h.Fill(u);
      v[i] = u;
   }

//Calcolo della media e varianza della serie di numeri

   t = 0.;
   for(i=0; i<ng; i++)
      t = t + v[i];
   median = t / ng;
   
   cout << endl << "Media serie numeri : " << median << endl;


   t = 0.;
   for(i=0; i<ng; i++)
      t = t + pow( v[i],2 );
   varn = (t/ng) - median*median;

   cout << "Varianza serie numeri : " << varn << endl << endl;



//Creazione della serie delle somme


   i = 0;

   for(j=0; j<(ng-(ng%es))/es; j++){
   
      vsomma[j] = 0.;
      for(unsigned int k=0; k<es; k++, i++)
         vsomma[j] = vsomma[j] + v[i];
      g.Fill(vsomma[j]);

   }

//Calcolo della media e varianza della serie delle somme

   t = 0.;
   for(i=0; i<(ng-(ng%es))/es; i++)
      t+=vsomma[i];

   medias = t / ( (ng-(ng%es))/es );
   
   cout << endl << "Media serie somme : " << medias << endl;


   t = 0.;
   for(i=0; i<(ng-(ng%es))/es; i++)
      t+=pow( vsomma[i],2 );
   vars = (t/((ng-(ng%es))/es)) - medias*medias;

   cout << "Varianza serie somme : " << vars << endl << endl;

   delete[] v;
   delete[] vsomma;



   TCanvas *c1 = new TCanvas("c1","c1", 1200, 600);

   c1->Divide(2,1);

   c1->cd(1);
   h.Draw();
 
   c1->cd(2);
   g.Draw();


   app.Run();
   return 0;
   
}
