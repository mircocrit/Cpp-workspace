/*Liste
 * Esercizio 1:
Sovraccaricare l'operatore != in modo che l'espressione x != y restituisca true se e solo se le due liste x e y sono diverse ok

 * Esercizio 2:
Definire e implementare nell'interfaccia i seguenti metodi:
	-clear(): ende la lista vuota		ok
	-num_elements(p1, p2): calcola il numero di elementi compresi fra le posizioni p1 e p2	ok
	-exchange(p1, p2): scambia l'elemento in posizione p1 con quello in posizione p2	ok
	-move_min_max(): quando la lista è di elementi di tipo intero, sposta, nel modo più efficiente possibile, il massimo in ultima posizione, e il minimo in prima posizione ok
		Scrivere una funzione che elimini da una lista L1 tutti gli elementi presenti nella lista L2.	ok
		Se |L1|~|L2|=n, qual'è la complessità del vostro algoritmo?

 * Esercizio 3:
Implementare il metodo Lista::insertionSort che ordina la lista utilizzando l'algoritmo di ordinamento per inserzione (Nota: non cancellare ne creare nuovi nodi)	ok

 * Esercizio 4:
Cambiare la realizzazione del metodo Lista::canclista in modo che dimezzi la dimensione del vettore quando il numero di elementi della lista è minore di dimensione/2
*/

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linked_list.h"

/*

template< class T >
void insert_ordered(Linked_list< T > &l,typename Linked_list<T>::value_type &a){
	l.insert(a,ordered_position(l,a));
	l.set_size(l.size()+1);
};

*/
/*
template< class T >
typename Linked_list<T>::position ordered_position(Linked_list<T> &L,const typename Linked_list<T>::value_type v){
	typename Linked_list<T>::position  p_begin=	L.begin();

	 while(p_begin!= L.last()){
		  if(L.read(p_begin)>v)
			  return p_begin;
		  else
			  p_begin= 	L.next(p_begin);
	  }
	 return nullptr;
}
*/



template< class T, class P >
int position_c(Linear_list< T,P > & L,typename Linked_list<T>::position pos){
	typename Linked_list<T>::position  p_begin=L.begin();
	int count=0;

	if(p_begin==pos)			return 0;
	do{
		p_begin= L.next(p_begin);
		count++;
		if(p_begin==pos)			return count;
	}while(p_begin!= L.last());
	return -1;
}



template< class T, class P >
void exchange(Linear_list< T,P > &l,typename Linear_list< T,P >::position p1, typename Linear_list< T,P >::position p2){
	typename Linked_list< T >::value_type v1=l.read(p1);
	typename Linked_list< T >::value_type v2=l.read(p2);
	l.write(v2,p1);
	l.write(v1,p2);
}

template< class T >
void ric_min_max(Linked_list< T > &l){
	typename Linked_list< T >::position  p_begin=	l.begin();
	typename Linked_list< T >::value_type min= l.read(l.begin());
	typename Linked_list< T >::value_type max= l.read(l.begin());
	typename Linked_list< T >::position p_temp,p_temp2;
	p_begin=l.next(p_begin);

	while(p_begin!= l.last()){
		if(l.read(p_begin)<min)			{min=l.read(p_begin);	p_temp=p_begin;}
		if(l.read(p_begin)>max)			{max=l.read(p_begin);	p_temp2=p_begin;}
		p_begin=p_begin->next();
	}
	l.write(l.read(l.begin()),p_temp);
	l.write(min,l.begin());
	l.write(l.read(l.last()),p_temp2);
	l.write(max,l.last());
}

template< class T >
void clear(  Linked_list< T > &l){
	typename Linked_list< T >::position p=l.last();
	while(p!=l.begin()){
		l.erase(p);
		p=l.previous(p);
	}
	l.erase(l.begin());
}

template< class T >
void delete_from(Linked_list< T > &l, Linked_list<T>& temp){
	typename Linked_list< T >::position  l_=	l.begin();
	typename Linked_list< T >::position  temp_=	temp.begin();
	while(temp_!= temp.last()){
		l_=l.begin();
		while(l_!=l.last()){
			if(l.read(temp_)==l.read(l_)){
				l.erase(l_);
			}
			l_=l.next(l_);
		}
		temp_=l.next(temp_);
	}
}

template< class T >
bool operator!=(const Linked_list<T> & L1, const Linked_list<T> & L2) {
	return !(L1==L2);};


template< class T >
int num_elements(typename Linked_list<T>::position p1, typename Linked_list<T>::position p2){
	return (position_c(p2) -position_c(p1));}


#endif /* FUNZIONI_H_ */
