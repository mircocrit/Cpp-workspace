/*
 * test.cpp
 *
 *  Created on: 07 gen 2019
 *      Author: utente
 *  Data una pila di interi, implementare in C++ una funzione che restituisca una nuova
	pila i cui elementi corrispondano a quelli presenti nella pila data e siano ordinati dall’alto
	(top dello stack) al basso.
	Prevedere una funzione nel main che contenga una procedura di inserimento automatico
	e successivamente il test della funzione implementata.
 */

#include "funzioni.h"
#include <ctime>

void inserimento(Pila<int> &);
void testOrdinaPila(Pila<int> &);

int main(int argc , char *argv[])
{
	Pila<int> prova;

	testOrdinaPila(prova);
	std::cout << "Dopo" << "\n";
	std::cout <<prova<<std::endl;
	std::cout << "Dopo" << "\n";
	std::cout <<prova<<std::endl;
	getchar();
	return 0;
}

void inserimento(Pila<int> &P)
{
	srand(time(NULL));

	int n = 10;

	for(int i=0;i<n;i++)
		P.inPila(rand()%50);
}

void testOrdinaPila(Pila<int> &P)
{
	inserimento(P);
	ordinaPila(P);
}
