#ifndef _CODAVT_
#define _CODAVT_

#include <iostream>
#include "pilavt.h"
#include <cstring>

template < class tipoelem >
class Coda {
	public:
	  Coda(int n){	 maxlung = n;		 creaCoda();}
	  ~Coda(){		delete[] elementi;}
	  void creaCoda();
	  bool codaVuota(){ 	return (lung == 0); }
	  tipoelem leggiCoda(){    	if (!codaVuota())     return (elementi[testa]);}
	  void fuoriCoda();
	  void inCoda(tipoelem);

	 private:
	  tipoelem *elementi;
	  int testa, lung, maxlung;
};
template < class tipoelem >
  void Coda<tipoelem>::creaCoda(){
	elementi = new tipoelem[maxlung];
	testa = 0;				lung = 0;
  }
template < class tipoelem >
  void Coda<tipoelem>::fuoriCoda(){
	if (!codaVuota()){
	  testa = (testa + 1) % maxlung;
	  lung--;
	}
  }
template < class tipoelem >
  void Coda<tipoelem>::inCoda(tipoelem a){
	if (lung != maxlung){
	  elementi[(testa+lung) % maxlung] = a;
	  lung++;
	}
  }


#endif //CODAVT_
