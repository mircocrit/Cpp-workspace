#ifndef _LISTALIN_H
#define _LISTALIN_H
///////////////////////////////////////////INTERFACCIA/////////////////////////////////

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;

// classe astratta listaLinare

template< class T, class P >
class Linear_list{
   public:
	  typedef T value_type;
	  typedef P position;

	  virtual 	void create() = 0;
	  virtual 	bool empty() const = 0; 								// vero se la lista ha dimensione 0
	  virtual 	value_type read(position) const = 0;
	  virtual 	void write(const value_type &, position) = 0;			// scrive x a posizione p
	  virtual 	position begin() const = 0;  							// ritorna la posizione che punta all'inizio della lista
	  virtual 	bool end(position) const = 0; 							// vero se la posizione punta a fine lista
	  virtual	position next(position) const = 0; 						// ritorna la successiva posizione
	  virtual 	position previous(position) const = 0; 					// ritorna la precedente posizione
	  virtual 	void insert(const value_type &, position) = 0; 			// inserisce l'elemento
	  virtual 	void erase(position pos) = 0; 							// elimina l'elelmento in posizione pos
	  //////////////////////////////////////////////////////////////////////////////////////////////
	  // funzioni di servizio
	  //friend ostream& operator<< <T,P>(ostream&, const Linear_list<T,P>&);

		/* Altre funzioni di servizio implementabili */

		//virtual	 	int size() const; 										// returns the size of the list
		/*
		virtual 	void push_front(const value_type &); 					// insert a new element at the beginning
		virtual 	void push_back(const value_type &); 					// insert a new element at the end
		virtual 	void pop_front(); 										// removes the first element
		virtual 	void pop_back(); 										// removes the last element
		virtual 	void clear();											// erases all the elements
		*/

};

/* sovraccarica <<. Attenzione se il tipo restituito da read non è primitivo, allora
 *  anche per questo tipo bisogna sovraccaricare l'operatore <<
 */
//OPERATORE DI COUT

template< class T, class P >
ostream& operator<<(ostream& os, const Linear_list<T,P> &l){
	typename Linear_list<T,P>::position p;
	p = l.begin();
	os << "[";
	while (!l.end(p)){	//se la lista non e' finita
		if (p!= l.begin())			os << ", " << l.read(p);	//in base a quello che sta nella classe:va fato override(se non e' tipo primitivo)
		else						os << l.read(p);
		p = l.next(p);
	}
	os << "]" << endl;
	return os;
}

/*
template< class T, class P >
int Linear_list<T,P>::size() const{
   ....
}
*/

#endif // _LISTALIN_H

