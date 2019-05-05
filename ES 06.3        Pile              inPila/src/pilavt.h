
#ifndef PILAVT_H
#define PILAVT_H

#include <iostream>

using namespace std;


template <class Elemento>
class Pila{
  public:
    typedef Elemento tipoelem;

    Pila();
    Pila(int);
    ~Pila(){	 delete[] elementi;};;
    void creaPila(){	 testa=0;};
    bool pilaVuota() const{       return testa==0;};
    tipoelem leggiPila() const{       return elementi[testa-1];};
    void fuoriPila();
    void inPila(tipoelem);

    int get_max() const{ return MAXLUNGH;};

  private:
    tipoelem *elementi;
    int MAXLUNGH;
    int testa;
  };

template <class Elemento>
Pila<Elemento>::Pila(){
  elementi = new tipoelem[100]; 	MAXLUNGH = 100;// dimensione standard della pila
  creaPila();
}

template <class Elemento>
Pila<Elemento>::Pila(int N){
  elementi = new tipoelem[N]; 		MAXLUNGH = N;	// dimensione N della pila
  creaPila();
}

template <class Elemento>
void Pila<Elemento>::fuoriPila(){
  if (!pilaVuota())      testa-=1;
  else				  cout<<"nessun elemento nella pila"<<endl;
}

template <class Elemento>
void Pila<Elemento>::inPila(tipoelem el){
  if (testa==MAXLUNGH)			  cout<<"raggiunta capacità massima della pila"<<endl;
  else{

      elementi[testa]=el;
      testa++;
    }
}

#endif // _PILAVT_H
