/***************************************************************************
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

#ifndef _SET_SORTEDLIST_H
#define _SET_SORTEDLIST_H

#include "linked_list.h"
#include "set.h"

template< class T >
class SetList : public Set<T> {

 public:
  typedef typename Linear_list<T, List_node<T>*>::value_type value_type;
 	typedef typename Linear_list<T, List_node<T>*>::position position;
  // costruttori
	SetList() {};
	// costruttore per copia
	SetList(const SetList<T>& b) {set=b.set;};
	//distruttore
	//~SetList() {};

	// operatori
	// operators
	void create() {set.create();};
	bool empty() const {return set.empty();};
	bool contains(const T & elem) const {
		position p=find(elem);
		if (set.end(p)) {
			return false;
		} else {
			return (set.read(p)==elem);
		}
	};
	void insert(const T & elem) {
		position p=find(elem);
		set.insert(elem, p);
	};
	void remove(const T & elem) {
		position p=find(elem);
		if (!set.end(p)) {
			set.erase(p);
		}
	};
	void unionSet(const Set<T> & b);
	void intersectionSet(const Set<T> & b);
	void differenceSet(const Set<T> & b);

	// sovraccarico di operatori
	SetList<T>& operator=(const SetList<T>& b) {set=b.set;}; // the assignment operator
	bool operator==(const SetList<T> & b) const {return set==b.set;}; // tests two sets for equality
 private:
	 Linked_list<T> set;
   position find(const T & elem) const {
    position p=set.begin();
    while (!set.end(p)) {
      T e=set.read(p);
      if (e<elem) {
        p=set.next(p);
      } else return p;
    }
    return p;
  };
};

template< class T>
void SetList<T>::unionSet(const Set<T> & b) {
  return;
}

template< class T>
void SetList<T>::intersectionSet(const Set<T> & b) {
  return;
}

template< class T>
void SetList<T>::differenceSet(const Set<T> & b) {
  return;
}


#endif // _SET_SORTEDLIST_H
