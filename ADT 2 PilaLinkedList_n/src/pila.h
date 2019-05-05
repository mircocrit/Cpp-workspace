/*
 * pila.h
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */

#ifndef PILA_H_
#define PILA_H_

#include "pilaLineare.h"
#include "linked_list.h"

template <class I>
class Pila : public PilaLineare<I,List_node<I>*>
{
public:
	typedef typename PilaLineare<I , List_node<I>*>::valore valore;
	typedef typename PilaLineare<I , List_node<I>*>::posizione posizione;

	Pila()
	{
		creaPila();
	}

	Pila(Pila<I> &P)
	{
		Pila<I> tmp;

		creaPila();
		while(!P.pilaVuota())
		{
			tmp.inPila(P.leggiPila());
			P.fuoriPila();
		}

		while(!tmp.pilaVuota())
		{
			P.inPila(tmp.leggiPila());
			inPila(tmp.leggiPila());
			tmp.fuoriPila();
		}
	}
/*
	Pila<I>& operator = (Pila<I> &P)
	{
		if(this == &P)
			return *this;
		else
		{
			Pila<I> tmp;
			pila.~Linked_list();
			creaPila();
			while(!P.pilaVuota())
			{
				tmp.inPila(P.leggiPila());
				P.fuoriPila();
			}
			while(!tmp.pilaVuota())
			{
				P.inPila(tmp.leggiPila());
				inPila(tmp.leggiPila());
				tmp.fuoriPila();
			}
		}
		return *this;
	}
*/
	void creaPila()
	{
		pila.create();
	}

	bool pilaVuota() const
	{
		return pila.empty();
	}

	valore leggiPila() const
	{
		if(!pilaVuota())
			return pila.read(pila.begin());
	}

	void fuoriPila()
	{
		if(!pilaVuota())
			pila.erase(pila.begin());
	}

	void inPila(const valore &p)
	{
		pila.insert(p , pila.begin());
	}


	friend std::ostream& operator << (std::ostream &os,Pila<I> &p){
		valore e;

		Pila<I> qaux;
		qaux.creaPila();
		os<<" [  ";
		while(!p.pilaVuota()){
			e = p.leggiPila();
			os<<e<< "  ";
			qaux.inPila(e);
			p.fuoriPila();
		}

		p.creaPila();
		while ( !qaux.pilaVuota()){
			e = qaux.leggiPila();
			p.inPila(e);
			qaux.fuoriPila();
		}
	os<<" ]  ";
	return os;
	}
private:
	Linked_list<I> pila;
};

#endif /* PILA_H_ */
