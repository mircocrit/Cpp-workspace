/*
5. Fornire in un file util_bin_tree.cpp la realizzazione in C++ delle seguenti funzioni che operano su alberi binari di elementi di tipo intero:
• int odd(bintree<int> &T, int k): calcola e restituisce il numero di nodi di livello k il cui valore dispari
• int even leafs(bintree<int> &T): calcola e restituisce il numero di foglie il cui valore pari
• int leafs with even parent(bintree<int> &T): calcola e restituisce il numero di foglie che hanno come genitore un nodo il cui valore pari
Prevedere un main che acquisisca automaticamente un albero binario e mostri a video il test delle funzioni implementate.
 */

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linkBinAlberi.h"
#include "Bin_tree.h"

template <class P>
int odd(Bin_tree<int,P> &A , int k)
{
	int cont = 0;
	bool livelloSuperato = false;
	Coda<LinkBinAlberi<int>::node> tmp;

	tmp.inCoda(A.root());

	while(!tmp.codaVuota() && livelloSuperato == false)
	{
		LinkBinAlberi<int>::node p = tmp.leggiCoda();
		tmp.fuoriCoda();

		if(A.getlevel(p) > k)
			livelloSuperato = true;
		if(A.getlevel(p) == k && A.read(p)%2 != 0)
			cont++;


		if(!A.sxEmpty(p))
			tmp.inCoda(A.sx(p));
		if(!A.dxEmpty(p))
			tmp.inCoda(A.dx(p));
	}

	return cont;
}

template <class P>
int contFogliePari(Bin_tree<int,P> &A , typename Bin_tree<int,P>::Nodo n , int &cont)
{
	if(!A.sxEmpty(n))
		contFogliePari(A,A.sx(n),cont);
	if(!A.dxEmpty(n))
		contFogliePari(A,A.dx(n),cont);

	if(A.dxEmpty(n) && A.sxEmpty(n) && A.read(n)%2 == 0)
		cont++;
	return cont;
}

template <class P>
int contPadriPari(Bin_tree<int,P> &A ,typename Bin_tree<int,P>::Nodo n , int &cont)
{
	if(A.dxEmpty(n) && A.sxEmpty(n) && A.read(A.parent(n))%2 == 0)
		cont++;
	if(!A.sxEmpty(n))
		contPadriPari(A,A.sx(n),cont);
	if(!A.dxEmpty(n))
		contPadriPari(A,A.dx(n),cont);
	return cont;
}

template <class P>
int evenLeafs(Bin_tree<int,P> &A)
{
	int cont = 0;
	return contFogliePari(A,A.root(),cont);
}

template <class P>
int leafsWithEvenParent(Bin_tree<int,P> &A)
{
	int cont = 0;
	return contPadriPari(A,A.root(),cont);
}

#endif /* FUNZIONI_H_ */
