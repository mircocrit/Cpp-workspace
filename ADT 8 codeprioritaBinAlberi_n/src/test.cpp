/*
 * test.cpp
 *
 *  Created on: 29 dic 2018
 *      Author: utente
 */
#include "codaPriorita.h"
int main(int argc , char *argv[])
{
	CodaPriorita<int> cp;
	cp.inserisci(9);
	cp.inserisci(5);
	cp.inserisci(33);
	cp.inserisci(55);
	cp.inserisci(40);
	cp.inserisci(6);
	cp.inserisci(23);
	cp.inserisci(17);
	cp.inserisci(10);
	cp.inserisci(35);
	cp.inserisci(20);
	cp.inserisci(11);
	cp.inserisci(1);
	std::cout << "Min > " << cp.min() << std::endl;
	cp.cancellaMin();
	std::cout << "Min > " << cp.min() << std::endl;

	getchar();
	return 0;
}

