#include <iostream>
#include "listav.h"

using namespace std;
void stampaLista(Lista &l){
	cout<<"[";Lista::posizione indice;

	for (indice = l.primoLista();((!l.fineLista(indice)) && (indice < DIMENSIONE));indice = l.succLista(indice)){
		cout << l.leggiLista(indice).getTitolo();
		if (!l.fineLista(l.succLista(indice)))
			cout << ", ";
	}
	cout<<"]\n";
}
