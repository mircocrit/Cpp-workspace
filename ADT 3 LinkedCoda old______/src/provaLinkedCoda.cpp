/*
 * provaLinkedCoda.cpp
 *
 *  Created on: 24 ott 2018
 *      Author: utente
 */
#include "coda.h"
#include <cstdlib>


int main(int argc , char *argv[])
{
	Coda<int> c1;
	for(int i=0;i<5;i++)
		c1.inCoda(i+1);
	std::cout << c1.getSize() << std::endl;

	while(!c1.codaVuota())
	{
		std::cout << c1.leggiCoda() << std::endl;
		c1.fuoriCoda();
	}

	/*
	std::cout << c1.leggiCoda() << std::endl;
	std::cout << c1.leggiCoda() << std::endl;
	*/
	system("pause");
	return 0;
}
