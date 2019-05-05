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

	////////////////////////////////////////
	void inverti_valori();
	bool palindroma();
	position ordered_position( const value_type);	//il metodo restituisce la posizone in cui inserire il nodo in base al valore inserito da utente, ordinato per valore
	void insert_ordered(value_type &a){		insert(a,ordered_position(a));		set_size(size()+1);};//inserisce elemento di tipo valuetype in ordine crescente

	position index(int ind);		//restituisce la posizione corrispondente ad un creto indice
	int position_c(position);	// restitisce l'indice ad una certa posizoine
	position ricerca_binaria(const value_type);
	Linked_list<T>& merge(Linked_list<T>&,Linked_list<T>&);
	void Insertion_sort();

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template< class T >
void Linked_list<T>::inverti_valori(){
	 position  p_begin=	begin();
	 position  p_end=	last();
	  while(p_begin!= p_end &&		 p_begin!= p_end->prev()){//gestire caso pari
		  value_type temp=read(p_end);
		  write(read(p_begin),	p_end);   	//1	//VALORE				PUNTATORE
		  write(temp,	p_begin);	//0

		  p_begin=	p_begin->next();	//PUNTATORI
		  p_end=	p_end->prev();
	}
}

template< class T >
typename Linked_list<T>::position Linked_list< T >::ordered_position(const value_type v){
	 position  p_begin=	begin();

	 while(p_begin!= last()){
		  if(read(p_begin)>v)
			  return p_begin;
		  else
			  p_begin=  p_begin->next();
	  }
	 return nullptr;
}



template< class T >
bool Linked_list<T>::palindroma(){
	Linked_list<T> *temp=this;
	temp->inverti_valori();
	return (*this==*temp);
}


template< class T >
typename Linked_list<T>::position Linked_list< T >::index(int ind){
	position  p_begin=begin();
	int count=0;
	if(0==ind)			return p_begin;
	do{
		p_begin= p_begin->next();
		count++;
		if(count==ind)			return p_begin;

	}while(p_begin!= last());
	return nullptr;
}

template< class T >
int Linked_list< T >::position_c(Linked_list<T>::position pos){
	position  p_begin=begin();
	int count=0;

	if(p_begin==pos)			return 0;
	do{
		p_begin= p_begin->next();
		count++;
		if(p_begin==pos)			return count;
	}while(p_begin!= last());
	return -1;
}


template< class T >
typename Linked_list<T>::position Linked_list< T >::ricerca_binaria(const value_type v){
	position  p_begin=	begin();
	position  p_end=	last();
	value_type first;
	while(p_begin!= p_end){
		position mid= index((position_c(p_begin) + position_c(p_end))/2);
		if(v==read(mid)){			return mid;
		}else{
			if(v>read(mid)){				p_begin=mid->next();}
			else{						p_end=mid->prev();}
		}
	}
	return nullptr;
}

template< class T >
Linked_list<T>& Linked_list< T >::merge(Linked_list<T>& L1,Linked_list<T>& L2){
	Linked_list<T> *L3=new Linked_list<T>;
	position p1=L1.begin();
	position p2=L2.begin();
	position p3=L3->begin();

	while(! L1.end(p1) && !L2.end(p2)){
		value_type elem1=L1.read(p1);
		value_type elem2=L2.read(p2);
		if(elem1<elem2){
			L3->insert(elem1,p3);
			p1=p1->next();
		}else{
			L3->insert(elem2,p3);
			p2=p2->next();
		}
		p3= p3->next();
	}
	while(! L1.end(p1)){
		L3->insert(L1.read(p1),p3);
		p1=p1->next();
		p3=p3->next();
	}
	while(! L2.end(p2)){
		L3->insert(L2.read(p2),p3);
		p2=p2->next();
		p3=p3->next();
	}
	return *L3;
}

//position index(int ind);
template< class T >
void Linked_list< T >::Insertion_sort(){
    value_type key;
    int i,j;
    int n=size();

    for(i=1;i<n;i++){			   					//for(i=1;i<n;i++){
    	key=read(index(i));								//key=arr[i];
        j=i-1;											//j=i-1;
        while(j>=0 && read(index(j))>key){				//while(j>=0 && arr[j]>key){
        	write(read(index(j)),	index(j+1));    		//arr[j+1]=arr[j];
        	j=j-1;											//j=j-1;
        }
        write(key,index(j+1));							//arr[j+1]=key;
    }
}



#endif // _LINKED_LIST_H

