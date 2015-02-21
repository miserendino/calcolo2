#include <iostream>
#include "posizione.hpp"
#define MASSATERRA 5.972E24 
#define RAGGIOTERRA 6.371E6 
#define MASSALUNA 7.347673E22
#define RAGGIOLUNA  1.738E6 
#define RAGGIOSOLE 6.95800E8 
#define MASSASOLE 1.989E30 

int main(int argc, char **argv){
particella * part = new particella(2,3);
elettrone * elett = new elettrone;
corpoceleste * earth = new corpoceleste("Terra",MASSATERRA,RAGGIOTERRA);
std::cout  << earth->getmassa() << std::endl;
earth->setposizione(3,4,5);
#ifdef DEBUG
std::cout << earth->getxposizione() << std::endl;
std::cout << earth->getyposizione() << std::endl;
std::cout << earth->getzposizione() << std::endl;
#endif
posizione r(2,3,4);
double prova=earth->calcolapotenziale(r);
std::cout << "il potenziale della terra calcolato a una distanza fittizia di r(2,3,4) è " << prova << std::endl;
delete part,elett,earth;

/***********************************************************************************
 il potenziale gravitazionale prodotto dal Sole sulla Luna è più o meno grande di quello prodotto dalla Terra?
***********************************************************************************/

corpoceleste * moon = new corpoceleste("Luna",MASSALUNA,RAGGIOLUNA);
corpoceleste * sun = new corpoceleste("Sole",MASSASOLE,RAGGIOSOLE);
/* assegno le posizione ai rispettivi pianeti */

moon->setposizione(0,3.84400E8,0);
sun->setposizione(0,0,1.49598E11);
earth->setposizione(0,0,0);

double distanza_sole_luna = 1.473E11;
double distanza_terra_luna = 3.84400E8;
std::cout << "il potenziale generato dal sole sulla luna è circa pari a " <<  sun->calcolapotenziale(moon->getposizione()) << " J/kg " << std::endl;
std::cout << "il potenziale generato dalla terra sulla luna è circa pari a " <<  earth->calcolapotenziale(moon->getposizione()) << " J/kg " << std::endl;

  delete moon,sun;
  return 0;
}
