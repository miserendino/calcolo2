#include "random.hpp"
#include <iostream>
#include <TCanvas.h>
#include <TApplication.h>
#include <TH1D.h>
#include <TGraphErrors.h>
#include <cstdlib>

TApplication myapp("app",NULL,NULL); // crea l'interfaccia grafica
int main(int argc, char *argv[]){
  TCanvas tela; // crea (e apre) la finestra grafica
  TH1D histo("Random numbers","Random",100,0.0,1.0); // crea l'istogramma
  Random rand(4);
  rand.setA(1664525);
  rand.setC(1013904223);
  rand.setM(2E31);
  
 for(int i=0; i<100000; ++i){
  double tmp=rand.Rand01();
  std::cout << tmp << std::endl;
  histo.Fill(tmp); // riempe l'istogramma
 }
 histo.GetXaxis()->SetTitle("X"); // da il nome all'asse X
 histo.GetYaxis()->SetTitle("Y"); // da il nome all'asse X
 histo.Draw(); // disegna l'istogramma
 myapp.Run(true); // runna l'interfaccia grafica dando all'utente la possibilita' di intervenire
 tela.Close(); // chiude la finestra

  return 0;
}
