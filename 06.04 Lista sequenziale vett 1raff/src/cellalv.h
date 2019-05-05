#ifndef _CELLALV_H
#define _CELLALV_H

#include <iostream>
//1° RAFFINAMENTO
/*Definizione della classe CellaLista
	Interfaccia
	- classe CellaLista
	-parte pubblica
	- tipoelem
	- costruttori e distruttore
	- scriviCella e leggiCella
	- sovraccarico dell'operatore ==
	-parte privata
	- etichetta
*/

//nodo lista che memorizza 1 elem di tipo INTERO
typedef int tipoelem;

class CellaLista{
	public:
		CellaLista(); 					//costruttore
		CellaLista(tipoelem);
		~CellaLista(){}; 				//distruttore

		void scriviCella(tipoelem);		//setter
		tipoelem leggiCella() const;	//getter
		bool operator == (CellaLista);	//overloaded operatore uguaglianza==
	private:
		tipoelem etichetta;
};
#endif // _CELLALV_H
