#ifndef CIRCLISTA_H_
#define CIRCLISTA_H_

#include "cellalp.h"
#include "listap.h"

template<class T>
	class circLista{
		public:
			typedef T tipoelem;
			circLista(); // costruttore
			circLista(const circLista<T>&); // costruttore di copia
			~circLista(); // distruttore
			/* posizione è un puntatore a cella */
			typedef Cella<T> * posizione;

			/* Prototipi degli operatori */
			void creaLista();
			bool listaVuota();
			tipoelem leggiLista(posizione);
			void scriviLista(tipoelem, posizione);
			posizione primoLista();
			bool fineLista(posizione);
			posizione succLista(posizione);
			posizione precLista(posizione);
			void insLista(tipoelem,posizione&);
			void cancLista(posizione &p);
		private:
			posizione lista;
		//la lista è un puntatore ad oggetto Cella
};
/*
template< class T > circLista< T >::circLista() { crealista(); }
template< class T > const circLista< T >::circLista<T>& Lista) {
	// da realizzare
	 * }
template< class T > circLista< T >::~circLista(){
	while (lista->getSucc() != lista->getPrec()) canclista(lista->getSucc());
	delete lista;
}
template< class T > void circLista< T >::crealista(){
	tipoelem ElementoNullo;
	lista = new Cella;
	lista->setElemento(ElementoNullo);
	lista->setSucc(lista);
	lista->setPrec(lista);
	//la sentinella punta a se stessa
}
template< class T > bool circLista< T >::listaVuota() const{
	return ((lista->getSucc() == lista) && (lista->getPrec()==lista)); }
template< class T > circLista< T >::posizione circLista< T >::primoLista() const{
	return lista->getSucc(); }
template< class T > circLista< T >::posizione circLista< T >::succLista(Lista::posizione p) const{
	return p->getSucc(); }
template< class T > circLista< T >::posizione circLista< T >::precLista(Lista::posizione p) const {
	return p->getPrec(); }
template< class T > bool circLista< T >::fineLista(Lista::posizione p) const {
	return (p==lista); }
template< class T > circLista< T >::tipoelem circLista< T >::leggiLista(posizione p) const{
	return p->getElemento();
}
template< class T > void circLista< T >::scriviLista(tipoelem a, posizione p){
	p->setElemento(a);
}
template< class T > void circLista< T >::insLista(tipoelem a, Lista::posizione &p){
	Lista::posizione temp;
	temp = new Cella;
	temp->setElemento(a);
	temp->setPrec(p->getPrec());
	temp->setSucc(p);
	(p->getPrec())->setSucc(temp);
	p->setPrec(temp);
	p=temp;
}
template< class T > void circLista< T >::cancLista(Lista::posizione &p){
	Lista::posizione temp;
	temp=p;
	(p->getSucc())->setPrec(p->getPrec());
	(p->getPrec())->setSucc(p->getSucc());
	p=p->getSucc();
	delete(temp);
}
*/
#endif /* CIRCLISTA_H_ */
