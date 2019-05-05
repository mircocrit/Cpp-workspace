/*
 * codaLineare.h
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */

#ifndef CODALINEARE_H_
#define CODALINEARE_H_

#include <iostream>

template <class T , class P>
class CodaLineare
{
public:
	typedef T valore;
	typedef P posizione;

	virtual void creaCoda() = 0;
	virtual bool codaVuota()const= 0;
	virtual valore leggiCoda()const = 0;
	virtual void fuoriCoda() = 0;
	virtual void inCoda(const valore&) = 0;
	virtual int getLung() const = 0;
};


#endif /* CODALINEARE_H_ */
