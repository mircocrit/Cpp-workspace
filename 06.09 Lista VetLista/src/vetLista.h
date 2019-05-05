#ifndef VETLISTA_H_
#define VETLISTA_H_
#include "listaLineare.h"

template< class T >
 class vetLista : public listaLineare<T>{
  public:
	typedef T tipoelem;
	typedef int posizione;

	vetLista(int dim = 10); // costruttore
	vetLista(const vetLista<T>&); // costruttore di copia
	~vetLista(); //distruttore
	// operatori
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
  protected:
	tipoelem* elementi; // vettore
	int lunghezza; // lunghezza della lista
	int dimensione; // dimensione del vetore
};

template< class T >
	void vetLista< T >::creaLista(){ lunghezza = 0; }

// il costruttore crea un vettore la cui dimensione è dimIniziale che di default è 10
template< class T >
	vetLista< T >::vetLista(int dim) {
	dimensione = dim;
	elementi = new T[dimensione];
	crealista();
}
/* il costruttore di copia effettua una copia o clone di un oggetto. Questo costruttore viene invocato,
* per esempio, quando un oggetto viene passato per valore ad una funzione o quando una funzione
* restituisce un oggetto. */
template< class T >
	vetLista< T >::vetLista(const vetLista<T>& Lista) {
	dimensione = Lista.dimensione;
	lunghezza = Lista.lunghezza;
	elementi = new T[dimensione];
	for (int i=0; i<Lista.dimensione; i++)
		elementi[i] = Lista.elementi[i];
}
/*
template< class T >
	void vetLista< T >::creaLista(){ lunghezza = 0; }
	*/
template< class T >
	bool vetLista< T >::listaVuota() const { return(lunghezza == 0); }
//...
//...

#endif /* VETLISTA_H_ */
