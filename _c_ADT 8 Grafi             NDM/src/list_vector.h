#ifndef _LISTAVT_H
#define _LISTAVT_H

#include "linear_list.h"

template< class T >
class List_vector :					 public Linear_list<	T, int	>{		//interfaccia
 public:
	typedef typename Linear_list<T, int>::value_type				 value_type;
	typedef typename Linear_list<T, int>::position					 position;

	List_vector() {	   array_dimension_ = 10;			this->create();		};    // costruttori
	List_vector(int dim){	 array_dimension_ = dim;		  this->create();		};
	List_vector(const List_vector<T>& ); 										  // costruttore per copia
	~List_vector(){		delete elements_;}	;  									  //distruttore
																							// OPERATORI
	void create(){  this->elements_ = new T[array_dimension_];		  this->length_ = 0;	};//elements e' di tipo value_type*
	bool empty() const{   	 return(length_ == 0);};
	value_type read(position p) const{	if ( (0 < p) && (p < length_+1)) 		return(elements_[p-1]);};			// precondizione:posizione in range
	void write(const value_type &a, position p){	if ( (0 < p) && (p < length_+1)) 			elements_[p-1] = a;};//scrive  dopo posizione passata, sovrascivendo , no shift
	position begin() const {	return(1);}; // e quindi pos(1)=pos(n+1) se la lista e' vuota (n=0)}
	//ATTENZIONE NEGLI ARRAY SI INIZIA PER FORZA A 1
	bool end(position p) const{
		if ( (0 < p) && (p <= length_+1)) 		return( p == length_+1);//  ritorno true se la posizione e' l'ultima
		else					return(false);		};
	position next(position p) const{
		if ( (0 < p) && (p < length_+1))	return(p+1);					//ritorno la posizione successiva
		else								return(p);		};
	position previous(position p) const{
		if ( (1 < p) && (p < length_+1)) 		return(p-1);				//ritorno posizione precedente
		else									return(p);		};
	void insert(const value_type &, position);
	void erase(position);
																			// sovraccarico di operatori
	List_vector<T>& operator=(const List_vector<T>&); 						// the assignment operator
	bool operator==(const List_vector<T> &) const;							 // tests two list for equality

 private:
	void change_dimension_(T*& , int , int );							//solo in se stesssa e non fuori:work
	value_type* elements_;												//elementi cella
	int length_; 														// the length of the list
	int array_dimension_; 												// array's dimension
};

/* Il costruttore per copia effettua una copia o clone di un oggetto.  
 * Questo costruttore viene invocato, per esempio, quando un oggetto viene passato 
 * per valore ad una funzione o quando una funzione restituisce un oggetto. 
 */
template< class T >//costruttore  di copia
List_vector< T >::List_vector(const List_vector<T>& Lista) {
  this->array_dimension_ = Lista.array_dimension_;	//assegna la dimensioen della lista a questa
  this->length_ = Lista.length_;
  this->elements_ = new T[array_dimension_];	//alloco spazio per gli elementi
  for (int i=0; i<Lista.array_dimension_; i++)	//popolo
     this->elements_[i] = Lista.elements_[i];
}


template< class T >
void List_vector< T >::insert(const value_type &a, position p){			//aggiungo un elemento nuovo
  if (length_ == array_dimension_){			//confronto le dimensioni:array pieno
    change_dimension_(elements_, array_dimension_, array_dimension_ * 2);		//cambio dim
    array_dimension_ = array_dimension_ * 2;	//aument dim*2 volte
  }
  if ( (0 < p) && (p <= length_+1)) { 		// precondizione
		for (int i=length_; i>=p; i--)		//parto dalla fine
			elements_[i] = elements_[i-1];	//metto l'i-1 nell i(IN ALTO)  11122133  12212113331
		elements_[p-1]=a;	//metto alla fine l'elemento a							-->
		length_++;			//aumento lungh
	}
}

template< class T >
void List_vector< T >::erase(position p){
  if ( (0 < p) && ( p < length_ + 1)) // precondizione
    if (!empty()) {
		for (int i=p-1;i<(length_-1);i++)//fino alla fine firza andria
			elements_[i]=elements_[i+1];	//shift indietro		11122133 1 2212113331
		length_--;//decremento												<--
		}
}

template<class T>
void List_vector< T >::change_dimension_(T*	&a, int vecchiaDim, int nuovaDim){

  T* temp = new T[nuovaDim];// alloco spazio nuovo necessario
  int number;
  if (vecchiaDim < nuovaDim) //allora devo alllocare nuovo spazio
     number = vecchiaDim;	//mi salvo la vecchia dimensioe
  else
     number = nuovaDim;	//altrimenti mi salvo la nuova, in ogni caso
  for (int i=0; i<number; i++)
     temp[i]=a[i];	//copio elementi di a in temp
  delete [] a; //ora posso rimuovere a
  a = temp;	//copio temp in a
}


template<class T>
List_vector<T>& List_vector<T>::operator=(const List_vector<T>& l){// operatore di assegnamento
	if (this != &l){   // noautoassegnamenti:
		this->array_dimension_ = l.array_dimension_;	//copio dimensione
		this->length_ = l.length_;		//copio lunghezza
		delete this->elements_;			//rimuovo cio che ho in locale
		this->elements_ = new T[array_dimension_];	//rialloco spazio
		for (int i=0; i<l.array_dimension_; i++)
			this->elements_[i] = l.elements_[i];	//copoio elementi
	}
	return *this;		//ritono puntatore ad oggetto apena isyanziato
}


template<class T>
bool List_vector<T>::operator==(const List_vector<T> &l) const{/* operatore di test di uguaglianza */
	if (l.length_ != this->length_)	//se sono diversi in lunghezza
		return false;
  for (int i=0; i<this->array_dimension_; i++)  //accedo alla mia dimensione
		if (this->elements_[i] != l.elements_[i])	//confronto
			return false;
	return true;
}
/*
template< class T >
List_vector< T >::~List_vector(){	delete elements_;}		// distruttore
*//*
template< class T >					// operatori
void List_vector< T >::create(){
  this->elements_ = new T[array_dimension_];
  this->length_ = 0;
}*/
/*
template< class T >
bool List_vector< T >::empty() const {    return(length_ == 0);}
*//*
template< class T >
typename List_vector< T >::position List_vector< T >::begin() const {	return(1); // e quindi pos(1)=pos(n+1) se la lista -Ah vuota (n=0)}
}
*//*
template< class T >
typename List_vector< T >::position List_vector< T >::next(position p) const {
	if ( (0 < p) && (p < length_+1))	return(p+1);		 // precondizione
	else								return(p);
}
*//*
template< class T >
typename List_vector< T >::position List_vector< T >::previous(position p) const {
	if ( (1 < p) && (p < length_+1)) 		return(p-1);			// precondizione
	else							return(p);
}
*//*
template< class T >
bool List_vector< T >::end(position p) const {
	if ( (0 < p) && (p <= length_+1)) 		return( p == length_+1);			// precondizione
	else					return(false);
}
*//*
template< class T >
typename List_vector< T >::value_type List_vector< T >::read(position p) const {
	if ( (0 < p) && (p < length_+1)) 	return(elements_[p-1]);			// precondizione
}*/
/*
template< class T >
void List_vector< T >::write(const value_type &a, position p) {
  if ( (0 < p) && (p < length_+1)) 				elements_[p-1] = a;				// precondizione
}
*/

/*
template< class T >
List_vector< T >::List_vector() {		// costruttore
  array_dimension_ = 10;			this->create();
}

template< class T >							// costruttore
List_vector< T >::List_vector(int dim){
  array_dimension_ = dim;		  this->create();
}
*/
#endif // _LISTAVT_H

