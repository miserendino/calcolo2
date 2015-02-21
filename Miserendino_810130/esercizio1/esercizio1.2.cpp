#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char **argv){
  if (argc < 3){
    cout << "Usage ./esercizio1.2 <input file> <output file>" << endl;
   return 1;
  }
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
    unsigned int number_of_elements;   // il numero degli elementi sono il primo numero di imput del file!!!
    input >> number_of_elements;
    std::cout << "Numero degli elementi caricati nel vettore " << number_of_elements << std::endl;
 double v[number_of_elements];
   for(unsigned int num=0; num<number_of_elements; ++num)
   {
    input >> v[num];
//     #ifdef DEBUG
    std::cout << "Elemento numero " << (num+1) << " : " <<  v[num] << std::endl;
//    #endif
  }
   input.close();
 for(unsigned int i=0; i<number_of_elements;++i){
   if(i%2==0){
  long double pippo(v[i+1]);         // se il  numero dell'elemento del vettore e' pari scambio l'elemento con il successivo
#ifdef DEBUG 
  std::cout << pippo << endl;
#endif
  v[i+1]=v[i];
    v[i]=pippo;
   }
   else continue;
 }
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
  ofstream output;
  output.open(argv[2]);
  output << "Ecco gli elementi del vettore scambiati" << endl;
    if(output.is_open()){
      for(int lcl=0; lcl<number_of_elements; ++lcl){
        output << v[lcl] << '\n';
      }
    }
   output.close();
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
