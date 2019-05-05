/*
 * test.cpp
 *
 *  Created on: 07 gen 2019
 *      Author: utente
 */
#include "listaOrdinata.h"
#include <ctime>

template <class I>
void inserimento(ListaOrdinata<I> &);

int main(int argc , char *argv[])
{
	ListaOrdinata<int> testo , pattern;

	//inserimento(prova1);
	//system("pause");
	//inserimento(prova);
	//std::cout << "prova prima \n" << prova;
	//std::cout << "prova1 prima \n" << prova1;
	//std::cout << "prova dopo \n" << prova.differenza(prova,prova1);

	for(int i=0;i<20;i++)
		testo.inserisci(testo,i);

	std::cout << "testo \n" << testo;	//{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}

	for(int i=0;i<4;i++)
		pattern.inserisci(pattern,i+6);

	std::cout << "pattern \n" << pattern;		//{6,7,8,9}


	std::cout <<testo.read(pattern.sottoLista(pattern,testo));
	//prova.rimuovi(prova,5);
	//std::cout << "dopo \n" << prova;

	getchar();
	return 0;
}


template <class I>
void inserimento(ListaOrdinata<I> &L)
{
	srand(time(NULL));

	int n = 10;

	for(int i=0;i<n;i++)
	{
		L.inserisci(L,rand()%10);
	}
}
