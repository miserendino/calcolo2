#include <iostream>
#ifndef __CAMPO_HPP
#define __CAMPO_HPP
#include <cmath>
#include <string>
using namespace std;
#define K 8.99E9
#define e_mass 9.109382616*10E-31
#define e_charge -1.6021765314*10E-19
#define G 6.67384*10E-11 // m^3/(kg*s^2)
#define m_earth 5.972*10E24 // kg
//***********************************************************************************
class posizione{
    public:
      posizione(){Mx=0;My=0;Mz=0;}
      posizione(double x,double y,double z){Mx=x; My=y; Mz=z;}
    ~posizione(){};
    void sphcord();
    void cilcord();
    double x();
    double y();
    double z();
   double getrho();
   double gettheta();						//metodi per ottenere le coordinate in diversi sistemi di riferimento
   double getphi();
   double gett();
    double distanza(posizione&);			//metodo per calcolare la distanza da reference a posizione
    protected:
    double Mx,My,Mz;
    double rho,theta,phi,t;
};
void posizione::sphcord(){
  rho=(sqrt(pow(Mx,2)+pow(My,2)+pow(Mz,2)));
  phi=atan(My/Mx);
theta=acos(Mz/(sqrt(pow(Mx,2)+pow(My,2)+pow(Mz,2))));
    }
void posizione::cilcord(){
  rho=(sqrt(pow(Mx,2)+pow(My,2)));
  theta=atan(My/Mx);
  t=Mz;
}

double posizione::x() {
  return Mx;
}
double posizione::y() {
  return My;
}
double posizione::z() {
  return Mz;
}

double posizione::getrho(){  
  sphcord();
  return rho;
  }
double posizione::gettheta(){
  sphcord();
  return theta;
  }
double posizione::getphi(){
  sphcord();
  return phi;
    }
double posizione::gett(){
  cilcord();
  return t;
  }
double posizione::distanza( posizione& b) {
  return sqrt(pow(x()-b.x(),2)+pow(y()-b.y(),2)+pow(z()-b.z(),2));
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

  class corpoceleste : public particella,posizione {
    public:
      corpoceleste();
      ~corpoceleste(){}
      corpoceleste(std::string nome, double massa, double raggio, double dist) : particella(massa,0), posizione(dist,0,0)
    {
      m_nome = nome;
        m_raggio = raggio;
    }
      void setnome(std::string nome){m_nome=nome;}
      double potenziale(corpoceleste&);
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
    double corpoceleste::potenziale(corpoceleste& x){
			return (-(G*m_massa)/(x.getraggio()+m_raggio+distanza(x)));
	}

//*********************************************************************************

  class campovettoriale: public posizione{
  public:
    double Mx()   {return vett[0];}
    double My()   {return vett[0];}
    double Mz()   {return vett[0];}
    void setMx(double)  {vett[0]=c;}
    void setMy(double)  {vett[1]=c;}
    void setMz(double)  {vett[2]=c;}
    campovettoriale(posizione&);

    double modulo();
    void somma(campovettoriale);
  protected:
    double vett[3],c;
};


campovettoriale::campovettoriale(posizione& a):posizione(a){
  vett[0]=0.;
  vett[1]=0.;
  vett[2]=0.;
}

double campovettoriale::modulo(){
  double a=0.;
  for(unsigned int i=0; i<3; ++i)  
    a=a+pow(vett[i],2);
  return sqrt(a);
}

void campovettoriale::somma(campovettoriale a){
  for(unsigned int i=0; i<3; ++i)  
    vett[i]=vett[i]+a.vett[i];
}
//***********************************************************************************

class puntomateriale :public particella, posizione{
  public:
    puntomateriale(double massa,double carica,double x,double y,double z);
    campovettoriale campoelettrico( posizione&);
    campovettoriale campogravitazionale( posizione&);
};
puntomateriale::puntomateriale(double massa,double carica,double x,double y,double z):particella(massa,carica),posizione(x,y,z){
}

campovettoriale puntomateriale::campoelettrico(posizione& r)  {
  campovettoriale el(r);
  el.setMx(K*m_carica*(el.x()-Mx)/pow(distanza(r),3));
  el.setMy(K*m_carica*(el.y()-My)/pow(distanza(r),3));
  el.setMz(K*m_carica*(el.z()-Mz)/pow(distanza(r),3));
  return el;
}

campovettoriale puntomateriale::campogravitazionale( posizione& r) {
  campovettoriale gr(r);
  gr.setMx(G*m_massa*(gr.x()-Mx)/pow(distanza(r),3));
  gr.setMy(G*m_massa*(gr.y()-My)/pow(distanza(r),3));
  gr.setMz(G*m_massa*(gr.z()-Mz)/pow(distanza(r),3));
  return gr;
}


#endif//__CAMPO__HPP
