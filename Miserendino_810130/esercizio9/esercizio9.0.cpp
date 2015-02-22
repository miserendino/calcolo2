#include <random>
#include <iostream>
#include "esperimentoprisma.hpp"
#include "TCanvas.h"
#include "TApplication.h"
#include "TH2D.h"
#define N 10000

int main(int argc, char **argv){
double dm1[N],dm2[N];
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
   histo3.GetXaxis()->SetTitle("X[rad]"); // da il nome all'asse X
   histo3.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo3.Draw();
  tela2.cd(2);            // sposta il cursore sulla prima parte della canvas
   TH1D histo2("theta1","theta1",100,foo.Gettheta1in()-1E-3, foo.Gettheta1in()+1E-3); // crea l'istogramma
   histo2.GetXaxis()->SetTitle("X[rad]"); // da il nome all'asse X
   histo2.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   for (int i=0;i<N; ++i){
   histo2.Fill(theta1[i]); // riempe l'istogramma
   }
   histo2.Draw();
   tela2.cd(1);
   TH1D histo4("theta0","theta0",100,foo.Gettheta0in()-1E-3, foo.Gettheta0in()+1E-3); // crea l'istogramma
   for (int i=0;i<N; ++i){
   histo4.Fill(theta0[i]); // riempe l'istogramma
   }
   histo4.GetXaxis()->SetTitle("X[rad]"); // da il nome all'asse X
   histo4.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo4.Draw();
   // definisco un altra tela per i dm
  TCanvas tela3("c2","c2",1200,400);
  tela3.Divide(3,1);
  tela3.cd(1);
   // calcolo dei residui per dm1,2
      TH2F corrdm12("corrdm12","Residui dm1,2",100,-0.002,0.003,100,-0.002,0.003);
// *******************************************************************************************
   TH1D histo5("dm1","dm1",100,(foo.Gettheta1in()-foo.Gettheta0in())-1E-3,(foo.Gettheta1in()-foo.Gettheta0in())+1E-3); // crea l'istogramma
// *******************************************************************************************
   TH1D n1("n1", "Distribuzione di n1", 100, -0.001, 0.001); 
   TH1D n2("n2", "Distribuzione di n2", 100, -0.001, 0.001);
   TH2F corrn12("corrn12","Residui n1,2",100,-0.001,0.001,100,-0.001,0.001);
// *******************************************************************************************
double u,v;
   for (int i=0;i<N; ++i){
     foo.Esegui();
     foo.Analizza();
      u = foo.Getn1() - foo.Getn1in();
      n1.Fill(u);
      v = foo.Getn2() - foo.Getn2in();
      n2.Fill(u);
      corrn12.Fill(u,v);
  dm1[i]=foo.Getdm1();
  dm2[i]=foo.Getdm2();
   corrdm12.Fill(dm1[i],dm2[i]);
   histo5.Fill(dm1[i]); // riempe l'istogramma
#ifdef DEBUG
   std::cout << dm1[i] <<  std::endl;
   std::cout << u << " " << v << std::endl;
#endif
   }
   histo5.GetXaxis()->SetTitle("X[rad]"); // da il nome all'asse X
   histo5.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo5.Draw();
   // dm2 
  tela3.cd(2);
   TH1D histo6("dm2","dm2",100,(foo.Gettheta2in()-foo.Gettheta0in())-1E-3,(foo.Gettheta2in()-foo.Gettheta0in())+1E-3); // crea l'istogramma
   for (int i=0;i<N; ++i){
   histo6.Fill(dm2[i]); // riempe l'istogramma
#ifdef DEBUG
   std::cout << dm2[i] <<  std::endl;
#endif
   }
   histo6.GetXaxis()->SetTitle("X[rad]"); // da il nome all'asse X
   histo6.GetYaxis()->SetTitle("Y"); // da il nome all'asse Y
   histo6.Draw();
   
   corrdm12.GetXaxis()->SetTitle("Discrepanza dm1 [rad]");
   corrdm12.GetYaxis()->SetTitle("Discrepanza dm2 [rad]");
   tela3.cd(3);
   corrdm12.Draw();
   TCanvas tela4("c3","c3",1200,400);
  tela4.Divide(3,1);


tela4.cd(1);
n1.Draw();
tela4.cd(2);
n2.Draw();
tela4.cd(3);
corrn12.Draw();



   myapp.Run(true);
   tela1.Close();
   tela2.Close();
   tela3.Close();
  return 0;
}
