#include "matrice.h"
#include <iostream>

int main(){
	matrice A(3,2), T(2,3);
	A.random();
	A.stampa();
	T = A.trasposta();
	T.stampa();

	matrice B(4,4);
	B.stampa();
	B = T;
	B.stampa();

	matrice C(3,2);
	C.random();
	C.stampa();
	matrice D(2,3);
	D.random();
	D.stampa();
	matrice E=C.prodotto(D);
	E.stampa();
	system("pause");
	return 0;
}
