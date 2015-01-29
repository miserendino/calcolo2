#include <iostream>
#include <iomanip>
#include <fstream>
#include "posizione.hpp"
#include <system_error>
#include <cerrno>

int main(int argc,char *argv[]){
  
  double x=0,y=0,z=0;
#if 0
  std::cout << "Inserire la prima coordinata del punto " << std::endl;
  std::cin >> x;
  std::cout << "Inserire la seconda coordinata del punto" << std::endl;
  std::cin >> y;
  std::cout << "Inserire la ternza coordinata del punto" << std::endl;
  std::cin >> z;
#endif
  if(x==y==z==0){
    std::cout << "Prego inserire le coordinate del punto" << std::endl;
    std::cin >> x >> y >> z;
  }
        posizione foo(x,y,z);
        foo.sphcord();
        std::cout << "Coordinate cartesiane: " << std::endl;
        std::cout << "x=" << foo.getx() << " y=" << foo.gety() << " z=" << foo.getz() << std::endl;
    std::cout << "Coordinate sferiche: " << std::endl;
    std::cout << "rho=" <<  foo.getrho() << " theta=" << foo.gettheta() << " phi=" << foo.getphi() << std::endl;
    foo.cilcord();
    std::cout << "Coordinate cilindriche: " << std::endl;
    std::cout << "rho=" << foo.getrho() << " theta=" << foo.gettheta() << " t=" << foo.gett() << std::endl;
  return 0;
}
