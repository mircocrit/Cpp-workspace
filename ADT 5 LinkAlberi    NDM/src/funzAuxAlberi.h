/*
 * funzAuxAlberi.h
 *
 *  Created on: 29 dic 2018
 *      Author: utente
 */

#ifndef FUNZAUXALBERI_H_
#define FUNZAUXALBERI_H_

#include "linkAlberi.h"

template <class I>
int profondita(LinkAlberi<I> &L, typename LinkAlberi<I>::node n)
{
	typename LinkAlberi<I>::node p;
	int max , temp;
	if(L.leaf(n))
		return 0;
	else
	{
		p = L.firstChild(n);
		max = 0;
		while(L.lastSibling(p))
		{
			temp = profondita(L,p);
			if(max <= temp)
				max = temp;
			p = L.nextSibling(p);
		}
		max++;
	}
	return max;
}

template <class I>
int larghezza(LinkAlberi<I> &L, typename LinkAlberi<I>::node n)
{
	int count = 1;
	int larghezza = 1;
	Coda<typename LinkAlberi<I>::node> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		typename LinkAlberi<I>::node p = temp.leggiCoda();
		temp.fuoriCoda();
		typename LinkAlberi<I>::node v = L.firstChild(p);
		while(v)
		{
			temp.inCoda(v);
			v = L.nextSibling(v);
		}
		count -= 1;
		if(count == 0)
		{
			count = temp.getSize();
			if(count > larghezza)
				larghezza = count;
		}
	}
	return larghezza;
}

template <class I>
int contaFigli(LinkAlberi<I> &L, typename LinkAlberi<I>::node n)
{
	int count = 0;
	if(n->_parent == nullptr && n->_firstChild == nullptr)
		return 0;
	if(n->_firstChild == nullptr)
		return 0;
	else
	{
		typename LinkAlberi<I>::node p = L.firstChild(n);
		count = 1;
		while(!L.lastSibling(p))
		{
			count++;
			p = L.nextSibling(p);
		}
	}
	return count;
}

template <class I>
int numFoglie(LinkAlberi<I> &L, typename LinkAlberi<I>::node n)
{
	if(L.empty())
		return 0;

	if(L.leaf(n))
		return  1 + numFoglie(n->_nextSibling);
	else
		return numFoglie(n->_firstChild) + numFoglie(n->_nextSibling);

}

#endif /* FUNZAUXALBERI_H_ */
