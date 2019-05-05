/* Esercizio 5:
[Polinomi] Un polinomio di grado d può essere rappresentato con una lista lineare di d+1 elementi,
*in cui ogni elemento rappresenta un coefficiente del polinomio (l'elemento i-esimo della lista è il coefficiente dell'i-esimo termine, c_i x^d, del polinomio).
Definire una classe C++ polynomial che metta a disposizione i seguenti metodi
	-polynomial() - crea un polinomio di grado zero
	-grado() - restituisce il grado di un polinomio
	-input(inStream) - acquisisce un polinomio dallo stream di input inStream.
	Possiamo assumere che l'input sia il grado del polinomio seguito dai valori dei coefficienti.
	-output(outStream) - visualizza il polinomio
	-somma(b) - somma con il polinomio b
	-moltiplica(b) - moltiplica con il polinomio b
	-valore(x) - restituisce il valore del polinomio nel punto x*/
//2x^2 + 4x+1--->  2  4  1  grado 2


#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include <iostream>
#include <sstream>
#include <ios>
#include "linked_list.h"

using namespace std;

template< class T >
 class Polynomial {
  public:
	typedef typename Linear_list<T, List_node<T>*>::value_type			 value_type;
	typedef typename Linear_list<T, List_node<T>*>::position 		 	 position;


	Polynomial();									// crea un polinomio di grado zero
	~Polynomial();

	int grado(){					return degree;} // restituisce il grado di un polinomio
	void insert(const value_type &);				//inserisce nuovo coefficiente di grado n+1
	//void input(ios_base::istream &);				// acquisisce un polinomio dallo stream di input inStream.		ok
													//Possiamo assumere che l'input sia il grado del polinomio seguito dai valori dei coefficienti.
	//void output(ios_base::ostream &) ;				//visualizza il polinomio	ok
	void somma(Polynomial<T>&,Polynomial<T>&);			// somma con il polinomio b	ok
	Polynomial<T>& moltiplica(Polynomial<T>&b);		// moltiplica con il polinomio b
	double valore(double) ;							// restituisce il valore del polinomio nel punto x
	void visual();
	void insert_inverted(const value_type &);
	value_type read(int index){
		if(degree!=0)
			return list.read(list.index(degree-index-1));}		//1+2


 private:
	Linked_list<T>  list;
	int degree;
};

template< class T >
Polynomial< T >::Polynomial() {
	 list.create();
	 degree=0;
}

template< class T >
Polynomial< T >::~Polynomial(){
	delete &list;
}
template< class T >
void Polynomial< T >::insert(const value_type &a){
	list.insert(a,list.last()->next());
	degree++;
}

template< class T >
void Polynomial< T >::insert_inverted(const value_type &a){
	list.insert(a,list.begin());
	degree++;
}

template< class T >
void Polynomial< T >::visual(){
	int i=0;
	for(i=0;i<degree;i++){
		cout<<list.read(list.index(degree-i-1))<<" x^"<<i<<"	";
			if(i!= degree-1){
				if(list.read(list.index(i+1))>=0)			{	cout<<"+";}
			}

	}
	cout<<endl;
}

// this=		1.6,  -2.3,  0, -4.5,  6.4,  -5.2		grado 5
// poly2=			 -4.4, 5.3, 2.1,   0,    -2.1		grado 4
// result=		1.6	 -6.7  5.3	-2.4   6.4	 -7.3       grado 5

template< class T >
void Polynomial< T >::somma(Polynomial<T> & poly2,Polynomial<T> & result){
	int limit;
	if(grado() > poly2.grado())				limit=poly2.grado();
	else 									limit=grado();

	for(int i=0;i<limit;i++){
		result.insert_inverted(poly2.read(i)+ read(i));	//non prende 1 e 0
	}

	if(grado() > poly2.grado()){
		for(int i=poly2.grado();i<grado();i++)
			result.insert_inverted(read(i));
	}
	else
		if (grado() < poly2.grado()){
			for(int i=grado();i<poly2.grado();i++)
				result.insert_inverted(poly2.read(i));
	}
}

#endif /* POLYNOMIAL_H_ */
