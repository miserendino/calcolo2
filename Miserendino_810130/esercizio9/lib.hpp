#ifndef LIB_HPP 
#define LIB_HPP
#include <cmath>
#include <random>
using namespace std;
#define M_PI           3.14159265358979323846  /* pi */

  std::default_random_engine generator;

class EsperimentoPrisma {
  public:
    EsperimentoPrisma();
    void Esegui();
    void Analizza();
    double Gettheta1();
    double Gettheta2();
    double Gettheta1in();
    double Gettheta2in();
  private:                
    double lambda1,lambda2; 
    double alpha,sigmat;
    double a_input, a_misurato;
    double b_input, b_misurato;
    double n1_input, n1_misurato;
    double n2_input, n2_misurato;
    double t0_input, t0_misurato;
    double t1_input, t1_misurato;
    double t2_input, t2_misurato;
};
EsperimentoPrisma::EsperimentoPrisma() :
  lambda1(579.1E-9),
  lambda2(404.7E-9),
  alpha(60*M_PI/180.),
 sigmat(0.3E-3),
  a_input(2.7),
  b_input(60000E-18)
{
  //calcolo degli indici di rifrazione attesi
  n1_input = sqrt(a_input+b_input/(pow(lambda1,2)));
  n2_input = sqrt(a_input+b_input/(pow(lambda2,2)));
// calcolo dei valori attesi degli angoli misurati
  t0_input = M_PI/2;  //theta0 e' arbitrario
  double dm;
  dm = 2.*asin(n1_input*sin(0.5*alpha))-alpha;
  t1_input = t0_input+dm;
  dm = 2.*asin(n2_input*sin(0.5*alpha))-alpha;
  t2_input = t0_input+dm;
}
void EsperimentoPrisma::Esegui(){
  std::normal_distribution<double> distribution0(t0_input,sigmat);
  t0_misurato=distribution0(generator);
  std::normal_distribution<double> distribution1(t1_input,sigmat);
  t1_misurato=distribution1(generator);
  std::normal_distribution<double> distribution2(t2_input,sigmat);
  t2_misurato=distribution2(generator);
}
double EsperimentoPrisma::Gettheta1(){
  return t1_misurato;
}
double EsperimentoPrisma::Gettheta2(){
  return t2_misurato;
}
double EsperimentoPrisma::Gettheta1in(){
  return t1_input;
}

double EsperimentoPrisma::Gettheta2in(){
  return t2_input;
}
void EsperimentoPrisma::Analizza(){
double dm1=t1_misurato-t0_misurato;
double dm2=t2_misurato-t0_misurato;
n1_misurato=(sin(dm1+alpha)/2)/sin(alpha/2);
n2_misurato=(sin(dm2+alpha)/2)/sin(alpha/2);
a_misurato=pow(lambda2,2)*pow(n2_misurato,2)-pow(n1_misurato,2)*pow(lambda2,2);
b_misurato=(pow(n2_misurato,2)-pow(n1_misurato,2))/(1/pow(lambda2,2)-1/pow(lambda1,2));
}

#endif
