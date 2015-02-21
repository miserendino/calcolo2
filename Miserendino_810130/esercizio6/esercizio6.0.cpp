#include <iostream>
#include "vettore.hpp"

int main(int argc, char **argv){
    vettore *a = new vettore(10);       //occhio ai memory leak
#ifdef DEBUG
    std::cout << a << std::endl;
    std::cout << a->getsize() << std::endl;
#endif 
    for (unsigned int i=0; i<a->getsize(); ++i){
      a->setcomponent(i,((10.)*i));
    }
      std::cout << "vettore a iniziale" << std::endl;  
  for(unsigned int i=0; i<(a->getsize()); ++i){
    std::cout << i << ") " << a->getcomponent(i) << std::endl;
  }
    if ( (a->getsize()) >0 ){
      vettore b=(*a);         //vettore b copia di a
      std::cout << "vettore b iniziale" << std::endl;
      for(unsigned int i=0; i<b.getsize(); ++i){
        std::cout << i << ") " << b.getcomponent(i) << std::endl;
      }
        //modifichiamo il vettore b e verifichiamo che le modifiche siano 
        //corrette
    for(unsigned int i=0; i<b.getsize(); ++i){
      b.setcomponent(i,9.*i);
      std::cout << "vettore b modificato:" << i << ") " << b.getcomponent(i) << std::endl;
    }
    }
  //stampiamo il nuovo vettore a:
  //il risultato e' quello che ci aspettiamo?
//#if 0
    std::cout << "vettore a: " << std::endl;
    for(unsigned int i=0; i<a->getsize(); ++i){
      std::cout << i << ") " << a->getcomponent(i) << std::endl;
    }
      std::cout << "delete a" << std::endl;
      delete a; //booom
     std::cout << "a deleted" << std::endl;
//#endif 
     delete[] a;
     return 0;
}
