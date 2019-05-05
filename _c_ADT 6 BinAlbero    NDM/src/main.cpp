#include "Bin_treec.h"
#include <iostream>

using namespace std;


int main(){
	Bin_treec<int> T;
	typename Bin_treec<int>::Nodo n1, n2;
	T.ins_root(n1);
	T.write(T.root(),1);
	cout << T;
	n1 = T.root();

	T.ins_sx(n1);
	T.ins_dx(n1);
	cout << T;

	T.write(T.sx(n1),2);
	cout << T;

	n1 = T.dx(n1);
	T.write(n1, 3);
	cout << T;

	T.ins_dx(n1);
	T.write(T.dx(n1), 4);
	cout << T;
	//T.print();

	system("pause");
	return 0;
}

