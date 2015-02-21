#include<iostream>
#include<cmath>
#include"TCanvas.h"
#include"TGraph.h"
#include"TApplication.h"
#include"TGraphErrors.h"
#include <algorithm>
#include<fstream>
#include "TAxis.h"
#include <iomanip>
#include "TMinuit.h"
#include<vector>
#define NUMBER_OF_FILE 16   //sono i file i n ogni colonna

/************************************************************************************
Programma che plotta su una Tcanvas le prestazioni del mio calcolatore rispetto all'algortimo selectionsort sequenziale
***********************************************************************************/

int main(int argc,char *argv[]){
TApplication app("App",0,0);
double xcoord[NUMBER_OF_FILE];
double ycoord[NUMBER_OF_FILE];
  

std::ifstream input("risultati.dat");

for(int i=0;i<NUMBER_OF_FILE;i++){
  input >> xcoord[i] >> ycoord[i];
}
input.close();
#ifdef DEBUG
std::cout << "Values charged in the TGraph :" << std::endl;
std::cout << "X \t \t Y " << std::endl;  
for(int i=0;i<NUMBER_OF_FILE;++i){
  
std::cout << xcoord[i] << "\t" << ycoord[i] << std::endl;
}
#endif
TCanvas c1;
input.close();
TGraph my_gr(NUMBER_OF_FILE,xcoord,ycoord);
my_gr.Draw("A*");
my_gr.SetTitle("Prestazioni di un Intel(R) Pentium(R) CPU B980 @ 2.40GHz selection sort sequenziale");
my_gr.GetXaxis()->SetTitle("X)");
my_gr.GetYaxis()->SetTitle("Y");
my_gr.Fit("pol2");


app.Run(true);
c1.Close();
return 0;
}
