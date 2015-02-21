#include <iostream>
#include "campo.hpp"
#include <sstream>
#define e 1.60217653E-19
#include <cstdlib>
#define me 9.1093826E-31
#define mp 1.67262171E-27
#define d 1.E-10
using namespace std;

int main(int argc,char** argv){

	if(argc!=4){
		std::cerr << "Errore, digita " << argv[0] << " <x> <y> <z> " << endl;
		return -1;
	}
#if 0
	double x=0,y=0,z=0;
   std::stringstream s1(argv[1]);
    		s1 >> x;
			std::stringstream s2(argv[2]);
    		s2 >> y;
			std::stringstream s3(argv[3]);
    		s3 >> z;
#endif

                double x=atof(argv[1]);
                    double y=atof(argv[2]);
                        double z=atof(argv[3]);

	posizione r(x,y,z);                             // crea un'istanza della classe posizione con le ccordinate inserite dall'utente

	puntomateriale a(me,-e,d/2.,0.,0.);             // definisce un elettrone a distanza d/2 rispetto a un sistema di coordinate cartesiano 
	puntomateriale b(mp,e,-d/2.,0.,0.);              // definisce un protone ecc....

	campovettoriale gr(r);
	gr.somma(b.campogravitazionale(r));
  gr.somma(a.campogravitazionale(r));

	campovettoriale el(r);
	el.somma(b.campoelettrico(r));
  el.somma(a.campoelettrico(r));
	cout<<"Il campo gravitaz in ("<<r.x()<<","<<r.y()<<","<<r.z()<<") vale : ("<<gr.Mx()<<","<<gr.My()<<","<<gr.Mz()<<")"<<endl;
		cout<<"Il campo elettrico in ("<<r.x()<<","<<r.y()<<","<<r.z()<<") vale : ("<<el.Mx()<<","<<el.My()<<","<<el.Mz()<<")"<<endl;

	return 0;
}
