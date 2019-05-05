#include "sorted_linked_list.h"
#include <iostream>

using namespace std;




int main() {

  Sorted_linked_list<string> a;
  a.insert("cane");
  a.insert("zebra");
  a.insert("giraffa");
  a.insert("gatto");
  a.insert("elefante");
  cout << a;

  Sorted_linked_list<string> b;
  b.insert("formica");
  b.insert("ape");
  b.insert("mosca");
  cout << b;

  Linked_list<string> c;
  a.merge(b, c);
  cout << c;

  cout << (a.search("gatto") ? "VERO" : "FALSO") << endl;
  cout << (a.search("ape") ? "VERO" : "FALSO") << endl;

  return 0;
}
