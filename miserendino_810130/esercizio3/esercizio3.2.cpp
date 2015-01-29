#include <iostream>
#include "posizione.hpp"


int main(int argc, char **argv){
particella * part = new particella(2,3);
elettrone * elett = new elettrone;
corpoceleste * earth = new corpoceleste("Terra",5.9742E24,6.372797);
std::cout  << earth->getmassa() << std::endl;
delete part,elett,earth;

  return 0;
}
