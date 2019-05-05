#ifndef _LISTAVT_H
#define _LISTAVT_H

#include "linear_list.h"

template< class T >
class List_vector :					 public Linear_list<	T, int	>{
 public:
	typedef typename Linear_list<T, int>::value_type				 value_type;
	typedef typename Linear_list<T, int>::position					 position;

	List_vector() {	  		 		array_dimension_ = 10;				this->create();		};
	List_vector(int dim){	 		array_dimension_ = dim;		  		this->create();		};
	List_vector(const List_vector<T>& );
	~List_vector(){					delete elements_;}	;
	// OPERATORI
	void create(){		 						this->elements_ = new T[array_dimension_];		  this->length_ = 0;	 };
	bool empty() const{   						return(length_ == 0);};
	value_type read(position p) const{				if ( (0 < p) && (p < length_+1)) 			return(elements_[p-1]);  };
	void write(const value_type &a, position p){	if ( (0 < p) && (p < length_+1)) 			elements_[p-1] = a;      };
	position begin() const {						return(1);};
	bool end(position p) const{
		if ( (0 < p) && (p <= length_+1)) 			return( p == length_+1);
		else										return(false);		};
	position next(position p) const{
		if ( (0 < p) && (p < length_+1))			return(p+1);
		else										return(p);		};
	position previous(position p) const{
		if ( (1 < p) && (p < length_+1)) 			return(p-1);
		else										return(p);		};
	void insert(const value_type &, position);
	void erase(position);
	// sovraccarico di operatori
	List_vector<T>& operator=(const List_vector<T>&);
	bool operator==(const List_vector<T> &) const;

 private:
	void change_dimension_(T*& ,int ,int );
	value_type* elements_;
	int length_;
	int array_dimension_;
};

template< class T >
List_vector< T >::List_vector(const List_vector<T>& Lista) {
	this->array_dimension_ = Lista.array_dimension_;
	this->length_ = Lista.length_;
	this->elements_ = new T[array_dimension_];
	for (int i=0; i<Lista.array_dimension_; i++)
		this->elements_[i] = Lista.elements_[i];
}


template< class T >
void List_vector< T >::insert(const value_type &a, position p){
  if (length_ == array_dimension_){
    change_dimension_(elements_, array_dimension_, array_dimension_ * 2);
    array_dimension_ = array_dimension_ * 2;
  }
  if ( (0 < p) && (p <= length_+1)) {
		for (int i=length_; i>=p; i--)
			elements_[i] = elements_[i-1];				//metto l'i-1 nell i(IN ALTO)  11122133  12212113331
		elements_[p-1]=a;								//metto alla fine l'elemento a							-->
		length_++;
	}
}

template< class T >
void List_vector< T >::erase(position p){
  if ( (0 < p) && ( p < length_ + 1))
    if (!empty()) {
		for (int i=p-1;i<(length_-1);i++)
			elements_[i]=elements_[i+1];			//shift indietro		11122133 1 2212113331
		length_--;
		}
}

template<class T>
void List_vector< T >::change_dimension_(T*	&a, int vecchiaDim, int nuovaDim){

  T* temp = new T[nuovaDim];
  int number;
  if (vecchiaDim < nuovaDim)     number = vecchiaDim;
  	  else						     number = nuovaDim;
  for (int i=0; i<number; i++)
     temp[i]=a[i];
  delete [] a;
  a = temp;
}


template<class T>
List_vector<T>& List_vector<T>::operator=(const List_vector<T>& l){
	if (this != &l){   																				// no autoassegnamenti
		this->array_dimension_ = l.array_dimension_;
		this->length_ = l.length_;
		delete this->elements_;
		this->elements_ = new T[array_dimension_];
		for (int i=0; i<l.array_dimension_; i++)
			this->elements_[i] = l.elements_[i];
	}
	return *this;
}

template<class T>
bool List_vector<T>::operator==(const List_vector<T> &l) const{
	if (l.length_ != this->length_) 		return false;
    for (int i=0; i<this->array_dimension_; i++)
		if (this->elements_[i] != l.elements_[i])			return false;
	return true;
}

#endif // _LISTAVT_H

