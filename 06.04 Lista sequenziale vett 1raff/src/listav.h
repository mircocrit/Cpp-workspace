#ifndef _LISTAV_H
#define _LISTAV_H

/*
 uso di un vettore per la memorizzazione degli elementi della lista
 vettori diversi per ogni istanza della classe
 vettore elementi monodimensionale che memorizza gli elementi della lista secondo la formula posizione(i) = i
 variabile lunghezza che tiene traccia del numero di elementi presenti nella lista
 costante DIMENSIONE che tiene traccia della dimensione del vettore*/

#include <iostream>
#include "cellalv.h"

typedef int tipoelem;
typedef int posizione;
const int DIMENSIONE = 1024;		// lunghezza massima della lista


class Lista{//il vettore e' statico
	public:
		Lista(); 	// costruttore
		~Lista(); 	// distruttore

		// operatori
		void creaLista();
		bool listaVuota() const;//mrtodi che non modificano attributi interni sono const
		tipoelem leggiLista(posizione) const;
		void scriviLista(tipoelem, posizione);
		posizione primoLista() const;
		bool fineLista(posizione) const;
		posizione succLista(posizione) const;
		posizione predLista(posizione) const;
		void insLista(tipoelem, posizione);
		void cancLista(posizione);
	private:
		tipoelem elementi[DIMENSIONE];
		int lunghezza;
};

#endif // _LISTAV_H
