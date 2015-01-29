#ifndef __LIB_HPP
#define __LIB_HPP
#include <memory>
#include <iostream>

 class vettore {
  public:
    
     vettore();
    vettore(unsigned int size){ m_size=size; m_v = new double[size]; 
      for(unsigned int i=0; i<size; ++i){ m_v[i]=0; }}    //inizializzo tutti gli elementi del vettore con 0

    unsigned int getsize() { return m_size; }
    unsigned int setcomponent(unsigned int ,double);
    double getcomponent(unsigned int);
    vettore(vettore&);             //copy constructor
    vettore& operator=(vettore&);     // operatore di assegnazione
  private:
    unsigned int m_size;
    double * m_v;
};

unsigned int vettore::setcomponent(unsigned int position, double value){
  while(position>m_size){
    std::cerr <<"the value specified is bigger than the lenght of the array,exiting" << std::endl;
  return -1;
  } 
  m_v[position]=value;
 return position;
}
double vettore::getcomponent(unsigned int position){
  while(position>m_size){
    std::cerr << "the value specified is bigger than the lenght of the array,exiting" << std::endl;
  return -1;
  }
  return m_v[position];
}
//costruttore di copy constructor -- implementazione

  vettore::vettore(vettore& pluto){
    m_size = pluto.m_size;                    //assegno la stessa lunghezza del vettore di partenza
    m_v = new double[m_size]; 
    for(unsigned int i=0; i<m_size; ++i){        // assegno i valori di ciascuna componente del vettore nuovo
      m_v[i] = pluto.m_v[i];
    }
  }
//overloaing dell'operatore di assegnazione

vettore& vettore::operator=(vettore& pippo){
  m_size = pippo.m_size;
  if (m_v) delete [] m_v;
  m_v = new double[m_size];
  for(unsigned int a=0; a<m_size; ++a){
    m_v[a] = pippo.m_v[a];
  }
  return *this;
}
#endif //__LIB_HPP
