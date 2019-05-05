#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"
#include "pilavt.h"
#include "codavt.cpp"

template<class T>//dichiarazione anticipata
   class Linked_list;


//NODO
template< class T >
 class List_node{
	friend class Linked_list<T>;///////////////
  private:
	////////////////////////////////////////////////////
	T _value;
	List_node<T> * _pPrev;	//riuso il tipo appena definito
	List_node<T> * _pNext;
	//////////////////////////////////////////////
  public:
 	List_node<T> * next(){			return(this->_pNext);};
 	List_node<T> * prev(){			return(this->_pPrev);};

};

//LISTA LINKATA(eredita da LISTA LINEARE)

template< class T >
 class Linked_list :			 public Linear_list<  T, List_node<T>* >{
  public:
	typedef typename Linear_list<T, List_node<T>*>::value_type			 value_type;//tipo valore + tipo posizione
	typedef typename Linear_list<T, List_node<T>*>::position 		 	 position;
	//PPREV PNEXT PVALUE

	Linked_list();								// costruttore
	Linked_list(int);							// costruttore
	Linked_list(const Linked_list<T>& );		// costruttore per copia(importante)
	~Linked_list();								//distruttore

	void create(){								if (empty())		_length = 0;};					//NO			// operatori
	bool empty() const{							return(_pHead == _pHead->_pNext);};		//se il prossimo punta a se stesso
	value_type read(position p ) const {			if (!end(p))		return(p->_value);};
	void write(const value_type &a, position p ){if (!end(p))		p->_value = a;}
	position begin() const{						return (_pHead->_pNext);};
	position last() const{						return (_pHead->_pPrev);};
	bool end(position p) const {				return(p == _pHead);};
	position next(position p) const{			return(p->_pNext);};
	position previous(position p) const{		if (p != _pHead)			return(p->_pPrev);};
	void insert(const value_type &, position);
	void erase(position);

	int size() const {							return _length;};
												// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
	bool operator==(const Linked_list<T> &) const; // contengono gli strssi elementi(non sui puntatori all'iniziono della lista)



 private:
	List_node<T> * _pHead;	//puntator e a inizioo lista
	int _length; // the length of the list
};

template< class T >
Linked_list< T >::Linked_list() {
	_pHead = new List_node<T>;	//creo nodo da 0 e lo assegno a il membro interno di lista, poi lo popolo utilizzando le funzion idi nodo
	_pHead->_pNext = _pHead;//succ e prec di testa puntano a se stesso
	_pHead->_pPrev = _pHead;
	_length = 0;//membro di lista
}

template< class T >	//costruttore di copia
Linked_list< T >::Linked_list(const Linked_list<T>& L) {
    _length = L.size();	//calcolo la lunghezza dell alista da copiare
	_pHead = new List_node<T>; //creo nuovo nodo non puntante a nulla
	_pHead->_pNext = _pHead;	//azzero puntatori
	_pHead->_pPrev = _pHead;

	if (!L.empty()){		//mentre la lista da copiare  non e' libera
		position p = L.last();	//metto in position l'ultimo elem della lista copiata
		for (int i=0; i <= L._length; i++){
			insert(L.read(p), begin());	//inserisco l'elemento letto all'inizio
			p = L.previous(p);  // e scalo dalla fine
		}
	}
}

template< class T >
Linked_list< T >::~Linked_list(){
	while(!empty())		//il successivo di head punto a se stesso
		erase(begin());	//distruggo la posizione begin
	delete _pHead;//ora rimuovo il puntatore
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p){//inserisce elemento di tipo valuetype in posizione p
	position t = new List_node<T>;		//Linear_list<T, List_node<T>*>::position
	t->_value = a;		//temp

	t->_pNext = p;			//algoritmo di inserimento
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;	//aumento lunghezza lista
}

template< class T >
void Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){	//se non e' vuoto e non e' finito
		p->_pPrev->_pNext = p->_pNext;	//òla posiz successiva di poosizione diventa la posizione successiva all precedente di posizione
		p->_pNext->_pPrev = p->_pPrev;
		delete p;	//cancello la posizione p
	}
}

template<class T>//OPERATORE DI ASSEGNAZIONE
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
	if (this != &L){	//SE OGG DEVERSO DA PASSATO
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

        cout << L.empty();	//boolean
        cout << L.size();	//grosso
		if (!L.empty()){//entro se lal sta non e' vuota
            position p = L.last();	//la fine della lista passata la metto in position
			for (int i=0; i < L.size(); i++){
				cout << i, L.read(p);	//stampa elem lista e posizione
				insert(L.read(p), begin());	//inserisco elemento letto dalla lista l di pos p,  in posizione  begin:
				//INSERT FA SCALARE GLI ELEMENTI QUINDI L'ULTIMO INSERITO SARA ALLA FINE L'ULTIMO ANCHE NELLA LISTA COPIATA
				p = L.previous(p); //vado all'elemento precedente della lista
			}
		}
	}
	return *this;
}


template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
	if (L.size() != _length)	//controllo le lunghezze
		return false;
	position p, pL;
	p = begin(); //salvo entrambe le osizioni di start
	pL = L.begin();
	while (!end(p)){	//finche la lista della classe non e' finita
		if (p->_value != pL->_value)	//se sono diversi esco
			return false;
		p = p->_pNext;	//seugenti posizioni
		pL = pL->_pNext;
	}
	return true;//se sopravvivio esco
}

#endif // _LINKED_LIST_H

