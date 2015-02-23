#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <cfloat>
#ifndef __FUNZIONE_HPP
#define __FUNZIONE_HPP

    class funzionebase
{
    public:
        ~funzionebase(){}
        virtual double eval(double){return 0;}  //ATTENZIONE! bisogna per forza definire il corpo del metodo virtuale altrimenti errore di compilazione
        };
    class parabola :public funzionebase{
        public:
            parabola();
            parabola(double a,double b, double c){ _a=a; _b=b;_c=c;}
            ~parabola(){}
            double eval(double x);
            double geta();
            void seta(double);
            double getb();
            void setb(double);
            double  getc();
            void setc(double);
        private:
        double    _a,_b,_c;
    };

//      implementazione dei metodi della classe parabola

double parabola::eval(double x){
    return _a*pow(x,2)+_b*x+_c;
    }
void parabola::seta(double a){
    _a=a;
}
void parabola::setb(double b){
    _b=b;
}
void parabola::setc(double c){
    _c=c;
}
double parabola::geta(){
    return _a;
}
double parabola::getb(){
    return _b;
}
double parabola::getc(){
    return _c;
}

//*******************************************************************+

    class solutore {
        public:
            virtual double cercazeri(double xmin, double xmax, funzionebase* f){return 0;}
            void setprecisione(double epsilon){_prec = epsilon;}
            double getprecisione(){return _prec;}
        protected:
            double _a,_b;
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
class ricerca:public solutore{
    public:
        ricerca();
        ricerca(double a,double b,double prec);
        ~ricerca();

        virtual double cercazeri(double xmin, double xmax, funzionebase* f);
        void print();
};

//implementazione della classe solutore

ricerca::ricerca(){
    _a=0;
    _b=0;
    _prec=0;
}
ricerca::ricerca(double a,double b, double prec){
    _a=a;
    _b=b;
    _prec=prec;
}
ricerca::~ricerca() {}
double c;
double ricerca::cercazeri(double xmin, double xmax, funzionebase *f) {

    if (sign(f->eval(xmin)==0)) {
        c=xmin;
        return c;
    }
    if (sign(f->eval(xmax)==0)) {
        c=xmax;
        return c;
    }
    if (sign(f->eval(xmin))*sign(f->eval(xmax))>0){
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

class seno: public funzionebase{
    public:
        seno();
        ~seno();

        virtual double eval(double x);
};
seno::seno(){}
seno::~seno() {}
double seno::eval(double x){
    double y=sin(x);
    return y;
}

// funzione caratteristica di un insieme

class funzione_caratteristica : public funzionebase{
  public:
  funzione_caratteristica(double );
  ~funzione_caratteristica(){}
  virtual double eval();
  private: 
double _raggio;
};


#endif
