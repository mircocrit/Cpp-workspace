#include "dequeue.h"
#include <iostream>

using namespace std;

int main() {
  Dequeue<int> d;
  d.addLast(10);
  d.addLast(11);
  d.addLast(12);
  d.addFirst(9);
  cout << d.getFirst() << endl;
  cout << d.getLast() << endl;
  d.removeFirst();
  cout << d.getFirst() << endl;
  d.removeLast();
  cout << d.getLast() << endl;
  return 0;
}
