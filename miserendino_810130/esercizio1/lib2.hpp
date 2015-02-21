#include <iostream>
#include <cmath>
#ifndef LIB2_HPP
#define LIB2_HPP
double calcola_modulo(double);
double calcola_modulo(double ,double);
double calcola_modulo(double *,unsigned int);

double calcola_modulo(double num){
  if(num>0) return num;
  if(num<0) return -(num);
  else std::cout << "Number inserted is equal to zero! " << std::endl;
}
double calcola_modulo(double v1,double v2){
  double tmp=0;
  tmp=pow((v1),2)+pow((v2),2);
  return sqrt(tmp);
}
double calcola_modulo(double *a,unsigned int size){
  double temp=0;
    for (int i=0; i<size; ++i){
        temp+=pow((a[i]),2);
         }
  return sqrt(temp);
}

#endif 
