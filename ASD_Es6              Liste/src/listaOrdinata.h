/*
6. Utilizzando una delle realizzazioni della ADT lista, realizzare in C++ la ADT
ListaOrdinata.h per la memorizzazione ordinata di elementi di tipo intero (gli elementi
compaiono in modo ordinato e sono ammesse più copie dello stesso elemento).
Bisogna realizzare la nuova struttura facendo uso degli operatori della ADT lista .
La ADT ListaOrdinata mette a disposizione i seguenti operatori:
• inserisci(S, elemento): inserisce l’elemento nella sequenza ordinata S
• rimuovi(S, elemento): rimuove la prima occorrenza dell’elemento dalla sequenza
S
• differenza(S1, S2): restituisce una nuova sequenza ordinata ottenuta
eliminando da S1 tutti gli elementi presenti in S2
• sottolista(S1, S2): restituisce true se la sottolista ordinata S1 è sottolista della
lista ordinata S2, false altrimenti
Prevedere un main che acquisisca automaticamente delle sequenze e mostri a video il
funzionamento degli operatori implementati.
7. Dato
 */

#ifndef LISTAORDINATA_H_
#define LISTAORDINATA_H_

#include "linked_list.h"

template <class I>
class ListaOrdinata :public Linked_list<I>
{
public:
	typedef typename Linked_list<I>::value_type valore;
	typedef typename Linked_list<I>::position posizione;

	void inserisci(ListaOrdinata<I> &,const valore);
	void rimuovi(ListaOrdinata<I> &, const valore);
	ListaOrdinata<I>& differenza(ListaOrdinata<I> &, ListaOrdinata<I> &);
	posizione sottoLista(ListaOrdinata<I> &, ListaOrdinata<I> &);
};

template <class I>
void ListaOrdinata<I>::inserisci(ListaOrdinata<I> &L, const valore elemento)
{
	posizione p = L.begin();
	while(!L.end(p) && L.read(p) < elemento)
		p = L.next(p);
	L.insert(elemento,p);
}

template <class I>
void ListaOrdinata<I>::rimuovi(ListaOrdinata<I> &L, const valore elemento)
{
	posizione p = L.begin();
	bool trovato = false;
	while(!L.end(p) && trovato == false)
	{
		if(L.read(p) == elemento)
		{
			trovato = true;
			L.erase(p);
		}
		p = L.next(p);
	}

}

template <class I>
ListaOrdinata<I>& ListaOrdinata<I>::differenza(ListaOrdinata<I> &S1, ListaOrdinata<I> &S2)
{
	posizione ps1 = S1.begin();
	posizione ps2 = S2.begin();
	valore tmp;

	while(!S2.end(ps2))
	{
		tmp = S2.read(ps2);

		ps1 = S1.begin();
		while(!S1.end(ps1))
		{

			if(S1.read(ps1) == tmp)
			{
				ps1 = S1.next(ps1);
				S1.erase(S1.previous(ps1));
			}
			else
				ps1 = S1.next(ps1);
		}

		ps2 = S2.next(ps2);
	}

	return S1;
}

template <class I>
typename ListaOrdinata<I>::posizione ListaOrdinata<I>::sottoLista(ListaOrdinata<I> &P, ListaOrdinata<I> &T)
{
	//bool isSottolista = false;
	posizione i = T.begin();	//i--->n
	posizione n=T.last();			//n

	posizione j = P.begin();	//j---->m
	posizione m=P.last();		//m

	posizione k= T.begin();

	while(!T.end(i) && !P.end(j))
	{
		if(T.read(i) == P.read(j))
		{
			i = T.next(i);
			j = P.next(j);
		}
		else
		{
			k = T.next(k);
			i = k;
			j = P.begin();
		}
		/*if(ps2 > m)
		{
			std::cout << "primo\n";
			return k;
		}
		else
		{
		*/
			//std::cout << "secondo\n";

		//}
	}
	return i;
}

#endif /* LISTAORDINATA_H_ */
