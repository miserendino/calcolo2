#include <random>
#include <iostream>
#include "lib.hpp"
#include "TCanvas.h"
#include "TApplication.h"
#include "TH2D.h"
#define N 10000

int main(int argc, char **argv){
double theta1[N],theta2[N];
TApplication myapp("app",NULL,NULL); // crea l'interfaccia grafica
  TCanvas tela;
EsperimentoPrisma foo;
   TH2D histo("histo", "titolo", 10, foo.Gettheta1in()-1, foo.Gettheta1in()+1 , 10 ,  foo.Gettheta2in()-1,  foo.Gettheta2in()+1);
for(int i=0; i< N;++i){
  foo.Esegui();
theta1[i]=foo.Gettheta1();
theta2[i]=foo.Gettheta2();
histo.Fill(theta1[i],theta2[i]);
#ifdef DEBUG
std::cout << theta1[i] << '\t' << theta2[i] << std::endl;
#endif
}
   histo.Draw("SURF3");
   myapp.Run(true);
   tela.Close();

  return 0;
}
