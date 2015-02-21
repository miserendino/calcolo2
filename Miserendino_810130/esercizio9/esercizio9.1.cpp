#include <random>
#include <iostream>
#include "lib.hpp"
#include "TCanvas.h"
#include "TApplication.h"
#include "TH2D.h"
#define N 10000
using namespace std;

TApplication myapp("app",NULL,NULL); // crea l'interfaccia grafica
int main(){
  double theta1[N];
  EsperimentoPrisma foo;
  TCanvas tela1;
   TH1D histo("theta1","theta1",100,foo.Gettheta1in()-1E-3, foo.Gettheta1in()+1E-3); // crea l'istogramma
   for (int i=0;i<N; ++i){
     foo.Esegui();
   histo.Fill(foo.Gettheta1()); // riempe l'istogramma
   }
   histo.GetXaxis()->SetTitle("X"); // da il nome all'asse X
   histo.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo.Draw();
   myapp.Run(true);
   tela.Close();
   return 0;
   }
