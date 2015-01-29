#ifndef __VETTORELINEARE_HPP
#define __VETTORELINEARE_HPP
#include "../esercizio6/vettore.hpp"
#include <iostream>

class vettorelineare : public vettore{
  public:
    vettorelineare (unsigned int);
    ~vettorelineare();
    vettorelienare operator+( vettorelineare& );
    double getcos(vettorelineare, vettorelineare);
    double operator*( vettorelineare&);       //prodotto scalare
    vettorelineare operator*(double);         //prodotto per uno scalare
};

vettorelineare vettorelineare::operator+ ( vettorelineare& b)
{
  vettorelineare r(getsize());
  if (getsize() != b.getsize(){
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
double getcos(vettorelineare a, vettorelineare b){
}
  















#endif //__VETTORELIENARE_HPP
