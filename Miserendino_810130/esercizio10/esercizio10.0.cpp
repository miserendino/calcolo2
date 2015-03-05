#include <iostream>
#include "vettorelineare.hpp"

int main(int argc,char **argv){
  if(argc!=7){
    std::cerr << "Usage: " << argv[0] << " x1 y1 z1 x2 y2 z2" << std::endl;
  }
  // converto i numeri passati come stringa in valore intero
     double x1 = atoi(argv[1]);
     double y1 = atoi(argv[2]);
     double z1 = atoi(argv[3]);
     double x2 = atoi(argv[4]);
     double y2 = atoi(argv[5]);
     double z2 = atoi(argv[6]);

vettorelineare v;
v.setcomponent(0,x1);
v.setcomponent(1,y1);
v.setcomponent(2,z1);
vettorelineare w;
w.setcomponent(0,x2);
w.setcomponent(1,y2);
w.setcomponent(2,z2);
#ifdef DEBUG
std::cout << v.getcomponent(0) << std::endl;
std::cout << v.getcomponent(1) << std::endl;
std::cout << v.getcomponent(2) << std::endl;
std::cout << w.getcomponent(0) << std::endl;
std::cout << w.getcomponent(1) << std::endl;
std::cout << w.getcomponent(2) << std::endl;
#endif


  return 0;
}
