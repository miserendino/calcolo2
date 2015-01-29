#ifndef LIB_HPP
#include <cmath>
#define LIB_HPP
long double funzione(long double);
long double funzione(long double x)
{
  return (sqrt(x+1) - sqrt(x));
}
double calcola_media(double *, int);
double calcola_media(double *v, int dim){
  double tmp;
  for (int i=0; i<dim; ++i){
    tmp+=v[i];
  }
  return (tmp/dim);
}
double calcola_varianza(double *, int);
double calcola_varianza(double *v, int dim){
  double temp;
  double media=calcola_media(v, dim); //calcolo la media del vettore in ingresso che utilizzo per calcolare la varianza
  for (int i=0; i<dim; ++i){
    temp+=pow((v[i]),2);
  }
  return (dim/(dim-1))*((temp/dim)-pow(media,2));
}
#endif
