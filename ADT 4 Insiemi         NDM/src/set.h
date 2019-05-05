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

#ifndef _SET_H
#define _SET_H

template< class T >
class Set {

 public:
	virtual void create() = 0;
	virtual bool empty() const = 0;
	virtual bool contains(const T & elem) const = 0;
	virtual void insert(const T & elem) = 0;
	virtual void remove(const T & elem) = 0;
	virtual void unionSet(const Set<T> & b) = 0;
	virtual void intersectionSet(const Set<T> & b) = 0;
	virtual void differenceSet(const Set<T> & b) = 0;
};

#endif
