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
    void quickSort(Elemento *, int);		//metodo qucksort per ordinare un array di elementi servemdosi di una pila

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

template <class Elemento>
void Pila<Elemento>::quickSort(Elemento *a, int n){
	int left, right, newleft, newright, middle, mguess, temp;
	inPila(1); inPila(n);
	while (!pilaVuota()){
		right = leggiPila(); 		fuoriPila();
		left = leggiPila(); 		fuoriPila();
		while (left < right){
			newleft = left; 			newright = right;
			middle = (left + right) /2;
			mguess = a[middle];
			while (a[newleft] < mguess) 				newleft++;
			while (mguess < a[newright]) 				newright--;
			while (newleft < newright-1){
				temp = a[newleft];
				a[newleft] = a[newright];
				a[newright] = temp;

				newleft++; 								newright--;
				while (a[newleft] < mguess) 			newleft++;
				while (mguess < a[newright]) 			newright--;
			}
			if (newleft <= newright) {
				if (newleft < newright) {
					temp = a[newleft];
					a[newleft] = a[newright];
					a[newright] = temp;
				}
				newleft++; newright--;
			}
			if (newright < middle) {
				inPila(newleft); 		inPila(right);
				right = newright;
			} else {
				inPila(left); 		inPila(newright);
				left = newleft;
			}
		}
	}
}

#endif // _PILAVT_H
