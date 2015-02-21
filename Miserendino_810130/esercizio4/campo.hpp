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
      posizione(double x,double y,double z){Mx=x; My=y; Mz=z;
#ifdef DEBUG
        std::cout << "Ecco i valori di posizione caricati nella classe: " << std::endl;
        std::cout << Mx << " " << My << " " << Mz << std::endl;
#endif
      }
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
elettrone::elettrone() : particella(e_mass,e_charge){}
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
    double Mx()   {return X;}
    double My()   {return Y;}
    double Mz()   {return Z;}
    void setMx(double);
    void setMy(double);
    void setMz(double);
    campovettoriale(posizione&);
    void set_campo(double, double, double);

    double modulo();
    void somma(campovettoriale);
  protected:
    double X,Y,Z,c;
};
  
void campovettoriale::setMx(double x){X=x;}
void campovettoriale::setMy(double y){Y=y;}
void campovettoriale::setMz(double z){Z=z;}

campovettoriale::campovettoriale(posizione& a):posizione(a){     // assegna un vettore nullo nella posizione indicata
  X=0.;
  Y=0.;
  Z=0.;
}

void campovettoriale::set_campo(double x, double y, double z){     // assegna un vettore di componenti x,y,z al mio campo vettoriale
  X=X;
  Y=y;
  Z=z;
}

double campovettoriale::modulo(){
  double a=0.;
    a=pow(X,2)+pow(Y,2)+pow(Z,2);
  return sqrt(a);
}

void campovettoriale::somma(campovettoriale a){
    X=X+a.Mx();
    Y=Y+a.My();
    Z=Z+a.Mz();
#ifdef DEBUG
    std::cout << "i nuovi valori del campo valgono: " << std::endl;
    std::cout << a.Mx() << " " << a.My() << " " << Mz() << std::endl;
#endif
  }

//***********************************************************************************

class puntomateriale :public particella, posizione{
  public:
    puntomateriale(double massa,double carica,double x,double y,double z);
    campovettoriale campoelettrico( posizione&);
    campovettoriale campogravitazionale( posizione&);
};
puntomateriale::puntomateriale(double massa,double carica,double x,double y,double z):particella(massa,carica),posizione(x,y,z){}

campovettoriale puntomateriale::campoelettrico(posizione& r)  {
  campovettoriale el(r);
  double assoluto,ax,ay,az;
#ifdef DEBUG
  std::cout << "Per il campo elettrico: " << std::endl;
#endif
  assoluto = (K*(getcarica()/pow(distanza(r),3)));
#ifdef DEBUG  
  std::cout << "Assoluto vale: " << assoluto << std::endl;
#endif
  ax=assoluto*(x()-r.x());
#ifdef DEBUG
  std::cout << "ax vale "  << ax << std::endl;
#endif
  ay=assoluto*(y()-r.y());
#ifdef DEBUG
  std::cout << "ay vale " << ay << std::endl;          
#endif  
  az=assoluto*(z()-r.z());
#ifdef DEBUG 
  std::cout << "az vale " << az << std::endl;
#endif  
  el.setMx(ax);
#ifdef  DEBUG 
  std::cout << " el.setMx(ax) vale "  << el.Mx() << std::endl;
#endif
  el.setMy(ay);               // assegno le nuove componenti del campo vettoriale al campo elettrico
#ifdef  DEBUG
  std::cout << " el.setMx(ay) vale "  << el.My() << std::endl;
#endif
  el.setMz(az);       
#ifdef  DEBUDEBUGG
  std::cout << " el.setMx(az) vale "  << el.Mz() << std::endl;
#endif
  return el;
}

campovettoriale puntomateriale::campogravitazionale( posizione& r) {
  campovettoriale gr(r);
  double assoluto,ax,ay,az;
#ifdef DEBUG
  std::cout << "Per il campo gravitazionale: " << std::endl;
#endif  
  assoluto = (G*(getmassa()/pow(distanza(r),3)));
#ifdef DEBUG 
  std::cout << "assoluto vale: " << assoluto << std::endl;
#endif
  ax=assoluto*(x()-r.x());
#ifdef DEBUG
  std::cout << "ax vale "  << ax << std::endl;
#endif
  ay=assoluto*(y()-r.y());
#ifdef DEBUG  
  std::cout << "ay vale " << ay << std::endl;          
#endif 
  az=assoluto*(z()-r.z());
#ifdef DEBUG
  std::cout << "az vale " << az << std::endl;
#endif
  
  gr.setMx(ax);
#ifdef DEBUG 
  std::cout << " gr.setMx(ax) vale "  << gr.Mx() << std::endl;
#endif  
  gr.setMy(ay);               // assegno le nuove componenti del campo vettoriale al campo gravitazionale
#ifdef DEBUG  
  std::cout << " gr.setMx(ax) vale "  << gr.Mx() << std::endl;
#endif  
  gr.setMz(az);       
#ifdef DEBUG  
  std::cout << " gr.setMx(ax) vale "  << gr.Mx() << std::endl;
#endif 
  
  return gr;
}


#endif//__CAMPO__HPP
