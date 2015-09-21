#ifndef __VETTORELINEARE_HPP
#define __VETTORELINEARE_HPP
#include "vettore.hpp"
#include <iostream>
#include <cmath>

using namespace std;

/**************************************************
 * ATENZIONE: tutte le funzioni che coinvolgono le
 * operazioni con i vettore prendono in ingresso 
 * riferimenti a vettori
 *************************************************/


// Scott Mayers More Effective C++, Item 3, NEVER TREATS ARRAY
// POLIMORPHICALLY

class vettorelineare:public vettore
{
public:
  vettorelineare (unsigned int);
    vettorelineare (const vettorelineare &);
  vettorelineare getversore ();
  double getmodulo () const;
  vettorelineare operator= (const vettorelineare &);
  double getcomponent (unsigned int) const;	// gli stessi metodi sono
  // dicharati pubblici
  // nella classe vettore
  // --> ATTENZIONE!
//  vettorelineare operator+ (vettorelineare &);    // una funzione passa l'argomento per referenza 
  unsigned int setcomponent (unsigned int, double);
  unsigned int getsize () const
  {
    return size;
  }
  double operator* (const vettorelineare &) const;	// prodotto
  // scalare
  vettorelineare operator* (double) const;	// prodotto per uno scalare
private:
  double *m_v;
  unsigned int size;
};


// copy costructor
vettorelineare::vettorelineare (const vettorelineare& a)
{
  size = a.getsize ();
  m_v = new (std::nothrow) double[size];
  if (m_v == nullptr)
    {
      std::cerr << "Can't allocate memory on heap, exiting..." << std::endl;
      exit (1);
    }
  for (unsigned int i = 0; i < size; ++i)
    {
      m_v[i] = a.getcomponent (i);
    }

}

// COSTRUTTORE

vettorelineare::vettorelineare (unsigned int lenght):
m_v (nullptr)
{
  size = lenght;
#ifdef DEBUG
  std::cout << "size = " << getsize () << std::endl;
#endif
  m_v = new (std::nothrow) double[size];
  if (m_v == nullptr)
    {
      std::cerr << "Can't allocate memory on heap, exiting..." << std::endl;
      exit (1);
    }
  for (unsigned int i = 0; i < size; ++i)
    {
      m_v[i] = 0;
    }
#if 0
  std::cout << "Ecco ciascuna componente del vettore(fresco fresco di costruttore): " << std::endl;
  for (unsigned int i = 0; i < size; ++i)
    {
      std::cout << getcomponent (i) << std::endl;
    }
#endif
}
#if 0
vettorelineare
vettorelineare::operator+ (vettorelineare & b)
{
#ifdef DEBUG
  std::cout << size << " ?= " << b.getsize () << std::endl;
#endif
  if (size != b.getsize ())
    {
      std::cerr << "errore, somma di vettori di diverse dimensioni" <<
	std::endl;
      exit (1);
    }
  for (unsigned int i = 0; i < size; ++i)
    {
      setcomponent (i, getcomponent (i) + b.getcomponent (i));
    }
  return *this;
}
#endif
  // implementazione del metodo di moltiplicazione per scalare
vettorelineare
vettorelineare::operator* (double alpha) const
{
  vettorelineare x(getsize());
  for (unsigned int i = 0; i < getsize (); ++i)
    {
      x.setcomponent (i, (getcomponent (i)) * alpha);
    }
  return x;
}

    // implementazione del prodotto scalare tra due vettori
double
vettorelineare::operator* (const vettorelineare & b) const
{
  if (getsize () != b.getsize ())
    {
      std::cerr <<
	"errore, prodotto scalare  di vettori di diverse dimensioni" <<
	std::endl;
      return -1;
    }
  double ris = 0;
  for (unsigned int a = 0; a < b.getsize (); ++a)
    {
      ris += b.getcomponent (a) * getcomponent (a);
    }
  return ris;
}

// occhio che getcos non fa parte dei metodi della classe ma è a se
// stante!
double
getcos (vettorelineare & a, vettorelineare & b)
{
  return (a * b) / (a.getmodulo () * b.getmodulo ());
}

// basta fare il prodotto scalare del vettore per se stesso e farne la
// radice quadrata
double
vettorelineare::getmodulo () const
{
  vettorelineare tmp (*this);
  return sqrt (tmp * tmp);
}


unsigned int
vettorelineare::setcomponent (unsigned int pos, double value)
{
  if (size > getsize ())
    {
      std::cerr << "pos you've inserted overflows array size, exiting..."
	<< std::endl;
      return 1;
    }
  m_v[pos] = value;
#ifdef DEBUG
  std::cout << getcomponent (pos) << std::endl;
#endif
  return pos;
}

double
vettorelineare::getcomponent (unsigned int position) const
{
   return m_v[position];
}


// overloading dell'operatore << per stampare il vettore su standard
// output
std::ostream & operator<< (std::ostream & outstream, vettorelineare & vect)
{
  for (int i = 0; i < vect.getsize (); ++i)
    {
      outstream << vect.getcomponent (i) << " ";
    }
  std::cout << std::endl;
  return outstream;
}

class funzionevettorialebase {
public:
  virtual vettorelineare eval(double , const vettorelineare &) const = 0;   // metodo virtuale puro
};

class oscillatore : public funzionevettorialebase {
public:
	~oscillatore(){}
  oscillatore(double);
  double getfreq(){return omega;}
  void setfreq(double a){omega = a;}
  virtual vettorelineare eval(double ,const vettorelineare &) const;
private:
  double omega;
};

oscillatore::oscillatore(double w){
  omega = w;
}

vettorelineare oscillatore::eval(double t,const vettorelineare& x) const {
  vettorelineare v(2);
  v.setcomponent(0,x.getcomponent(1));
  v.setcomponent(1,( - x.getcomponent(0)*pow(omega,2)));
  return v;
}

class pendolo : public funzionevettorialebase {
  public:
    ~pendolo(){}
    pendolo(double x){    // lunghezza del filo
   l = x; 
    }
    vettorelineare eval(double t, const vettorelineare &x) const {
    double tmp=-(g/l)*sin(x.getcomponent(0));
    vettorelineare out(2);
    out.setcomponent(0,x.getcomponent(1));
    out.setcomponent(1,tmp);
    return out;

    } 
  private:
    double l;
    const static int g = 9.806;

};

class oscillatoreforzato : public funzionevettorialebase {
  public:
  ~oscillatoreforzato(){}
  oscillatoreforzato(double o0,double o,double a){
  omega0=o0;
  omega=o;
  alpha=a;
  }
  vettorelineare eval(double t,vettorelineare v){
  double a = -pow(omega0,2)*v.getcomponent(0)- alpha*v.getcomponent(1) + sin(omega*t); 
  vettorelineare out(2);
  out.setcomponent(0,v.getcomponent(1));
  out.setcomponent(1,a);
  
  return out;
  }
  private:
  double omega0,alpha,omega;

};

//operator+ staccato dalla classe

vettorelineare operator+ (vettorelineare a,vettorelineare b)
{
#ifdef DEBUG
  std::cout << a.getsize() << " ?= " << b.getsize () << std::endl;
#endif
  if (a.getsize() != b.getsize ())
    {
      std::cerr << "errore, somma di vettori di diverse dimensioni" <<
	std::endl;
      exit (1);
    }
  vettorelineare tmp(a.getsize());    // creo un temporay che mi serve per tenere il risultato dell'operazione in modo che 
// ----> x = a + 2; quando faccio y = a + 3 la seconda a mi risulti già incrementata dall'operazione precedente, cioè come se fosse a+2   
  for (unsigned int i = 0; i < b.getsize(); ++i)
    {
      tmp.setcomponent (i, a.getcomponent (i) + b.getcomponent (i));
    }
  return tmp;
}

// implemetazione del metodo getversore

vettorelineare
vettorelineare::getversore ()
{
  for (unsigned int i = 0; i < size; ++i)
    {
      m_v[i] = m_v[i] / getmodulo ();
    }
  return *this;
}


// operatore di assegnazione

vettorelineare
vettorelineare::operator= (const vettorelineare&  a)      // l'argomento del mio operator= voglio che sia una referenza costante
{
  size = a.getsize ();
  m_v = new (std::nothrow) double[size];
  if (m_v == nullptr)
    {
      std::cerr << "Can't allocate memory on heap, exiting..." << std::endl;
      exit (1);
    }
  for (unsigned int i = 0; i < size; ++i)
    {
      m_v[i] = a.getcomponent (i);
    }
  return *this;
}


#endif // __VETTORELINEARE_HPP
