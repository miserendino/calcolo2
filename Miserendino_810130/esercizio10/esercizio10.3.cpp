#include <iostream>
#include "vettorelineare.hpp"
#include "vettore.hpp"
#include "equazionedifferenziale.hpp"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include <sstream>


int main(int argc, char**argv) {
if (argc =! 2){
	std::cerr << "Usage: " << argv[0] << " passo di integrazione" << std::endl;
	return -1;
}
	istringstream ss(argv[1]);
  double h;
  if (!(ss >> h)){
    std::cerr << "Invalid number " << argv[1] << '\n';
  exit(-1);
  }
  TApplication App("App",0,0);
  runge_kutta rk;
  pendolo *p = new pendolo(1.);
  TGraph *pos = new TGraph();
  TGraph *graph2 = new TGraph();
  double tmax = 70.;
  int nstep = static_cast<int>(tmax/h+0.5);
  double t=0.;
  vettorelineare x(2);
  x.setcomponent(0,0.);
  x.setcomponent(1,1.);
  for(auto step=0; step < nstep; ++step){
  	pos->SetPoint(step,t,x.getcomponent(0));
    x = rk.passo(t,x,h,p);
  	t = t+h;
  } 

// calcolo del periodo
double v;

for(auto i=1;i<30;++i){
  double A=0.1*i;
    t=0;
     h=0.1;
     x.setcomponent(0,-A);
     x.setcomponent(1,0.);
while(x.getcomponent(1)>=0){
  v = x.getcomponent(1);
  x = rk.passo(t,x,h,p);
  t = t+h;
}
  double T = t - (h*x.getcomponent(1)/(x.getcomponent(1)-v));
 T = T*2;
 graph2->SetPoint(i,A,T);


}

TCanvas c1("esercizio 10.3","Pendolo");

pos->GetXaxis()->SetTitle("t[s]");
pos->GetYaxis()->SetTitle("x[m]");
pos->Draw("ALP");
TCanvas c2("esercizio 10.3","Periodo");
graph2->GetXaxis()->SetTitle("A[m]");
graph2->GetYaxis()->SetTitle("t[s]");
graph2->Draw("ALP");
App.Run();


c1.Close(),c2.Close();
delete p;
delete graph2;
delete pos;
  return 0;
}


