#include <stdio.h>
#include <iostream>
#include "listav.h"
#include "serviziolv.h"
#include "libro.h"

using namespace std;
	int main(){
	Lista l;
	Lista::posizione indiceElemento = l.primoLista();
	Libro libro;
	libro.setTitolo("Primo");
	l.insLista(libro,indiceElemento=l.succLista(indiceElemento));
	libro.setTitolo("Secondo");
	l.insLista(libro,indiceElemento=l.succLista(indiceElemento));
	libro.setTitolo("Secondo");
	l.insLista(libro,indiceElemento=l.succLista(indiceElemento));
	libro.setTitolo("Quarto");
	l.insLista(libro,indiceElemento=l.succLista(indiceElemento));
	cout <<"\nL\'attuale lista e\': ";
	stampaLista(l);
	cout <<"\nOra inserisco l\'elemento Dieci nella seconda posizione...\n";
	libro.setTitolo("Dieci");
	l.insLista(libro,l.succLista(l.primoLista()));
	cout << "\nLista inserita: " << endl;
	stampaLista(l);
	cout << "\nEpurazione lista: " << endl;
	epurazioneLista(l);
	stampaLista(l);
	return 0;
}

