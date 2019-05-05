#include "hanoi.h"

int main () {
  int numerodischi;
  cin >> numerodischi;
  cout << "per " << numerodischi << " dischi i movimenti richiesti sono:" << endl;
  move(numerodischi, origine, intermedio, destinazione);

  system("pause");
  return 0;
}
