/*
 * linearStack.h
 *
 *  Created on: 22 ott 2018
 *      Author: utente
 */

#ifndef LINEARSTACK_H_
#define LINEARSTACK_H_

template <class T , class P>
class linearStack
{
public:
	typedef T valore;
	typedef P posizione;

	virtual void creaPila() = 0;
	virtual bool pilaVuota()const = 0;
	virtual valore leggiPila()const = 0;
	virtual void fuoriPila() = 0;
	virtual void inPila(const valore&) = 0;
};

#endif /* LINEARSTACK_H_ */
