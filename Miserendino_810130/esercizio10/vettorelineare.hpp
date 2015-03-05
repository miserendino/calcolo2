#ifndef __VETTORELINEARE_HPP
#define __VETTORELINEARE_HPP
#include "vettore.hpp"
#include <iostream>

/**************************************************
 * ATENZIONE: tutte le funzioni che coinvolgono le
 * oprazioni con i vettore prendono in ingresso 
 * riferimenti a vettori
 *************************************************/


class vettorelineare : public vettore{
  public:
    vettorelineare (unsigned int);
    ~vettorelineare();
    vettorelineare operator+( vettorelineare& );
    double getmodulo(vettorelineare& );
    double getcomponent(unsigned int );
    unsigned int secomponent(unsigned int ,double );
    double getcos(vettorelineare&, vettorelineare&);
    double operator*( vettorelineare&);       //prodotto scalare
    vettorelineare operator*(double);         //prodotto per uno scalare
};

vettorelineare vettorelineare::operator+ ( vettorelineare& b)
 {
  vettorelineare r(b.getsize());
  if (getsize() != b.getsize()){
      std::cerr << "errore, somma di vettori di diverse dimensioni" << std::endl;
      return -1;
      }
      for (unsigned int i=0; i<getsize(); ++i){
      r.setcomponent(i,getcomponent(i)+b.getcomponent(i));
      return r;
      }
}
  //implementazione del metodo di moltiplicazione per scalare
vettorelienare vettorelineare::operator*(double alpha)
  { 
      for(unsigned int i=0; i<m_v.getsize(); ++i)
      {
        m_v.setcomponent(i,(getcomponent(i))*alpha)
        }
    }
    //implementazione del prodotto scalare tra due vettori
double vettorelineare::operator*(vettorelineare& b)
  {   
  if(getsize() != b.getsize()){
      std::cerr << "errore, prodotto scalare  di vettori di diverse dimensioni" << std::endl;
      return -1;
      }
    for(unsigned int a=0; a<b.getsize(); ++i){
    }
  }    


double vettorelineare::getcos(vettorelineare& a, vettorelineare& b){
return (a*b)/(getmodulo(a)*getmodulo(b));
}
  
//basta fare il prodotto scalare del vettore per se stesso e farne la radice quadrata
double vettorelineare::getmodulo(vettorelineare& v){
  return sqrt(v*v);
}

#if 0
unsigned int vettorelineare::secomponent(unsigned int pos,double value){
v.setcomponent(pos,value);
return pos;
}

double vettorelineare::getcomponent(unsigned int position){
return v.getcomponent(position);
}
#endif






#endif //__VETTORELIENARE_HPP
