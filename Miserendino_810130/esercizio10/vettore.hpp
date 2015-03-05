#ifndef __VETTORE_HPP
#define __VETTORE_HPP
#include <memory>
#include <iostream>
#include <fstream>
#include "lib.hpp"

class vettore {
public:
vettore(){}         // bisogna mettere le parentesi altrimenti il compilatore frigna          
vettore(unsigned int size){ m_size=size; m_v = new double[size];
for(unsigned int i=0; i<size; ++i){ m_v[i]=0; }} //inizializzo tutti gli elementi del vettore con 0
unsigned int getsize() { return m_size; }
unsigned int setcomponent(unsigned int ,double);
double getcomponent(unsigned int);
vettore(vettore&); //copy constructor
vettore& operator=(vettore&); // operatore di assegnazione
private:         //.....ho la necessità di metterlo (non è vero) perchè cosi la classe vettorelineare vede ancora m_size e m_v
unsigned int m_size;
double * m_v;
};

unsigned int vettore::setcomponent(unsigned int position, double value){    //ATTENZIONE: a contare le posizioni dell'array parte da 0!
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

class vettoredati : public vettore {
  public:
    void mediana();
    void print();
    void media();
    void print(char *); 
    void varianza();
    void deviazione_standard();
    vettoredati(unsigned int);
    void caricavett();
    void quicksort();
    ~vettoredati(){}
  private:
    unsigned int num=0;      // numero degli elementi che voglio carica e utilizzare nel mio vettore di dati
    char namefile[32];
    double *v;
};
vettoredati::vettoredati(unsigned int number_of_data){
  v = new double [number_of_data];
  num=number_of_data;
}

void vettoredati::caricavett(){
  load(v,num);
}

void vettoredati::quicksort(){
  quicksort1(v,num);
}

void vettoredati::print(char type[32]){
  write_in_file(v,num);
}

void vettoredati::print(){
  for(unsigned int i=0;i<num;++i){
    std::cout << v[i] << std::endl;
  }
}

void vettoredati::media(){
  calcola_media(v,num);
}

void vettoredati::varianza(){
  calcola_varianza(v,num);
}

void vettoredati::deviazione_standard(){
  calcola_deviazione_standard(v,num);
}
void vettoredati::mediana(){
  calcola_mediana(v,num);
}
#endif //__VETTORE_HPP
