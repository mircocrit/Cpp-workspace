/*
 * funzioni.h
 *
 *  Created on: 05 gen 2019
 *      Author: utente
 */
#include "linkAlberi.h"

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

int maxLevel(LinkAlberi<int> &L)
{
	int max = L.readNode(L.root()) , somma_liv_corrente = 0 ,liv_corrente = 0 , livello_max = 0;

	Coda<LinkAlberi<int>::node> tmp;

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
