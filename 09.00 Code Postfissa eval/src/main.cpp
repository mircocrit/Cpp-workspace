#include <cstring>
#include <iostream>
#include "codavt.cpp"
#include "pilavt.h"

using namespace std;

//prendo una espressione in postfissa scritta su una coda e la valuto servendomi di una pila

int main() {
	char *a = "1 5 + 6 * 2 3 * +";  //(1+5)*6 + (2*3)	=42
	Coda<char> coda(strlen(a));
	coda.insert(a);
	cout << coda.valuta_polacca() << endl;
	system("pause");
	return 0;
}


