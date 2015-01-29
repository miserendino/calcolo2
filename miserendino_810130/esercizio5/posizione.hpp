#include <iostream>
#ifndef __POSIZIONE_HPP
#define __POSIZIONE_HPP
#include <cmath>
#include <string>
using namespace std;
#define e_mass 9.109382616*10E-31
#define e_charge -1.6021765314*10E-19
#define G 6.67384*10E-11 // m^3/(kg*s^2)
#define m_earth 5.972*10E24 // kg
//***********************************************************************************
class posizione{
    public:
      posizione(){_x=0;_y=0;_z=0;}
      posizione(double x,double y,double z){_x=x; _y=y; _z=z;}
    ~posizione(){};
    void sphcord();
    void cilcord();
   double getrho();
   double gettheta();
   double getphi();
   double gett();
   double getx();
   double gety();
   double getz();
    double distanza();
    private:
    double _x,_y,_z;
    double rho,theta,phi,t;
};

double posizione::getx(){
  return _x;
}
double posizione::gety(){
  return _y;
}
double posizione::getz(){
  return _z;
}
void posizione::sphcord(){
  rho=(sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2)));
  phi=atan(_y/_x);
theta=acos(_z/(sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2))));
    }
void posizione::cilcord(){
  rho=(sqrt(pow(_x,2)+pow(_y,2)));
  theta=atan(_y/_x);
  t=_z;
}
double posizione::distanza(){
 double distanza;
    distanza=sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
        return distanza;
        }
double posizione::getrho(){  
  return rho;
  }
double posizione::gettheta(){
  return theta;
  }
double posizione::getphi(){
  return phi;
    }
double posizione::gett(){
  return t;
  }
//*****************************************************************************

  class particella {
    public:
      particella(double massa,double carica){m_massa=massa; m_carica=carica;}
      ~particella(){}
      double getmassa()  {return m_massa;}
      double getcarica() {return m_carica;}
      virtual void print();
    protected:
      double m_massa;
      double m_carica;
  };
    void particella::print(){
  std::cout << "Particella: m=" << m_massa
    << ", q=" << m_carica << std::endl;
}
 class elettrone : public particella{
   public:
     elettrone();
     ~elettrone();
      void print();
  };
elettrone::elettrone() : particella(e_mass,e_charge){};
void elettrone::print(){
  std::cout << "Elettrone: m=" << m_massa
    << ", q=" << m_carica << std::endl;
}
//*****************************************************************************

  class corpoceleste : public particella {
    public:
      ~corpoceleste(){}
      corpoceleste(std::string nome, double massa, double raggio) : particella(massa,0)
    {
      m_nome = nome;
        m_raggio = raggio;
    }
      void setnome(std::string nome){m_nome=nome;}
      double calcolapotenziale(posizione);
      void setmassa(double massa){m_massa=massa;}
      void setraggio(double raggio){m_raggio=raggio;}
      std::string getnome(){ return m_nome;}
      double getraggio(){return m_raggio;}
      virtual void print();
    protected:
      std::string m_nome;
      posizione r;
      double m_raggio;
  }; 
      void corpoceleste::print() {
          std::cout << m_nome << " m=" << m_massa
            << ", R=" << m_raggio << std::endl;
      }
    double corpoceleste::calcolapotenziale(posizione dist)
      {
        return (-(G*m_massa)/dist.distanza());
      }  
 
#endif//__POSIZIONE__HPP
