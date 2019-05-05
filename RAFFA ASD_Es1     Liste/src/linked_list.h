#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "linear_list.h"

template<class T>
class Linked_list;

template< class T >
class List_node
{
	friend class Linked_list<T>;
 private:
	T _value;
	List_node<T> * _pPrev;
	List_node<T> * _pNext;
};




template< class T >
class Linked_list : public Linear_list<T, List_node<T>*>
{
 public:
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_node<T>*>::position position;

	// costruttori
	Linked_list();
	Linked_list(int);
	// costruttore per copia
	Linked_list(const Linked_list<T>& );
	//distruttore
	~Linked_list();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);
	////
	void inverti(Linked_list<T>&);
	bool palindroma(Linked_list<T>&);
	void inserisci(const value_type&);
	void inserisciListaOrdinata(const value_type&);
	bool ricerca(const value_type&);
	void fusioneListe(const Linked_list<T>&,const Linked_list<T>&);
	void ordinaLista();
	void clear();
	int numElem(position , position);
	void exchange(position, position);
	value_type min();
	value_type max();
	void moveMinMax();
	void eliminaDaLista(const Linked_list<T>&);
	////
	int size() const
	{
		return _length;
	};

	// sovraccarico di operatori
	Linked_list<T>& operator=(const Linked_list<T>&); // the assignment operator
	bool operator==(const Linked_list<T> &) const; // tests two list for equality
	bool operator!=(const Linked_list<T> &) const;

 private:
	List_node<T> * _pHead;
	int _length; // the length of the list
};

template< class T >
Linked_list< T >::Linked_list()
{
	_pHead = new List_node<T>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}


template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L)
{
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
Linked_list< T >::~Linked_list()
{
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class T >
void Linked_list< T >::create()
{
	if (empty())
			_length = 0;
}

template< class T >
bool Linked_list< T >::empty() const
{
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position
Linked_list< T >::begin() const
{
	return (_pHead->_pNext);
}

template< class T >
typename Linked_list< T >::position
Linked_list< T >::last() const
{
	return (_pHead->_pPrev);
}


template< class T >
typename Linked_list< T >::position
Linked_list< T >::next(position p) const
{
	return(p->_pNext);
}

template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const
{
	if (p != _pHead)
		return(p->_pPrev);
}

template< class T >
bool Linked_list< T >::end(position p) const
{
	return(p == _pHead);
}

template< class T >
typename Linked_list< T >::value_type Linked_list< T >::read(position p) const
{
	if (!end(p))
		return(p->_value);
}

template< class T >
void Linked_list< T >::write(const value_type &a, position p)
{
	if (!end(p))
    p->_value = a;
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p)
{
	position t = new List_node<T>;
	t->_value = a;

	t->_pNext = p;
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
}

template< class T >
void Linked_list< T >::erase(position p)
{
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
	_length--;
}

template <class T>
void Linked_list<T>::inverti(Linked_list<T> &L)
{
	if(!empty())
	{
	position inizio = L.begin();
	position fine = L.last();

	while(inizio != fine && inizio != fine->_pPrev)
	{
		value_type temp;
		temp = inizio->_value;
		inizio->_value = fine->_value;
		fine->_value = temp;

		inizio = L.next(inizio);
		fine = L.previous(fine);
	}
	if (L.size() % 2 == 0)
	{
		value_type temp = inizio->_value;
		inizio->_value = fine->_value;
		fine->_value = temp;
	}
	}
}

template <class T>
bool Linked_list<T>::palindroma(Linked_list<T> &L)
{
	Linked_list<T> temp;

	position fine = L.last();
	while(!L.end(fine))
	{
		temp.inserisci(L.read(fine));
		fine = L.previous(fine);
	}

	return L == temp;
}

template <class T>
void Linked_list<T>::inserisci(const value_type &V)
{
	position nodo = new List_node<T>;
	nodo->_value = V;
	if(empty())
	{
		_pHead->_pNext = nodo;
		nodo->_pNext = _pHead;
		_pHead->_pPrev = nodo;
		nodo->_pPrev = _pHead;

	}
	else
	{
		nodo->_pNext = _pHead;
		nodo->_pPrev = _pHead->_pPrev;
		_pHead->_pPrev->_pNext = nodo;
		_pHead->_pPrev = nodo;
	}
	_length++;

}

template <class T>
void Linked_list<T>::inserisciListaOrdinata(const value_type &V)
{
	position nodo = new List_node<T>;

	nodo->_value = V;
	if(empty())
	{
		_pHead->_pNext = nodo;
		nodo->_pNext = _pHead;
		_pHead->_pPrev = nodo;
		nodo->_pPrev = _pHead;
	}

	else
	{
		position p = begin();
		while(!end(p))
		{

		if(read(p) < V)
		{
			nodo->_pPrev = p;
			nodo->_pNext = p->_pNext;
			p->_pNext->_pPrev = nodo;
			p->_pNext = nodo;

		}
		/*
		if(read(p) > V)
		{
			nodo->_pNext = p;
			nodo->_pPrev = p->_pPrev;
			p->_pPrev->_pNext = nodo;
			p->_pPrev = nodo;
		}
		*/
			p = next(p);
		}
	}

	_length++;
}

template <class T>
bool Linked_list<T>::ricerca(const value_type &V)
{
	position p = begin();
	while(!end(p))
	{
		if(read(p) == V)
			return true;
		p = next(p);
	}
	return false;

}

template <class T>
void Linked_list<T>::clear()
{
	position p = this->begin();
	while(!this->empty())
	{
		this->erase(p);
		p = this->next(p);
	}
}

template <class T>
int Linked_list<T>::numElem(position p1 , position p2)
{
	int cont = 0 ;
	bool trovato = false;
	position p = this->begin();
	while(!this->end(p) && trovato == false)
	{
		if(p == p1)
		{
			trovato = true;
			p = p1;
			cont = 1;
		}
		p = this->next(p);
	}
	while(p <= p2)
	{
		cont++;
		p = this->next(p);
	}
	return cont;
}

template <class T>
void Linked_list<T>::exchange(position p1 , position p2)
{
	value_type temp = p1->_value;
	p1->_value = p2->_value;
	p2->_value = temp;

}

template <class T>
typename Linked_list<T>::value_type Linked_list<T>::min()
{
	position p = this->begin();
	value_type min = p->_value;
	while(!this->end(p))
	{
		if(p->_value < min)
			min = p->_value;
		p = this->next(p);
	}
	return min;
}

template <class T>
typename Linked_list<T>::value_type Linked_list<T>::max()
{
	position p = this->begin();
	value_type max = p->_value;
	while(!this->end(p))
	{
		if(p->_value > max)
			max = p->_value;
		p = this->next(p);
	}
	return max;
}

template <class T>
void Linked_list<T>::moveMinMax()
{
	value_type max = this->max() , min = this->min();
	this->begin()->_value = min;
	this->last()->_value = max;
}

template <class T>
void Linked_list<T>::eliminaDaLista(const Linked_list<T> &L)
{
	position pl = L.begin() , p = this->begin();

	while(!this->end(p))
	{
		if(p->_value == pl->_value)
			this->erase(p);
		p = this->next(p);
		pl = this->next(pl);
	}
}

template <class T>
void Linked_list<T>::fusioneListe(const Linked_list<T> &L1, const Linked_list<T> &L2 )
{
	position p1 = L1.begin();
	position p2 = L2.begin();
	position p3 = begin();
	while(!L1.end(p1) && !L2.end(p2))
	{
		value_type elem1 = L1.read(p1);
		value_type elem2 = L2.read(p2);
		if(elem1 < elem2)
		{
			inserisci(elem1);
			p1 = L1.next(p1);
		}
		else
		{
			inserisci(elem2);
			p2 = L2.next(p2);
		}
		p3 = next(p3);
	}
	while(!L1.end(p1))
	{
		inserisci(L1.read(p1));
		p1 = L1.next(p1);
		p3 = next(p3);
	}
	while(!L2.end(p2))
	{
		inserisci(L2.read(p2));
		p2 = L2.next(p2);
		p3 = next(p3);
	}

}

template <class T>
void Linked_list<T>::ordinaLista()
{
	//int n = this->size() , i = 0 , j = 0;
	position ip = this->begin() , jp ;
	value_type key;

	/*
	ip = this->next(ip);
	for(i=1;i<n;i++)
	{
		key = ip->_value;
		j = i - 1;
		jp = this->previous(ip);
		while(j >= 0 && jp->_value > key)
		{
			jp->_pNext->_value = jp->_value;
			j = j - 1;
			jp = this->previous(jp);
		}
		jp->_pNext->_value = key;
		ip = this->next(ip);
	}
	*/
	ip = this->next(ip);
	while(!this->end(ip))
	{
		key = ip->_value;
		jp = this->previous(ip);
		while(jp >= this->begin() && jp->_value > key)
		{
			jp->_pNext->_value = jp->_value;
			jp = this->previous(jp);
		}
		jp->_pNext->_value = key;
		ip = this->next(ip);
	}

}

template <class T>
Linked_list<T>& Linked_list<T>::operator =(const Linked_list &L)
{
	if(&L == this)
		return *this;
	else
	{
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

		if(!L.empty())
		{
			position p = L.begin();
			while(!L.end(p))
			{
				inserisci(L.read(p));
				p = L.next(p);
			}
		}
	}
	return *this;
}
/*
template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L)
{
	if (this != &L){
		_length = L.size();

		_pHead = new List_node<T>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

        cout << L.empty();
        cout << L.size();
		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}
*/

template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const
{
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

template <class T>
bool Linked_list<T>::operator !=(const Linked_list<T> &L)const
{
	if(L.size() != this->_length)
		return true;
	position p , pl;
	p = this->begin();
	pl = L.begin();
	while(!this->end(p))
	{
		if(p->_value != pl->_value)
			return true;
		p = this->next(p);
		pl = L.next(pl);
	}
	return false;
}
#endif // _LINKED_LIST_H
