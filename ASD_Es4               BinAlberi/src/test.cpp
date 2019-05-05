/*
 * test.cpp
 *
 *  Created on: 07 gen 2019
 *      Author: utente
 *  Dato un albero binario di elementi di tipo intero, implementare in C++ la funzione int
	multipli(Tree<int> T) che modifica l’etichetta di ogni nodo n dell’albero
	memorizzandoci il numero dei nodi pari presenti nel sottoalbero radicato in n.
	Prevedere una funzione nel main che contenga una procedura di inserimento automatico
	e successivamente il test della funzione implementata.
 */
#include "funzioni.h"
#include <ctime>

void inserimento(LinkBinAlberi<int> &);

int main(int argc, char *argv[])
{
	LinkBinAlberi<int> prova;
	inserimento(prova);
	std::cout << "prima\n" << prova;
	multipli(prova);
	std::cout << "dopo\n" << prova;

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
