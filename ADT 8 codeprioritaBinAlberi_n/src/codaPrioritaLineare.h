/*
 * codaPrioritaLineare.h
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */

#ifndef CODAPRIORITALINEARE_H_
#define CODAPRIORITALINEARE_H_

template <class T , class P>
class CodaPrioritaLineare
{
	public:

	typedef T tipoElem;
	typedef P posizione;

	virtual void creaPrioriCoda() = 0;
	virtual void inserisci(tipoElem) = 0;
	virtual tipoElem min()const = 0;
	virtual void cancellaMin() = 0;
};


#endif /* CODAPRIORITALINEARE_H_ */
