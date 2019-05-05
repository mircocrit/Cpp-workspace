#include "hanoi_iter.h"

int main () {
  int numerodischi,counter=0;
  cin >> numerodischi;
  cout << "per " << numerodischi << " dischi i movimenti richiesti sono:" << endl;
  move(numerodischi, origine, intermedio, destinazione,counter);
  cout<<counter;
  system("pause");
  return 0;
}

