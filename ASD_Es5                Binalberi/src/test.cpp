/*
 * test.cpp
 *
 *  Created on: 07 gen 2019
 *      Author: utente
 */
#include "funzioni.h"
#include <ctime>

void inserimento(LinkBinAlberi<int> &);

int main(int argc , char *argv[])
{
	LinkBinAlberi<int> prova;
	int n = 0;

	inserimento(prova);
	std::cout << prova;
	/*
	for(int i=0;i<4;i++)
	{
	std::cin >> n;
	std::cout << "nodi di livello K il cui valore dispari > " << odd(prova,n) << std::endl;
	}
	*/
	//std::cout << "numero di foglie il cui valore e' pari > " << evenLeafs(prova) << std::endl;
	std::cout << "numero di foglie che hanno come genitore un nodo il cui valore e' pari > " << leafsWithEvenParent(prova) << std::endl;

	getchar();
	getchar();
	return 0;
}

void inserimento(LinkBinAlberi<int> &A)
{
	srand(time(NULL));
	int numNodi = 10 , conta = 0;

	Coda<LinkBinAlberi<int>::node> tmp;
	A.insRoot(rand()%10);

	LinkBinAlberi<int>::node p = A.root();
	tmp.inCoda(p);

	while(!tmp.codaVuota() && conta < numNodi-1)
	{
		p = tmp.leggiCoda();
		tmp.fuoriCoda();

		A.insSx(p,rand()%10);
		conta++;

		A.insDx(p,rand()%10);
		conta++;

		if(!A.sxEmpty(p))
			tmp.inCoda(A.sx(p));
		if(!A.dxEmpty(p))
			tmp.inCoda(A.dx(p));
	}
}

