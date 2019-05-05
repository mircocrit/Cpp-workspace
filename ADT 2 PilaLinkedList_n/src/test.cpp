/*
 * test.cpp
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */

#include "pila.h"

int main (int argc , char *argv[])
{
	Pila<int> prova;

	prova.inPila(1);
	prova.inPila(2);
	prova.inPila(3);

	Pila<int> prova2(prova);

	std::cout << prova2.leggiPila() << " ";
	prova2.fuoriPila();
	std::cout << prova2.leggiPila() << " ";
	prova2.fuoriPila();
	std::cout << prova2.leggiPila() << "\n";

	/*
	Pila<int> prova3;

	prova3 = prova;

	std::cout << prova3.leggiPila() << " ";
	prova3.fuoriPila();
	std::cout << prova3.leggiPila() << " ";
	prova3.fuoriPila();
	std::cout << prova3.leggiPila() << "\n";
	*/

	//prova.stampaPila();

	getchar();
	return 0;
}
