#include <iostream>
#include "vettore.hpp"

int main(int argc,char **argv){
  vettoredati foo(12);
  foo.caricavett();
  foo.print();
  foo.quicksort();
  foo.print("ciao");
  foo.media();
  foo.print();
  foo.varianza();
  foo.print();
  foo.deviazione_standard();
  foo.print(); 
  foo.mediana();
  foo.print();
  return 0;
}
