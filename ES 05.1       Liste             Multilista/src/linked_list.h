#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"


template<class T>
   class Linked_list;

//NODO
template< class T >
 class List_node{
	friend class 		Linked_list<T>;

 public:
	List_node<T> * next(){			return(this->_pNext);};
	List_node<T> * prev(){			return(this->_pPrev);};

  private:
	////////////////////////////////////////////////////
	T _value;
	List_node<T> * _pPrev;
	List_node<T> * _pNext;
	//////////////////////////////////////////////
};

//LISTA LINKATA

template< class T >
 class Linked_list :			 public Linear_list<  T, List_node<T>*  >{
  public:
	typedef typename Linear_list<T, List_node<T>*>::value_type			 value_type;
	typedef typename Linear_list<T, List_node<T>*>::position 		 	 position;

	Linked_list();
	Linked_list(const Linked_list<T>& );
	~Linked_list();

	void create(){								if (empty())		_length = 0;};
	bool empty() const{							return(_pHead == _pHead->_pNext);};

	value_type read(position p) const{			if (!end(p))		return(p->_value);};
	void write(const value_type &a, position p ){if (!end(p))		p->_value = a;}

	position begin() const{						return (_pHead->_pNext);};
	position last() const{						return (_pHead->_pPrev);};
	bool end(position p) const {				return(p == _pHead);};

	position next(position p) const{			return(p->_pNext);};
	position previous(position p) const{		if (p != _pHead)			return(p->_pPrev);};

	void insert(const value_type &, position);
	void erase(position);

	int size() const {							return _length;};
	void set_size(int val) {	_length=val;};

	Linked_list<T>& operator=(const Linked_list<T>&);
	bool operator==(const Linked_list<T> &) const;

 private:
	List_node<T> * _pHead;
	int _length;
};



template< class T >
Linked_list< T >::Linked_list() {
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}


template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L) {
    _length = L.size();
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

	if (!L.empty()){
		position p = L.last();
		for (int i=0; i <= L._length; i++){
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}

template< class T >
Linked_list< T >::~Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p){
	position temp = new List_node<T>;
	temp->_value = a;

	temp->_pNext = p;
	temp->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = temp;
	p->_pPrev = temp;

	_length++;
}

template< class T >
void Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
}

template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L){
	if (this != &L){
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}

template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const{
	if (L.size() != _length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}



#endif // _LINKED_LIST_H

