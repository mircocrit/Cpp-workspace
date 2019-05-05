
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

    ////////////////////////////
    void stampaPila();
    tipoelem Postfissa(string);//calcola il risultato di una esspressione postfissa
    void Inf2Postf(string a);


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
typename Pila<Elemento>::tipoelem Pila<Elemento>::Postfissa(string a){
	int N = a.length();
	Pila<Elemento> postf(N);
	int op1; int op2; bool inNumb;
	inNumb = false;

	for (int i=0; i<N; i++){
		if (a[i] == '+'){
			inNumb = false;
			op1 = postf.leggiPila(); 				postf.fuoriPila();
			op2 = postf.leggiPila(); 				postf.fuoriPila();
			postf.inPila(op1 + op2);
			//cout<<postf.leggiPila()<<endl;
		} else if (a[i] == '*'){
			inNumb = false;
			op1 = postf.leggiPila(); 				postf.fuoriPila();
			op2 = postf.leggiPila(); 				postf.fuoriPila();
			postf.inPila(op1 * op2);
			//cout<<postf.leggiPila()<<endl;
		} else
		if ((a[i] >= '0') && (a[i] <= '9')){
			if (inNumb) {			//e' il secondo numero
				op1 = postf.leggiPila(); 			postf.fuoriPila();
				postf.inPila(10 * op1 + (a[i]-'0'));
				//cout<<postf.leggiPila()<<endl;//creo numero con n+1 cifre

			} else 		//non numeri prima
				{inNumb = true; 			//ora c'e un numero prima
				postf.inPila(a[i]-'0'); }		//impilo
				//cout<<postf.leggiPila()<<endl;
		}
		else inNumb = false;

		//cout<<"Iterata"<<i<<endl;
	}
	return postf.leggiPila();
}

template <class Elemento>
void Pila<Elemento>::stampaPila(){
	Pila<Elemento> temp(testa);
	 tipoelem Element;
	 while (!pilaVuota()) {
		 Element = leggiPila();
		 fuoriPila();
		 cout << Element << "";
		 temp.inPila(Element);
	 }
	 creaPila();
	 while ( !temp.pilaVuota()){
		Element = temp.leggiPila();
		inPila(Element);
		temp.fuoriPila();
	 	}
 }
template <class Elemento>
void Pila<Elemento>::Inf2Postf(string a){
	int N = a.length();
	Pila<char> operatori(N);

	for (int i=0; i<N; i++){
		if (a[i] == ')') {
			cout << operatori.leggiPila() << " ";
			operatori.fuoriPila();
		}
		if ((a[i] == '+') || (a[i] == '*'))		//impilo operatori
			operatori.inPila(a[i]);
		if ((a[i] >= '0') && (a[i] <= '9'))		//se e' un numero stampa a video
			cout << a[i] << " ";
	}
}

#endif // _PILAVT_H
