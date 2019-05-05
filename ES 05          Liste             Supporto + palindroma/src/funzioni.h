/*Esercizio 1
Implementare
1) una funzione per calcolare la lunghezza di una lista;				ok
2) una funzione in grado di invertire l'ordine di una lista L senza utilizzare una lista di supporto;	ok
3) una funzione che stabilisca se una lista è palindroma.	ok
 int lunghezza(Lista);
 void inverti(Lista &);
 bool palindoma(Lista);
Le funzioni possono anche essere implementate come metodi della classe astratta LinearList.

*Esercizio 1.2
Liste lineari ordinate: particolare tipo di lista in cui l'ordine sequenziale degli elementi è legato ad una relazione d'ordine definita sugli elementi.
Esempio: se gli elementi sono stringhe si suppone che l'odinamento sia per chiave alfabetica.
A tale scopo sarà necessario definire gli operatori '<', '<=' e '>' per il tipo di dato stringa (Tali operatori sono già definiti per il tipo di dato string, definito nella libreria string. ).
1) Modificare l'operatore insLista per liste lineari ordinate (oppure definire un nuovo operatore insListaOrdinata);	ok
2) implementare l'algoritmo di ricerca lineare ordinata;	ok
3) implementare l'algoritmo di fusione di liste ordinate;	ok
4) applicare le funzioni a liste lineari di stringhe ordinate per chiave alfabetica. ok

*/


#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linked_list.h"
#include "linear_list.h"
#include <iostream>

using namespace std;

template< class T,class P >
void inverti_valori(Linear_list<T,P> &L){
	typename Linear_list<T,P>::position   p_begin=	L.begin();
	typename Linear_list<T,P>::position   p_end=	L.last();
	  while(p_begin!= p_end &&		 p_begin!= L.previous(p_end)){//gestire caso pari
		  typename Linear_list<T,P>::value_type temp=L.read(p_end);
		  L.write(L.read(p_begin),	p_end);
		  L.write(temp,	p_begin);

		  p_begin=	L.next(p_begin);
		  p_end=	L.previous(p_end);
	}
}
//insert
template< class T,class P >
void insert_ordered(Linear_list< T ,P> &l,typename Linear_list<T,P>::value_type &a){
	l.insert(a,ordered_position(l,a));
	//l.set_size(l.size()+1);
};

template< class T,class P >
typename Linear_list<T,P>::position ordered_position(Linear_list<T,P> &L,const typename Linear_list<T,P>::value_type v){
	typename Linear_list<T,P>::position  p_begin=	L.begin();

	 while(p_begin!= L.last()){
		  if(L.read(p_begin)>v)
			  return p_begin;
		  else
			  p_begin= 	L.next(p_begin);
	  }
	 return nullptr;
}

template< class T,class P  >
bool palindroma(Linear_list<T,P> &L){
	//Linear_list<T,P> temp= L;
	//inverti_valori(temp);
	//return (L==temp);
}


template< class T,class P >
typename Linear_list<T,P>::position index(Linear_list<T,P> &L,int ind){
	typename Linear_list<T,P>::position  p_begin=L.begin();
	int count=0;
	if(0==ind)			return p_begin;
	do{
		p_begin= L.next(p_begin);
		count++;
		if(count==ind)			return p_begin;

	}while(p_begin!= L.last());
	return nullptr;
}

template< class T,class P >
int position_c(Linear_list<T,P>& L,typename Linear_list<T,P>::position pos){
	typename Linear_list<T,P>::position  p_begin=L.begin();
	int count=0;

	if(p_begin==pos)			return 0;
	do{
		p_begin= L.next(p_begin);
		count++;
		if(p_begin==pos)			return count;
	}while(p_begin!= L.last());
	return -1;
}


template< class T,class P >
typename Linear_list<T,P>::position ricerca_binaria(Linear_list<T,P>& L,const typename Linear_list<T,P>::value_type v){
	typename Linear_list<T,P>::position  p_begin=	L.begin();
	typename Linear_list<T,P>::position  p_end=	L.last();
	typename Linear_list<T,P>::position mid;
	typename Linear_list<T,P>::value_type first;
	while(p_begin!= p_end){
		mid= index(L,(position_c(L,p_begin) + position_c(L,p_end))/2);
		if(v==L.read(mid)){			return mid;
		}else{
			if(v>L.read(mid)){				p_begin=L.next(mid);}
			else{						p_end=L.previous(mid);}
		}
	}
	return nullptr;
}

template< class T, class P >
void merge(Linear_list<T,P>& L1,Linear_list<T,P>& L2,Linear_list<T,P>& L3){
	typename Linear_list<T,P>::position p1=L1.begin();
	typename Linear_list<T,P>::position p2=L2.begin();
	typename Linear_list<T,P>::position p3=L3.begin();

	while(! L1.end(p1) && !L2.end(p2)){
		typename Linear_list<T,P>::value_type elem1=L1.read(p1);
		typename Linear_list<T,P>::value_type elem2=L2.read(p2);
		if(elem1<elem2){
			L3.insert(elem1,p3);
			p1=L1.next(p1);
		}else{
			L3.insert(elem2,p3);
			p2=L2.next(p2);
		}
		p3= L3.next(p3);
	}
	while(! L1.end(p1)){
		L3.insert(L1.read(p1),p3);
		p1=L1.next(p1);
		p3=L3.next(p3);
	}
	while(! L2.end(p2)){
		L3.insert(L2.read(p2),p3);
		p2=L2.next(p2);
		p3=L3.next(p3);
	}
}


template< class T,class P >
void Insertion_sort(Linear_list<T,P>& L){
	typename Linear_list<T,P>::value_type key;
    int i,j;
    int n=L.size();

    for(i=1;i<n;i++){			   					//for(i=1;i<n;i++){
    	key=L.read(index(L,i));								//key=arr[i];
        j=i-1;											//j=i-1;
        while(j>=0 && L.read(index(L,j))>key){				//while(j>=0 && arr[j]>key){
        	L.write(L.read(index(L,j)),	index(L,j+1));    		//arr[j+1]=arr[j];
        	j=j-1;											//j=j-1;
        }
        L.write(key,index(L,j+1));							//arr[j+1]=key;
    }
}


#endif /* FUNZIONI_H_ */
