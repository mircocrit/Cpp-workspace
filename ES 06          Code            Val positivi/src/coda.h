/*
 * coda.h
 *
 *  Created on: 02 gen 2019
 *      Author: utente
 */

#ifndef CODA_H_
#define CODA_H_

#include "codaLineare.h"
#include "linked_list.h"

template <class I>
class Coda : public CodaLineare<I,List_node<I>*>
{
public:
	typedef typename CodaLineare<I,List_node<I>*>::valore valore;
	typedef typename CodaLineare<I,List_node<I>*>::posizione posizione;

	Coda()
	{
		creaCoda();
	}

	Coda(Coda<I> &C)
	{
		Coda<I> tmp;
		creaCoda();
		while(!C.codaVuota())
		{
			valore elem = C.leggiCoda();
			inCoda(elem);
			C.fuoriCoda();
			tmp.inCoda(elem);
		}

		while(!tmp.codaVuota())
		{
			C.inCoda(tmp.leggiCoda());
			tmp.fuoriCoda();
		}
	}

	Coda<I>& operator = (Coda<I> &C)
	{
		Coda<I> tmp;
		if(this == &C)
			return *this;
		else
		{
			coda.~Linked_list();
			creaCoda();
			while(!C.codaVuota())
			{
				valore elem = C.leggiCoda();
				inCoda(elem);
				C.fuoriCoda();
				tmp.inCoda(elem);
			}
			while(!tmp.codaVuota())
			{
				C.inCoda(tmp.leggiCoda());
				tmp.fuoriCoda();
			}
		}
		return *this;
	}

	void creaCoda()
	{
		coda.create();
		dim=0;
	}

	bool codaVuota() const
	{
		return coda.empty();
	}

	valore leggiCoda() const
	{
		return coda.read(coda.begin());
	}

	void fuoriCoda()
	{
		coda.erase(coda.begin());
		dim--;
	}

	void inCoda(const valore &c)
	{
		posizione p = coda.begin();
		while(!coda.end(p))
			p = coda.next(p);
		coda.insert(c,p);
		dim++;
	}
	int getLung() const{
		return dim;
	}


/*
	std::ostream& operator <<(std::ostream &os, const Coda<I> &C){
		I n;
		int i=0;
		while(i<getSize()){
			n=leggiCoda();
			cout<<n;
			fuoriCoda();
			inCoda(n);
			i++;
		};
		return os;
	}

*/
private:
	Linked_list<I> coda;
	int dim;
};


#endif /* CODA_H_ */
