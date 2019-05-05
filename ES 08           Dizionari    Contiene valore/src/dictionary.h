#ifndef _DICTIONARY_H
#define _DICTIONARY_H

template<class K, class E>
class Entry {
public:
	  K first;		//KEY
	  E second;		//ENTRY
	  Entry(){}
	  Entry(Entry<K,E>& e){    first = e.first;    second = e.second;}
	  E get_value(){ return second;};
	  K get_key(){ return first;};
};

/////////////////////////////////////////INTERFACE//////////////////////////////////////////////////////////////////
template <class K, class E>
class Dictionary{

public:
  virtual ~Dictionary() {}

  virtual void create() = 0; 									// crea dizionario vuoto
  virtual void insert(Entry< K, E>& e) = 0;						 // inserisce l'entry nel dizionario

  virtual bool empty() const = 0; 								// true se dizionario vuoto
  virtual int size() const = 0;									// numero entry dizionario

  virtual Entry< K, E>* find(const K& k) const = 0; 			// ritorna entry(key+chiave) dando una chiave

  virtual void modify(const K& k, const E& e) = 0;				// modifica il valore della entry con chiave k con il valore e
  virtual void erase(const K& k) = 0;							//elimina l'entry con la key
};

#endif
