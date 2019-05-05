/*
2. Dato un albero n-ario di elementi di tipo intero, implementare in C++ la funzione
int max level(Tree<int>) che restituisce in output il livello k dell’albero per il quale la somma di tutti i nodi di livello k è massima.
Prevedere una funzione nel main che contenga una procedura di inserimento automatico e successivamente il test della funzione implementata.
 */
#include "linkAlberi.h"
#include "tree.h"
#include "codaLineare.h"
#include "coda.h"
#include "Tree.h"

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

template<class P>
int maxLevel(Tree<int,P> &L)
{
	int max = L.readNode(L.root()) ,
	somma_liv_corrente = 0 ,liv_corrente = 0 , livello_max = 0;

	Coda<typename Tree<int,P>::node> tmp;

	tmp.inCoda(L.root());
	while(!tmp.codaVuota())
	{
		LinkAlberi<int>::node p = tmp.leggiCoda();
		tmp.fuoriCoda();
		if(liv_corrente!=L.getLivello(p))
		{
			if(max<somma_liv_corrente)
			{
				max = somma_liv_corrente;
				livello_max = liv_corrente;
			}
			liv_corrente++;
			somma_liv_corrente = 0;
		}
		somma_liv_corrente += L.readNode(p);

		p = L.firstChild(p);
		while(!L.lastSibling(p))
		{
			tmp.inCoda(p);
			p = L.nextSibling(p);
		}
	}

	return livello_max;
}


#endif /* FUNZIONI_H_ */
