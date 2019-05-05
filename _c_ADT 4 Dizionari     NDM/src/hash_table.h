#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "dictionary.h"
#include <string>
#include <iostream>

using std::string;

template<class T>
class Hash{
	public:
	  size_t operator()(const T the_key) const;
};

template<>
class Hash<string>{
	public://override
	  size_t operator()(const string the_key) const {		//size t=int
		unsigned long hash_value = 0;
		int length = (int) the_key.length();
		for (int i=0; i<length; i++)
		  hash_value = 5 * hash_value + the_key.at(i);
		return size_t(hash_value);
	  }
};

template<class K, class E>
struct Entry;

template<class K, class E>
class HashTable:									 public Dictionary<K,E> {
	public:
	  bool empty() const{    			return (dsize == 0); };
	  int size() const{    				return dsize;};
	  void erase(const K& k);						//da fare
	  void modify(const K& k, const E& e);			//da fare
	  HashTable(int);
	  void create(){};
	  int search(const K& ) const;
	  Entry< K, E>* find(const K& ) const;
	  void insert(Entry< K, E>& );

	private:
	 Entry<K, E>** table;
	 Hash<K> hashm;		            // mappa il tipo k in un tipo non integer
	 int dsize;		                // numero entries dizionario
	 int divisor;		            // diviosre funzione hash
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class K, class E>
HashTable<K,E>::HashTable(int the_divisor){
  divisor = the_divisor;
  dsize = 0;
  table = new Entry<K, E>* [divisor];
  for (int i=0; i<divisor; i++)
    table[i] = NULL;
}

template<class K, class E>
int HashTable<K,E>::search(const K& the_key) const{
  int i =0;
  int j = i;
  do {
    if (table[j] == NULL || table[j]->first == the_key)     return j;			//trovato
    j = (j+1) % divisor;
  } while (j != i);
  return j;
}

template<class K, class E>
Entry< K, E>* HashTable<K,E>::find(const K& the_key) const{
  int b = search(the_key);
  if (table[b] == NULL || table[b]->first != the_key)	    return NULL;
  return table[b];
}

template<class K, class E>
void HashTable<K,E>::insert(Entry<K, E>& e){
  int b = search(e.first);
  if (table[b] == NULL){
    table[b] = new Entry<K,E> (e);
    dsize++;
  } else {
    if (table[b]->first == e.first)
      table[b]->second = e.second;
    else{
      throw "Hash table is full";
    }
  }
}

#endif
