#include <random>
#include <iostream>
#include "lib.hpp"
#include "TCanvas.h"
#include "TApplication.h"
#include "TH2D.h"
#define N 10000

int main(int argc, char **argv){
double theta1[N],theta2[N],theta0[N];
TApplication myapp("app",NULL,NULL); // crea l'interfaccia grafica
  TCanvas tela1;
EsperimentoPrisma foo;
   TH2D histo1("histo", "Correlazione the theta1 e theta2", 10, foo.Gettheta1in()-1, foo.Gettheta1in()+1 , 10 ,  foo.Gettheta2in()-1,  foo.Gettheta2in()+1);
for(int i=0; i< N;++i){
  foo.Esegui();
theta1[i]=foo.Gettheta1();
theta0[i]=foo.Gettheta0();
theta2[i]=foo.Gettheta2();
histo1.Fill(theta1[i],theta2[i]);
#ifdef DEBUG
std::cout << theta1[i] << '\t' << theta2[i] << std::endl;
#endif
}
   histo1.Draw("SURF3");
   TCanvas tela2("c1","c1",1200,400);
   tela2.Divide(3,1);     // diveide la seconda canvas in tre parti distinte
  tela2.cd(3);            // sposta il cursore sulla prima parte della canvas
   TH1D histo3("theta2","theta2",100,foo.Gettheta2in()-1E-3, foo.Gettheta2in()+1E-3); // crea l'istogramma
   for (int i=0;i<N; ++i){
   histo3.Fill(theta2[i]); // riempe l'istogramma
   }
   //histo3.GetXaxis()->SetTitle("X"); // da il nome all'asse X
   //histo3.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo3.Draw();
  tela2.cd(2);            // sposta il cursore sulla prima parte della canvas
   TH1D histo2("theta1","theta1",100,foo.Gettheta1in()-1E-3, foo.Gettheta1in()+1E-3); // crea l'istogramma
   //histo2.GetXaxis()->SetTitle("X"); // da il nome all'asse X
   //histo2.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   for (int i=0;i<N; ++i){
   histo2.Fill(theta1[i]); // riempe l'istogramma
   }
   histo2.Draw();
   tela2.cd(1);
   TH1D histo4("theta0","theta0",100,foo.Gettheta0in()-1E-3, foo.Gettheta0in()+1E-3); // crea l'istogramma
   for (int i=0;i<N; ++i){
   histo4.Fill(theta0[i]); // riempe l'istogramma
   }
   //histo3.GetXaxis()->SetTitle("X"); // da il nome all'asse X
   //histo3.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo4.Draw();
   
   myapp.Run(true);
   tela1.Close();
   tela2.Close();
  return 0;
}
