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
  oscillatore *osc = new oscillatore(1.);		// oscillatore armonico con pulsazione unitaria
  double tmax=70.;
  TGraph *pos = new TGraph();
  TGraph *errore = new TGraph();
  int nstep = static_cast<int>(tmax/h+0.5);
  double t=0.;
  vettorelineare x(2);
  x.setcomponent(0,0.);
  x.setcomponent(1,1.);
  for(auto step=0; step < nstep; ++step){
  	pos->SetPoint(step,t,x.getcomponent(0));
  	errore->SetPoint(step,t,x.getcomponent(0) - sin(t));

  	x = rk.passo(t,x,h,osc);
  	t = t+h;
  } 

TCanvas c1;
c1.Divide(1,2);
c1.cd(1); pos->Draw("AL");
pos->GetXaxis()->SetTitle("t[s]");
pos->GetYaxis()->SetTitle("x[m]");
c1.cd(2);	errore->Draw("AL");
errore->GetXaxis()->SetTitle("t[s]");
errore->GetYaxis()->SetTitle("errore[m]");
App.Run();


  delete pos;
  delete errore;
  delete osc;
  return 0;
}


