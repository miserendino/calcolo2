#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <cfloat>
#ifndef fUNZIONE_HPP
#define fUNZIONE_HPP

    class funzionebase
{
    public:
        ~funzionebase(){}
        virtual double eval(double){return 0;}  //ATTENZIONE! bisogna per forza definire il corpo del metodo virtuale altrimenti errore di compilazione
        };
    class parabola :public funzionebase{
        public:
            parabola();
            parabola(double a,double b, double c){ a=a; b=b;_c=c;}
            ~parabola(){}
            double eval(double x);
            double geta();
            void seta(double);
            double getb();
            void setb(double);
            double  getc();
            void setc(double);
        private:
        double    a,b,_c;
    };

//      implementazione dei metodi della classe parabola

double parabola::eval(double x){
    return a*pow(x,2)+b*x+_c;
    }
void parabola::seta(double a){
    a=a;
}
void parabola::setb(double b){
    b=b;
}
void parabola::setc(double c){
    _c=c;
}
double parabola::geta(){
    return a;
}
double parabola::getb(){
    return b;
}
double parabola::getc(){
    return _c;
}


class sinusoide: public funzionebase{
	public:
		sinusoide();
		~sinusoide();

		virtual double eval(double x);
};

//       implementazione della classe sinusoide

sinusoide::sinusoide() {}

sinusoide::~sinusoide() {}

double sinusoide::eval(double x){
	double y=sin(x)-x*cos(x);
#ifdef DEBUG
  std::cout << "la y vale: " << y << std::endl;
#endif
	return y;
}

//*******************************************************************+

    class solutore {
        public:
            virtual double cercazeri(double xmin, double xmax, funzionebase* f){return 0;}
             virtual bool trovato(){return 0;}
             virtual double incertezza(){return 0;}
            void setprecisione(double epsilon){_prec = epsilon;}
            double getprecisione(){return _prec;}
        protected:
            double a,b;
            double _prec;
            funzionebase *f;

    };

//funzione segno
int sign(double a);
int sign(double a){
        if(a==0.)
                    return 0;
            if(a>0)
                        return 1;
                if(a<0)
                            return -1;
}
//*********************
//classe che eredita pubblicamente dalla classe solutore con un metodo virtuale cercazeri
class ricerca:public solutore{
    public:
        ricerca();
        virtual bool trovato();
        virtual double incertezza();
        ricerca(double a,double b,double prec);
        ~ricerca();

        virtual double cercazeri(double xmin, double xmax, funzionebase* f);
        void print();
};

    bool ricerca::trovato(){
        if (sign(f->eval(a))==sign(f->eval(b))){
            cerr <<"f(a) ha lo stesso segno di f(b)." <<endl;
            return false;
            }
        else {
            double xmin=a, xmax=b, m;
            bool risp;
            if (f->eval(xmin)==0) return true;
            else if (f->eval(xmax)==0) return true;
            else for (int i=0, j=1; xmax-xmin >_prec ; i++){
                m=xmin+((xmax-xmin)/2);
                if (f->eval(m)==0) return true;
                else if (sign(f->eval(m))==sign(f->eval(xmin))) xmin=m;
                else xmax=m;
                if (i==100){
                    cerr <<"L'algoritmo ha iterato " <<i*j <<" volte, continuare? (1: si   0: no) " <<endl;;
                    cin >>risp;
                    if (risp==false) return false;
                    else {
                        i=0;
                        j++;
                        }
                    }
                }
            }   
        return true;
        }

    double ricerca::incertezza() {
        double m, xmin=a, xmax=b;
        if (f->eval(xmin)==0) return 0;
        else if (f->eval(xmax)==0) return 0;
        else while (xmax-xmin >_prec){
            m=xmin+((xmax-xmin)/2);
            if (f->eval(m)==0) return 0;
            else if (sign(f->eval(m))*sign(f->eval(xmin))>0) xmin=m;
            else xmax=m;
            }
        return (xmax-xmin)/2;
        }

ricerca::ricerca(){
    a=0;
    b=0;
    _prec=0;
}
ricerca::ricerca(double a,double b, double prec){
    a=a;
    b=b;
    _prec=prec;
}
ricerca::~ricerca() {}
double c=0;
double ricerca::cercazeri(double xmin, double xmax, funzionebase *f) {

  if (sign(f->eval(xmin))==0) {
    c=xmin;
    return c;
  }
  if (sign(f->eval(xmax))==0) {
    c=xmax;
    return c;
  }
  if (sign((f->eval(xmin))*sign(f->eval(xmax)))>0){
    c=FLT_MAX;
    return c;
  }
  while ((xmax-xmin)>_prec){
    c=xmin + (xmax-xmin)/2;
    if (f->eval(c)==0)
      return c;
    if (sign(f->eval(xmin))*sign(f->eval(c))<0)
      xmax=c;
    if (sign(f->eval(xmax))*sign(f->eval(c))<0)
      xmin=c;
  }
}


void ricerca::print(){
    int cifre=-int(log10(_prec));
    cout<<fixed;
    if(c==FLT_MAX)
        cout<<"Mi servono due estremi con immagini di segno diverso"<<endl;
    else
        cout<<"Ho trovato lo zero in x= "<<setprecision(cifre)<<c<<endl;
}


#endif 
