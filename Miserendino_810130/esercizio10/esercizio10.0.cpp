#include <iostream>
#include <cstdlib>
#include "vettorelineare.hpp"

int
main (int argc, char **argv)
{

  double x1;
  double y1;
  double z1;
  double x2;
  double y2;
  double z2;

  std::cout << "inserisci le componenti del primo vettore " << std::endl;
  std::cin >> x1 >> y1 >> z1;
  std::cout << "inserisci le componenti del secondo vettore " << std::endl;
  std::cin >> x2 >> y2 >> z2;

  vettorelineare v (3);
  v.setcomponent (0, x1);
  v.setcomponent (1, y1);
  v.setcomponent (2, z1);
  vettorelineare w (3);
  w.setcomponent (0, x2);
  w.setcomponent (1, y2);
  w.setcomponent (2, z2);
  vettorelineare copia (v);	// immagazzino in memoria una copia del
                              // vettore v
  v + w;			// immagazina nel vettore v la risultante
              // delle forze tra i due vettori 
  v.getversore ();		// versore della risultante delle forze
  std::cout << "Ecco il versore di v" << std::endl;
  std::cout << v;
  double ris1 = getcos (v, w);	// calcolo il coseno tra
                                // la risultante e il
                                // primo dei due vettori
    std::cout << "valore del coseno tra la risultante e il primo dei due vettori" << std::endl;
    std::cout << ris1 << std::endl;
  double ris2 = getcos (v, copia);	// calcolo il coseno tra
                                    // la risultante e il
                                    // secondo dei due vettori
    std::cout << "valore del coseno tra la risultante e il secondo dei due vettori" << std::endl;
  std::cout << ris2 << std::endl;
  return 0;
}
