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

#include "set_sortedList.h"
#include <iostream>

using namespace std;


int main(){
  SetList<int> set;
  set.insert(3);
  set.insert(4);
  set.insert(1);
  cout << "set contains 1?: " << set.contains(1) << endl;
  cout << "set contains 10?: " << set.contains(10) << endl;

  SetList<int> setc(set);
  cout << "setc contains 1?: " << setc.contains(1) << endl;
  setc.remove(1);
  cout << "set contains 1?: " << set.contains(1) << endl;
  cout << "setc contains 1?: " << setc.contains(1) << endl;
  cout << "set==setc?: " << (set==setc) << endl;
  SetList<int> setb=setc;
  cout << "setb contains 1?: " << setb.contains(1) << endl;
}
