/*
 * pilaLineare.h
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */

#ifndef PILALINEARE_H_
#define PILALINEARE_H_

#include <iostream>

template <class T , class P>
class PilaLineare
{
public:
	typedef T valore;
	typedef P posizione;

	virtual void creaPila() = 0;
	virtual bool pilaVuota()const = 0;
	virtual valore leggiPila()const = 0;
	virtual void fuoriPila() = 0;
	virtual void inPila(const valore&) = 0;
	virtual int getSize() = 0;

	//virtual void stampaPila();
};

/*
template <class T , class P>
void PilaLineare<T,P>::stampaPila()
{
	valore elemento;
	while(!pilaVuota())
	{
		elemento = leggiPila();
		fuoriPila();
		stampaPila();
		std::cout << elemento;
		inPila(elemento);
	}
}


template<class T, class P>
std::ostream& operator<<(std::ostream& out, PilaLineare<T, P> &p)
{
    p.stampaPila();
    return out;
}
*/


#endif /* PILALINEARE_H_ */
