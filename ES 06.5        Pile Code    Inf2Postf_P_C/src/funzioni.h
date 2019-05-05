/*Esercizio 7
Convertire un'espressione aritmetica da notazione infissa alla corrispondente notazione postfissa utilizzando una coda come risultato della conversione.
 espressione               pila            coda
 35 + 17 * (40 - 9) - 7
 + 17 * (40 - 9) - 7                       35
 17 * (40 - 9) - 7         +               35
 * (40 - 9) - 7            +               17 35
 (40 - 9) - 7              + *             17 35
 40 - 9) - 7               + * (           17 35
 - 9) - 7                  + * (           40 17 35
 9) - 7                    + * ( -         40 17 35
 ) - 7                     + * ( -         9 40 17 35
 - 7                       + * (           - 9 40 17 35
 7                         -               + * - 9 40 17 35
                           -               7 + * - 9 40 17 35

*/
#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linked_list.h"
#include "pilavt.h"
#include "codavt.cpp"

using namespace std;


template<class T>
void trasferisci(Linked_list<T> &l, Pila<T> &s, Coda <T> &c){
	typename Linked_list<T>::value_type top_elem = s.leggiPila();
	s.fuoriPila();
	c.inCoda(top_elem);
}


int priorita(char v){
	if (v== '*'|| v=='/') 			return 2;
	else  if (v== '+' || v== '-' ) 	return 1;
	else 	return -1;
};




template<class T>
Coda<T>& converti(Linked_list<T> &l,Pila<T> &pila_op,Coda<T> &coda_post){
	typename Linked_list<T>::value_type t;
	typename Linked_list<T>::value_type top_elem;
	pila_op.creaPila();
	coda_post.creaCoda();
	typename Linked_list<T>::position p=l.begin();
	typename Linked_list<T>::position la=l.last();

	while (p!= la){
		t=l.read(p);
		if (t>='0' && t<='9'){					coda_post.inCoda(t);}
		else if(pila_op.pilaVuota()){			pila_op.inPila(t);}
		else if (t == '(' ){					pila_op.inPila(t);}
		else if (t == ')' ) {
			top_elem = pila_op.leggiPila();
			while (!pila_op.pilaVuota()  && pila_op.leggiPila() != '(' ){
				trasferisci(l,pila_op, coda_post);
			}
			if(pila_op.leggiPila() == '(')
				pila_op.fuoriPila();
		}
		else{
		  while (!pila_op.pilaVuota() && priorita(t) <= priorita(pila_op.leggiPila())){
			  trasferisci(l,pila_op, coda_post);
		  }
		  pila_op.inPila(t);
	   }
		p=l.next(p);
	}
	while (!pila_op.pilaVuota()){
		trasferisci(l,pila_op, coda_post);}
	return coda_post;
}




template <class T>
typename Pila<T>::tipoelem Postfissa(Pila<T> &p,string a){
	int N = a.length();
	Pila<T> postf(N);
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

template <class T>
void stampaPila(Pila<T> &p){
	Pila<T> temp(p.get_testa());
	 T Element;
	 while (!p.pilaVuota()) {
		 Element = p.leggiPila();
		 p.fuoriPila();
		 cout << Element << "";
		 temp.inPila(Element);
	 }
	 p.creaPila();
	 while ( !temp.pilaVuota()){
		Element = temp.leggiPila();
		p.inPila(Element);
		temp.fuoriPila();
	 	}
 }

template <class T>
void Inf2Postf(Pila<T> &p,string a){
	int N = a.length();
	Pila<T> operatori(N);

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



template < class T >
 void insert(Coda<char> &c, char *a){
	int N = strlen(a);
	for (int i=0;i<N;i++) {
			c.inCoda(a[i]);
		}
}


template <class T>
int valuta_polacca(Coda<T> &c) {
  Pila<int> pila;
  pila.creaPila();
  while (!c.codaVuota()) {
    char t=c.leggiCoda();
    c.fuoriCoda();
    if (t>='0' && t<='9') {
      int n=t-'0';
      while (t!=' ') {
        t=c.leggiCoda();
        c.fuoriCoda();
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


#endif /* FUNZIONI_H_ */
