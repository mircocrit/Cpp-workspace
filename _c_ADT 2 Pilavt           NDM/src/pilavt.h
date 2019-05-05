#ifndef PILAVT_H
#define PILAVT_H

#include <iostream>

using namespace std;

template <class Elemento>
class Pila{
  public:
    typedef Elemento tipoelem;

    Pila(){
    	elementi = new tipoelem[100]; 	MAXLUNGH = 100;
    	creaPila();
    	};
    Pila(int N){
    	elementi = new tipoelem[N]; 		MAXLUNGH = N;
    	creaPila();
    	};
    ~Pila(){	 						delete[] elementi;	};
    void creaPila(){				 	testa=0;};
    bool pilaVuota() const{       		return testa==0;};
    tipoelem leggiPila() const{       	return elementi[testa-1];	};
    void fuoriPila(){
    	  if (!pilaVuota())    			  		testa-=1;
    	  else				  	 				cout<<"nessun elemento nella pila"<<endl;	};
    void inPila(tipoelem el){
    	  if (testa==MAXLUNGH)			 	 	cout<<"raggiunta capacità  massima della pila"<<endl;
    	  else{      elementi[testa]=el;		testa++;		  }
    	};
  private:
    tipoelem *elementi;
    int MAXLUNGH;
    int testa;
  };

#endif // _PILAVT_H
