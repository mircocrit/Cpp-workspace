/* *Esercizio 1
Implementare un algoritmo che data una coda di interi ne costruisca un'altra ottenuta dalla prima considerando solo i valori positivi.

*Esercizio 3
Implementare un algoritmo che data una coda di interi ne costruisca un'altra ottenuta dalla prima considerando solo i valori positivi e conservando la coda originaria.

*/

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "codaLineare.h"
#include "coda.h"

template < class P>
void estrai_pari (CodaLineare<int,P> &queue,CodaLineare<int,P> &qpari){	//(q)this e' la coda originale'
	int e, dim=queue.getLung();							//quax e quella che servira a ripopolare this

	for(int i=0;i<dim;i++){
		e =queue.leggiCoda();
		if (e %2==0){
			qpari.inCoda(e);
		}
		queue.fuoriCoda();
		queue.inCoda(e);
	}
}

#endif /* FUNZIONI_H_ */
