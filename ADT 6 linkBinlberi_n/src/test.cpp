/*
 * test.cpp
 *
 *  Created on: 28 dic 2018
 *      Author: utente
 */
#include "metodiAuxBinAlberi.h"
#include "linkBinAlberi.h"

int main(int argc , char *argv[])
{

	LinkBinAlberi<int> bin1;

	bin1.insRoot(0);
	bin1.insSx(bin1.root(),1);
	bin1.insDx(bin1.root(),2);
	bin1.insSx(bin1.sx(bin1.root()),3);
	bin1.insDx(bin1.sx(bin1.root()),4);

	bin1.print();
	//bin1.erase(bin1.sx(bin1.root()));
	//std::cout << bin1;

	std::cout << "Bin1:\n" << bin1;

	std::cout << "preVisita:" << std::endl;
	bin1.previsita(bin1.root());

	std::cout << "postVisita:" << std::endl;
	bin1.postvisita(bin1.root());

	std::cout << "simmetrica:" << std::endl;
	bin1.visitaSimmetrica(bin1.root());

	std::cout << "ampiezza:" << std::endl;
	bin1.visitaAmpiezza(bin1.root());


	getchar();
	return 0;
}
