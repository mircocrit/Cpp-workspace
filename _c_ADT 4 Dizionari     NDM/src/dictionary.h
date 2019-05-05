#ifndef _DICTIONARY_H
#define _DICTIONARY_H

template<class K, class E>
struct Entry {
  K first;															//key
  E second;															//entry

  Entry(){}
  Entry(Entry<K,E>& e){    first = e.first;    second = e.second;}
};


template <class K, class E>
class Dictionary{

public:
  virtual ~Dictionary() {}
  virtual void create() = 0;
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual Entry< K, E>* find(const K& k) const = 0;
  virtual void insert(Entry< K, E>& e) = 0;
  virtual void erase(const K& k) = 0;
  virtual void modify(const K& k, const E& e) = 0;			// modifica il valore della entry con chiave k con il valore e
};

#endif
