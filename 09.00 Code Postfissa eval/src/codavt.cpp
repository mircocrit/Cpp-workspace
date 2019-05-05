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
	  ////////////////////
	  void insert(char *);
	  int valuta_polacca();
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

template < class tipoelem >
 void Coda<tipoelem>::insert(char *a){
	int N = strlen(a);
	for (int i=0;i<N;i++) {
			inCoda(a[i]);
		}
}
template <class tipoelem>
int Coda<tipoelem>::valuta_polacca() {
  Pila<int> pila;
  pila.creaPila();
  while (!codaVuota()) {
    char t=leggiCoda();
    fuoriCoda();
    if (t>='0' && t<='9') {
      int n=t-'0';
      while (t!=' ') {
        t=leggiCoda();
        fuoriCoda();
        if (t>='0' && t<='9') {
          n=n*10+(t-'0');
        }
      }
      //cout << n << endl;
      pila.inPila(n);
    } else if (t=='+' || t=='-' || t=='*' || t=='/') {
      double numtop = pila.leggiPila();
      pila.fuoriPila();
      double numsuc = pila.leggiPila();
      pila.fuoriPila();
      double ris;
      if (t == '+')
        ris = numsuc + numtop;
      if (t == '-')
        ris = numsuc - numtop;
      if (t == '*')
        ris = numsuc * numtop;
      if (t == '/')
        ris = numsuc / numtop;
      pila.inPila(ris);
    }
  }
  int ris=pila.leggiPila();
  return ris;
}
#endif //CODAVT_
