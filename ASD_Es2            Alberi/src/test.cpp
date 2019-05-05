/*
 * test.cpp
 *
 *  Created on: 05 gen 2019
 *      Author: utente
 *  Dato un albero n-ario di elementi di tipo intero, implementare in C++ la funzione int
	max level(Tree<int>) che restituisce in output il livello k dell’albero per il quale la
	somma di tutti i nodi di livello k è massima.
	Prevedere una funzione nel main che contenga una procedura di inserimento automatico
	e successivamente il test della funzione implementata.
 */
#include "funzioni.h"
#include <ctime>

void inserimento(LinkAlberi<int> &);
void testMaxLevel(LinkAlberi<int> &);


int main(int argc , char *argv[])
{
	LinkAlberi<int> prova;
	inserimento(prova);
	std::cout << prova;
	testMaxLevel(prova);

	getchar();
	return 0;
}


void inserimento(LinkAlberi<int> &L)
{

	srand(time(NULL));

	L.insRoot(rand()%10);

	Coda<LinkAlberi<int>::node> tmp;
	tmp.inCoda(L.root());
	bool terminaInserimento = false;

	while(!tmp.codaVuota() && terminaInserimento == false )
	{
		int numFigli = rand()% 5;
		LinkAlberi<int>::node p = tmp.leggiCoda();
		tmp.fuoriCoda();

		L.insFirst(p,rand()%10);
		for(int i=0;i<numFigli-1;i++)
			L.insFirst(p,rand()%10);

		terminaInserimento = false;

		p = L.firstChild(p);
		while(!L.lastSibling(p))
		{
			tmp.inCoda(p);
			p = L.nextSibling(p);
		}

	}

}


void testMaxLevel(LinkAlberi<int> &L)
{
	std::cout << "livello con somma nodi piu' alta > " << maxLevel(L) << std::endl;
}

