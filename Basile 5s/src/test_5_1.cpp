#include "linked_list.h"
#include <iostream>

using namespace std;

int main() {
  Linked_list<string> l;
  l.insert("cane",l.begin());
  l.insert("zebra",l.begin());
  l.insert("giraffa",l.begin());
  l.insert("gatto",l.begin());
  l.insert("elefante",l.begin());
  cout << l;
  cout << "list size: " << l.size() << endl;
  l.reverse();
  cout << "list reverse: ";
  cout << l;
  cout << "list palindroma: " << (l.palindrome() ? "VERO" : "FALSO") << endl;
  Linked_list<string> a;
  a.insert("b",a.begin());
  a.insert("a",a.begin());
  a.insert("c",a.begin());
  a.insert("a",a.begin());
  a.insert("b",a.begin());
  cout << a;
  cout << "list palindroma: " << (a.palindrome() ? "VERO" : "FALSO") << endl;
  return 0;
}
