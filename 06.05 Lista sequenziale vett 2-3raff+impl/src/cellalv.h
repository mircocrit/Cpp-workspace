#ifndef _CELLALV_H
#define _CELLALV_H
#include "libro.h"
typedef Libro tipoelem;


class CellaLista{
	public:
		CellaLista(); 					//costruttore
		CellaLista(tipoelem);
		~CellaLista(){}; 				//distruttore
		void scriviCella(tipoelem);
		tipoelem leggiCella() const;
		bool operator == (CellaLista);	//overload ==(chiamera lista)
	private:
		tipoelem etichetta;

};
#endif // _CELLALV_H


