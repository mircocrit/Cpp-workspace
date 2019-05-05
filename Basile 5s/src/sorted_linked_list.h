/***************************************************************************
 *   Copyright (C) 2016 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H

#include "linked_list.h"

template< class T >
class Sorted_linked_list : public Linked_list<T>{
 public:
	typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_node<T>*>::position position;

	void insert(const value_type &);
  void merge(const Sorted_linked_list<T> &B, Linked_list<T> &C);
	bool search(const T &e);

};

template< class T >
bool Sorted_linked_list< T >::search(const T &e) {
	position p;
	p = Linked_list<T>::begin();
	while (!Linked_list<T>::end(p) && Linked_list<T>::read(p) < e)
		p = Linked_list<T>::next(p);
	return Linked_list<T>::read(p)==e;
}

template< class T >
void Sorted_linked_list< T >::merge(const Sorted_linked_list<T> &B, Linked_list<T> &C){
	position pa = Linked_list<T>::begin();
	position pb = B.begin();
	position p = C.begin();

	while(!Linked_list<T>::end(pa) && !B.end(pb)){
    std::cout << Linked_list<T>::read(pa) << " " << B.read(pb) << endl;
		if (Linked_list<T>::read(pa) < B.read(pb)){
			C.insert(Linked_list<T>::read(pa), p);
			pa = Linked_list<T>::next(pa);
		}
		else{
			C.insert(B.read(pb), p);
			pb = B.next(pb);
		}
	}

  while(Linked_list<T>::end(pa)) {
    C.insert(Linked_list<T>::read(pa), p);
    pa = Linked_list<T>::next(pa);
  }

  while (!B.end(pb)) {
    std::cout << B.read(pb) << endl;
    C.insert(B.read(pb), p);
    pb = B.next(pb);
  }
}

template< class T >
void Sorted_linked_list< T >::insert(const value_type &a){
	position p;
	p = Linked_list<T>::begin();
	while (!Linked_list<T>::end(p) && Linked_list<T>::read(p) < a)
		p = Linked_list<T>::next(p);
	Linked_list<T>::insert(a, p);
}



#endif // _LINKED_LIST_H
