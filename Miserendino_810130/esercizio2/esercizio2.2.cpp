#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "lib.hpp"
using namespace std;

int main(int argc, char **argv){
  unsigned int conta=0;
  static unsigned int conta2=0;
  if (argc < 3){
    cout << "Usage ./esercizio2.2 <input file> <number of data>" << endl;
   return 1;
  }
  istringstream ss(argv[2]);
  unsigned int number_of_data;
  ss >> number_of_data;
ifstream input;
/*
double tmp;
input >> tmp;
    while(!input.eof())
  {
   i++;
     input >> tmp;
 
    #ifdef DEBUG
    std::cout << tmp << std::endl;
    #endif
    */
input.open(argv[1]);
 double v[number_of_data];
   for(unsigned int num=0; num<number_of_data; ++num)
   {
    input >> v[num];
//     #ifdef DEBUG
//  std::cout << "Elemento numero " << (num+1) << " : " <<  v[num] << std::endl;
//    #endif
  }
   input.close();
 ofstream output;
  output.open("before.dat");
    if(output.is_open()){
      for(int lcl=0; lcl<number_of_data; ++lcl){
        output << v[lcl] << '\n';
      }
    }
   output.close();
#if 0
 for(unsigned int i=0; i<number_of_data;++i){
   if(i%2==0){
  long double pippo(v[i+1]);         // se il  numero dell'elemento del vettore e' pari scambio l'elemento con il successivo
 
  std::cout << pippo << endl;

   }
   else continue;
 }
#endif
selectionsort(v,number_of_data); 
  output.open("after.dat");
    if(output.is_open()){
      for(int lcl=0; lcl<number_of_data; ++lcl){
        output << v[lcl] << '\n';
      }
    }
   output.close();
   /*
   //swappare tutti gli elementi dell'array
   for(unsigned int local=0; local<number_of_elements; ++local){
     swap(v[local],v[(local+1)*2]);
   }
   std::cout << "Ecco i numeri ordinati" << std::endl; 
   for(unsigned int local=0; local<number_of_elements; ++local){
     std::cout << v[local] << '\n';
   }
   */
   // scrivo il vettore ordinato in questo modo in un altro file
  #if 0 
   std::cout << "Ecco il vettore di numeri scambiati a due a due" << std::endl;
   for(int tmp=0; tmp<i; ++tmp){
    double local=v[tmp];
    v[tmp]=v[tmp+1];
    v[tmp+1]=local;
    std::cout << v[tmp] << endl;
   }
#endif
  return 0;
}
