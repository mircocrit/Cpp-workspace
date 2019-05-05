/*
 * coda.h
 *
 *  Created on: 24 ott 2018
 *      Author: utente
 */
#ifndef CODA_H_
#define CODA_H_

#include "codaLineare.h"
#include <iostream>

template <class T>
class Coda;

template <class T>
class Nodo
{
public:
	friend class Coda<T>;
private:
	T valore;
	Nodo<T> *succ;
};

template <class T>
class Coda : public codaLineare<T , Nodo<T>*>
{
public:
	typedef typename codaLineare<T , Nodo<T>*>::valore valore;
	typedef typename codaLineare<T , Nodo<T>*>::posizione posizione;

	Coda();
	~Coda();
	Coda(Coda<T>&);
	Coda<T>& operator=(Coda<T>&);
	bool operator==(const Coda<T>&);
	void creaCoda();
	bool codaVuota()const;
	valore leggiCoda()const;
	void fuoriCoda();
	void inCoda(const valore&);
	void stampaCoda();
	int getSize(){return numNodi;}
private:
	Nodo<T> *testa;
	Nodo<T> *coda;
	int numNodi;
};

template <class T>
Coda<T>::Coda()
{
	testa = new Nodo<T>;
	coda = new Nodo<T>;
	testa->succ = testa;
	coda->succ = coda;
	numNodi = 0;
}

template <class T>
Coda<T>::~Coda()
{
	while(!codaVuota())
		fuoriCoda();
	delete testa;
	delete coda;
}
/*
template <class T>
Coda<T>::Coda(Coda<T>&)
{
	;
}

template <class T>
Coda<T>& Coda<T>::operator =(Coda<T> &C)
{
	;
}

template <class T>
bool Coda<T>::operator ==(const Coda<T> &C)
{
	;
}
*/
template <class T>
void Coda<T>::creaCoda()
{
	numNodi = 0;
}

template <class T>
bool Coda<T>::codaVuota()const
{
	return (testa->succ == coda->succ);
}

template <class T>
typename Coda<T>::valore Coda<T>::leggiCoda()const
{
	if(!this->codaVuota())
	   return testa->succ->valore;
	else
		std::cout << "Coda vuota" << std::endl;
}

template <class T>
void Coda<T>::fuoriCoda()
{
	posizione temp = new Nodo<T>;
	if(!this->codaVuota())
	{
		temp->succ = testa->succ;
		delete testa->succ;
		testa->succ = testa->succ->succ;
		numNodi++;

	}
	else
		std::cout << "Coda vuota" << std::endl;
}

template <class T>
void Coda<T>::inCoda(const valore &V)
{
	posizione nodo = new Nodo<T>;
	nodo->valore = V;

	if(this->codaVuota())
	{
		coda->succ = nodo;
		testa->succ = nodo;
		nodo->succ = nullptr;
	}
	else
	{
		nodo->succ = coda->succ;
		coda->succ = nodo;
	}
	numNodi++;

}
#endif /* CODA_H_ */

