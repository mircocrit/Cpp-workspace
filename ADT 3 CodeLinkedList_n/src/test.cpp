/*
 * test.cpp
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */
#include "coda.h"

int main(int argc , char *argv[])
{

	Coda<int> prova;

	prova.inCoda(1);
	prova.inCoda(2);

	Coda<int> prova2(prova);
	std::cout << "prova2 :\n";
	std::cout << prova2.leggiCoda()  << " ";
	prova2.fuoriCoda();
	std::cout << prova2.leggiCoda()  << " ";

	Coda<int> prova3 = prova;

	std::cout << "\nprova3 :\n";
	std::cout << prova3.leggiCoda()  << " ";
	prova2.fuoriCoda();
	std::cout << prova3.leggiCoda()  << " ";

	getchar();
	return 0;
}
