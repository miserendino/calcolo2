#include <iostream>
#include <iomanip>
#include <cmath>
#include "lib.hpp"
using namespace std;

int main(int argc, char **argv){
  float a(0.3),b(0.2),c(0.1),d(0.4);
  std::scientific;
  std::cout << "a-b-c=" << (a-b-c) << " a-(b+c)=" << a-(b+c) << " d-c-a=" << (d-c-a)  << endl;
long int tmp(1E15),local(1E16);
  std::cout << "(1E15+1)-1E15=" << (tmp+1)-tmp << "  (1E16+1)-1E16=" << (local+1)-local << std::endl; 
  std::setw(2);
 for(int k=1; k<19; ++k){
double prova=funzione(pow(10,k));
long double prova2=funzione(pow(10,k));
std::cout << "-----------------------" << std::endl;
std::setw(2);
 std::cout << "1E" << k << " " << prova << " " <<  prova2 << std::endl;
 }
// seconda parte dell'esercizio

  double data[4]= {4,7,13,16};
  std::cout << "La media del vettore data è " << calcola_media(data,4) << std::endl;
  std::cout << "La varianza del vettore data è " << calcola_varianza(data,4) << std::endl;
  double data_hugenumber[4]= {4+1E9,7+1E9,13+1E9,16+1E9};
  std::cout << "La varianza del vettore data_hugenumber è " << calcola_varianza(data_hugenumber,4) << std::endl;

  // terza parte dell'esercizi0
  long int prova1=(1E15 + 1 ) - 1E15;
  long int prova2=(1E16 + 1 ) - 1E16;
  long int prova3=(1E17 + 1 ) - 1E17;     

  std::cout << "prova1=(1E15+1)-1E15=" << prova1 << " prova2=(1E16+1)-1E16=" << prova2 << " prova3=(1E17+1)-1E17=" << prova3 << std::endl;
  std::cout << "Con il tipo di dato long int il compilatore inizia an andare in overflow quando raggiungiamo 10E16 " << std::endl;













  return 0;
}

