#include <iostream>
#include "funzione.hpp"

int main(int argc,char **argv){
    parabola a(1,2,1);

    double c=a.eval(-2/2);
    std::cout << "il valore della parabola nel punto -b/2a è: " << c << std::endl;
    return 0;
}
