/*Esercizio 4
Il tipo di dato dequeue (double ended queue) è una sequenza modificabile ad entrambi gli estremi, in cui è possibile:
inserire un elemento in testa o inserirlo in fondo
cancellare un elemento dalla testa o cancellarlo dal fondo.
Si fornisca una realizzazione in C++ (operatori con tempo O(1)).
*/


#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include "linked_list.h"

template< class T >

class Dequeue:    public Linked_list<T>{
	public:
		void insert_head(const typename Linked_list<T>::value_type & v){ Linked_list<T>::insert(v,Linked_list<T>::begin());};
		void insert_tail(const typename Linked_list<T>::value_type & v){ Linked_list<T>::insert(v,Linked_list<T>::last());};
		void erase_head(){Linked_list<T>::erase(Linked_list<T>::begin());};
		void erase_tail(){Linked_list<T>::erase(Linked_list<T>::last());};
};

#endif /* DEQUEUE_H_ */
