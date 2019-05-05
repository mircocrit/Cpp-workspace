#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "dictionary.h"
#include <string>
#include <iostream>

using std::string;

///////////////////////HASH FUNCTION//////////////////////////////////////////////////////////////////////////////

template<class T>
class Hash{
	public:
	  size_t operator()(const T the_key) const;
};

template<>
class Hash<string>{
	public://override
	  size_t operator()(const string the_key)  const{		//size t=int
		unsigned long hash_value = 0;
		int length = (int) the_key.length();	//lunghezza stringa
		for (int i=0; i<length; i++)
		  hash_value = 5 * hash_value + the_key.at(i);		//at metodo di string: accede al valore del carattere iesimo della stringa
		return size_t(hash_value);		//size t e' intero
	  }
};

template<>
class Hash<int>{
	public://override
	  size_t operator()(const int valore) const {	//size t=int
		unsigned long hash_value = 0;
		hash_value = 13 * valore;		//at metodo di string: accede al valore del carattere iesimo della stringa
		return size_t(hash_value);		//size t e' intero
	  }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class K, class E>			//vd dizionario
struct Entry;

/////////////////////////////////////HASH TABLE//////////////////////////////////////////////////////////////////////

template<class K, class E>							//K CHIAVE 		//E ELEMENTO
class HashTable:								 public Dictionary<K,E> {
	public:
	  HashTable(int);														//costruttore con int
	  void create(){};														//crea dizionario

	  void insert(Entry< K, E>& );											//inserisce la entry di chiave k e valore e
	  bool empty() const{    			return (dsize == 0); };				//dizionario vuoto
	  int size() const{    				return dsize;};						//ritorna numero elementi dizionario
	  Entry< K, E>* find(const K& ) const;									//ritorna la entry trovata
	  int search(const K& ) const;											//ritona la posizoine in cui trovo la chiave

	  void erase(const K& k);												//elimina un elemento alla chiave
	  void modify(const K& k, const E& e);									//modifica valore riferito alla chiave k

	  Entry<K, E>* get_table(int index){ return table[index];};


	private:
	 Entry<K, E>** table;    										 // tabella hash
	 Hash<K> hashm;		            								 // mappa il tipo k in un tipo noninteger
	 int dsize;		               									 // numero entries dizionario
	 int divisor;		            								 // diviosre della funzione hash
};


template<class K, class E>
HashTable<K,E>::HashTable(int the_divisor){
  divisor = the_divisor;
  dsize = 0;
  table = new Entry<K, E>* [divisor];	//matrice di entry
  for (int i=0; i<divisor; i++)
    table[i] = NULL;						//azzero valore
}

template<class K, class E>
void HashTable<K,E>::insert(Entry<K, E>& e){
  int b = search(e.first);				//ricerco la chiave
  if (table[b] == NULL){
    table[b] = new Entry<K,E> (e);	//inserisco
    dsize++;
  } else {
    if (table[b]->first == e.first)		//chiave duplicata
      table[b]->second = e.second;
    else{
      throw "Hash table is full";
    }
  }
}

template<class K, class E>
int HashTable<K,E>::search(const K& the_key) const{		//chiave da ricercare:ritorna indice
  int i = (int) hashm(the_key) % divisor;   // hash chiave diviso divisore
  int j = i;
  do {
    if (table[j] == NULL || table[j]->first == the_key)		//elem nullo o corripsond di chiave
      return j;			//trovato
    j = (j+1) % divisor;
  } while (j != i);	//non esaurisco

  return j;                                 //tabella piena
}

template<class K, class E>			//ricerca nella tabella:ritorna entry
Entry< K, E>* HashTable<K,E>::find(const K& the_key) const{
  int b = search(the_key);						//posizione in cui ho trovato chiave
  if (table[b] == NULL || table[b]->first != the_key)		//chiavi diverse
    return NULL;									//l'entry e' vuota
  return table[b];  //altrimenti trovato
}


template<class K, class E>
void HashTable<K,E>::modify(const K& k, const E& e){
  // TO DO
}


template<class K, class E>
void HashTable<K,E>::erase(const K& k){
  //TO DO

}


#endif
