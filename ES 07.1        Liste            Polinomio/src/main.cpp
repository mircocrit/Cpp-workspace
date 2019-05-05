#include "linked_list.h"
#include "Polynomial.h"
#include <iostream>

using namespace std;


int main(){
  Polynomial<double> poly,poly2,polyres;
  double d[5]={1.6, -2.3, 0, -4.5, 6.4};

  for(int i=0;i<5;i++){
  	  poly.insert(d[i]);
  }
  poly.visual();

  double d2[8]={-4.4, 5.3, 2.1, 0, -2.1, -5.2,-4.5, 2.9};
  for(int j=0;j<8;j++){
	  poly2.insert(d2[j]);
    }
  poly2.visual();
  poly.somma(poly2,polyres);			// result=		1.6	 -6.7  5.3	-2.4   6.4	 -7.3       grado 5
  polyres.visual();
  system("pause");
  return 0;

}
