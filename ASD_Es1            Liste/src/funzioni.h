/*
 * 1. Data una lista di elementi di tipo intero, implementare in C++ le seguenti funzioni:
• int freq(List<int> &L, int k): restituisce il numero di occorrenze dei multipli di k nella lista L
• void hist(List<int> &L): stampa la frequenza di ogni elemento presente nella lista L
• void remp(List<int> &L): rimuove dalla lista L tutti gli elementi seguiti da un numero dispari
Prevedere una funzione nel main che contenga una procedura di inserimento automatico e successivamente il test delle funzioni implementate
 */

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "linked_list.h"
#include "linear_list.h"

template<class P>
int freq(Linear_list<int,P> &L , int k)
{
	int contaOcc = 0;
	typename Linear_list<int,P>::position p = L.begin();

	while(!L.end(p))
	{
		if(L.read(p) % k == 0)
			contaOcc++;
		p = L.next(p);
	}
	return contaOcc;
}

template<class P>
void hist(Linear_list<int,P> &L)
{
	Linked_list<int>::position p = L.begin();
	int freq = 0;

	while(!L.end(p))
	{
		freq = 0;
		int v = L.read(p);
		Linked_list<int>::position q = L.begin();
		while(!L.end(q))
		{
			if(v == L.read(q))
				freq++;
			q = L.next(q);
		}
		std::cout << v << " presente > "  << freq << " volte\n";
		p = L.next(p);
	}
}

template<class P>
void remp(Linear_list<int,P> &L)
{
	Linked_list<int>::position p = L.begin();

	while(!L.end(p))
	{
		if(L.read(L.next(p)) % 2 != 0)
		{
			p = L.next(p);
			L.erase(L.previous(p));
		}
		else
			p = L.next(p);
	}
}


#endif /* FUNZIONI_H_ */
