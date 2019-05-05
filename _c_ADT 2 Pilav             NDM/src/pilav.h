#ifndef _PILAV_H
#define _PILAV_H
#include <iostream>
#include "nodopv.h"

using namespace std;

const int MAXLUNGH=100;

class Pila{
    friend void stampaPila(Pila & L);

  public:
    Pila(){	creaPila();};
    ~Pila(){};

    void creaPila(){
    	  for (int i=0;i<MAXLUNGH;i++)      elementi[i].setElemento(0);
    	  testa=0;
    	};
    bool pilaVuota() const{   					return testa==0;};
    tipoelem leggiPila() const{	  				return (elementi[testa-1].getElemento());		};
    void fuoriPila(){
    	  if (!pilaVuota())       			  	testa-=1;
    	  else	    						  	cout<<"nessun elemento nella pila"<<endl;
    	};
    void inPila(tipoelem el){
    	  if (testa==MAXLUNGH)       			cout<<"raggiunta capacità massima della pila"<<endl;
    	  else{     				 			elementi[testa].setElemento(el);	         testa++;    }
    	};
  private:
    Nodo elementi[MAXLUNGH];
    int testa;
  };

void stampaPila(Pila & L){
  for (int i = 0; i< L.testa; i++)    cout << L.elementi[i] << " ";
}

#endif // _PILAV_H
