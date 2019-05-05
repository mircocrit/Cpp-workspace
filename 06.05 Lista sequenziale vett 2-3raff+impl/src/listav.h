#ifndef _LISTAV_H
#define _LISTAV_H
#include "cellalv.h"

const int DIMENSIONE = 1024;
//la lista non cambierà piu
class Lista{
	public:
		typedef int posizione;
		Lista(); // costruttore
		~Lista(); // distruttore
		// operatori
		//in tipoelem ho libro
		void creaLista();
		bool listaVuota() const;
		tipoelem leggiLista(posizione) const;
		void scriviLista(tipoelem, posizione);
		posizione primoLista() const;
		bool fineLista(posizione) const;
		posizione succLista(posizione) const;
		posizione predLista(posizione) const;
		void insLista(tipoelem, posizione);
		void cancLista(posizione);
	private:
		CellaLista elementi[DIMENSIONE];
		int lunghezza;
};
#endif // _LISTAV_H
