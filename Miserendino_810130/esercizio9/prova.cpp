#include <cstdlib>
#include <iostream>
int main(){
srand (time(NULL));
for(int i=0;i<100;i++){
std::cout << rand()/double(RAND_MAX) << std::endl;
}
int prova=0;
int ciao;
ciao = 4+5;
std::cout << prova << " " << ciao << std::endl;
return 0;
}
