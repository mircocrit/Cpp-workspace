/*Esercizio 1.3
Multilista: supponendo di voler rappresentare un numero intero I mediante una lista,
tale che il valore dell'elemento i-esimo della lista corrisponda a quello dell'i-esima cifra di I,
definire una lista di interi ed implementare le funzioni per:
1) l'acquisizione di n interi			"123"--> size  for(size)	c1--->1 -->  1    2   3
2) la visualizzazione di interi		123			ok
3) la somma di interi							ok

 l1 --> 1 3 5 6
 l2 --> 	3 4
 l3 -->   5 6 7
 l4 --> 	  1


Suggerimenti per la realizzazione con cursori
Definire la variabile SPAZIO come membro della classe lista di tipo static.

Di norma oggetti diversi della stessa classe non condividono risorse di memoria.
Per poter realizzare una comunicazione di ambiente condiviso bisogna dichiarare l'attributo (comune a tutte le istanze) come static.
Gli attributi static possono essere visti come elementi propri della classe, non dell'istanza.

class Lista
  {

  public:
    ...
    Lista();    //costruttore
    ~Lista();   //distruttore

    // operatori
    void crealista();
    ...

  private:
    Static componenteSpazio SPAZIO[100];
    // metodi per la manipolazione dell'attributo SPAZIO
    ...
    // altri dati privati
  };
componenteSpazio è un tipo strutturato costituito da una componente 'elemento' di tipo tipoelem e da una componente successivo di tipo posizione.
*/

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linked_list.h"

template< class T >
void insert_integer(Linked_list<T> &L,std::string value){
	int i,temp=0;
	typename Linked_list<T>::position p=L.begin();
	for(i=0;i<value.size();i++){
	  temp=(int)value[i]-48;
	  L.insert(temp,p);
	}
}

template< class T >
int print_integer(Linked_list<T> &L){
	typename Linked_list<T>::position p=L.begin();
	int temp=0;
	do{
	  temp=10*temp+ L.read(p);
	  p= L.next(p);
	}while(!L.end(p));
	return temp;
}

#endif /* FUNZIONI_H_ */
