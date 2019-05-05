/*
 * test.cpp
 *
 *  Created on: 05 gen 2019
 *      Author: utente
 *      Data una lista di elementi di tipo intero, implementare in C++ le seguenti funzioni:
• int freq(List<int> &L, int k): restituisce il numero di occorrenze dei multipli di
k nella lista L
• void hist(List<int> &L): stampa la frequenza di ogni elemento presente nella
lista L
• void remp(List<int> &L): rimuove dalla lista L tutti gli elementi seguiti da un
numero dispari
Prevedere una funzione nel main che contenga una procedura di inserimento automatico
e successivamente il test delle funzioni implementate.
 */
#include "funzioni.h"

void inserimento(Linked_list<int> &);
void testFunzioni(Linked_list<int> &);

int main(int argc , char *argv[])
{
	Linked_list<int> prova;

	inserimento(prova);
	testFunzioni(prova);

	getchar();
	return 0;
}


void inserimento(Linked_list<int> &L)
{
	Linked_list<int>::position p = L.begin();
	int n = 20;

	for(int i=0;i<n;i++)
	{
	 L.insert(rand()%5,p);
	 p = L.next(p);
	}
}

void testFunzioni(Linked_list<int> &L)
{
	std::cout << "lista prova inizio :\n" << L << "\n";

	std::cout << freq(L,2) << std::endl;

	hist(L);

	remp(L);

	std::cout << "lista prova fine :\n" << L << "\n";

}
