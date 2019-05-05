/*
4. Dato un albero binario di elementi di tipo intero, implementare in C++ la funzione int
multipli(Tree<int> T) che modifica l’etichetta di ogni nodo n dell’albero
memorizzandoci il numero dei nodi pari presenti nel sottoalbero radicato in n.
Prevedere una funzione nel main che contenga una procedura di inserimento automatico
e successivamente il test della funzione implementata.
 */

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linkBinAlberi.h"
#include "Bin_Tree.h"

template <class P>
int contaNodiPari(Bin_tree<int,P> &A , typename Bin_tree<int,P>::Nodo n , int &cont)
{
	if( A.read(n)%2 == 0)
		cont++;

	if(!A.sxEmpty(n))
		contaNodiPari(A,A.sx(n),cont);
	if(!A.dxEmpty(n))
		contaNodiPari(A,A.dx(n),cont);
	return cont;
}

template <class P>
void aggiornaAlbero(Bin_tree<int,P> &A, typename Bin_tree<int,P>::Nodo n)
{
	int cont = 0;
	if( A.read(n)%2 == 0)
		A.write(n,contaNodiPari(A,n,cont)-1);
	else
		A.write(n,contaNodiPari(A,n,cont));
	if(!A.sxEmpty(n))
		aggiornaAlbero(A,A.sx(n));
	if(!A.dxEmpty(n))
		aggiornaAlbero(A,A.dx(n));
}

template <class P>
void multipli(Bin_tree<int,P> &A)
{
	aggiornaAlbero(A,A.root());
}


#endif /* FUNZIONI_H_ */
