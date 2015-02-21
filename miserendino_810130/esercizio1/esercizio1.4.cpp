#include <iostream>
#include <string>
#include "lib2.hpp"
#include <fstream>
using namespace std;

int main(int argc,char *argv[]){
double prova=0;
double v1=0,v2=0;
unsigned int dim;
double tmp=0;
double num;
unsigned int expr=0;
std::ifstream input;
  std::cout << "Specificare che tipo di operazione si intende compierei [1=num/2=vetR2/3=vetRn]" << std::endl;
  std::cin >> expr;
  switch (expr)
  {
  case 1:
       std::cout << "inserire il numero di cui si vuole calcolare il modulo" << std::endl;
       std::cin >> num;
  prova=calcola_modulo(num);
         std::cout << "il modulo del numero " << num << " e' " << prova << std::endl;
         break;
  case 2:
     std::cout << "inserire i due elementi del punto di cui si vuole calcolare la norma" << std::endl;
      cin >> v1 >> v2;
     tmp=calcola_modulo(v1,v2);
     std::cout << "la norma del vettore e' " << tmp << std::endl;
     break;
  case 3:
       input.open("dati.dat");
        input >> dim;  
     double b[100];       
     for(int i=0; i<dim; ++i){
          input >> b[i];
#ifdef DEBUG 
          std::cout <<  b[i] << std::endl;
#endif
     }
        prova=calcola_modulo(b,dim);
        std::cout << "la norma del punto e' " << prova << std::endl;
        input.close();
      break;      
  default: 
     cout << "la direttiva inserita non e' valida: si prega di inserire una delle tre direttive" << std::endl;    
  }
       return 0;
}


