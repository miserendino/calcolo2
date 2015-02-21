#include <iostream>
#include <utility>      // std::swap

template<typename TD>
void selectionsort(TD *, unsigned int);
template<typename TD>
void selectionsort(TD v[], unsigned int dim) {
     int min;

     for(int i=0;i<dim ;i++) {
       min = i;
        for(int j=i+1;j<dim;j++) {
           if(v[j] < v[min])
           min = j;
                }
        std::swap(v[i], v[min]);
                                        }
}
