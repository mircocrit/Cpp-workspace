#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>

//ALBERO BINARIO:CLASSE ASTRATTA: da alto verso basso
template <class T, class N>

class Bin_tree {
  static const int NIL = -1;

  public:
    typedef T value_type;											// valore
    typedef N Nodo;													//nodo

    virtual void create() = 0;			  							// crea albero binario
    virtual bool empty() const =  0;	  							// restituisce true se albero vuoto
    virtual Nodo root() const = 0;		  							// restituisce il nodo radice dell'albero
    virtual Nodo parent(Nodo) const =  0; 							// restituisce il nodo padre del nodo
    virtual Nodo sx(Nodo) const = 0;	 							 //restituisce il fratello sinistro del nodo
    virtual Nodo dx(Nodo) const = 0;								//restituisce il fratello destro del nodo
    virtual bool sx_empty(Nodo) const = 0;							//restituisce true se non ho fratelli sinistri
    virtual bool dx_empty(Nodo) const = 0;							//restituisce true se non ho fratelli destri

    //virtual void costr(Bin_tree<T,N>);
    virtual void erase(Nodo) = 0;		//elimina nodo

    virtual T read(Nodo) const = 0;	//legge il nodo e restituisce il contenuto
    virtual void write(Nodo , value_type ) = 0;	//scrive un valore nel nodo passato in input

    virtual void ins_root(Nodo) = 0;	//inserisce il nodo nella radice
    virtual void ins_sx(Nodo) = 0;		//inserisce il nodo a sinistra di quello passato
    virtual void ins_dx(Nodo) = 0;		//inserisce il nodo a destra di quello passato

    // funzioni di servizio da implementare qui

    //virtual void previsit(Nodo);
    //virtual void invisita(Nodo);
    //virtual void postvisit(Nodo);

    virtual void print() const;		//stampa albero

private:
    virtual void printSubTree(const Nodo) const;	//stampa sottoalbero con radice in un determinato nodo

  };

template <class T, class N>
void Bin_tree<T,N>::print() const{
	if (!empty())		printSubTree(root());
	else 		std::cout << "[]" << std::endl;
	std::cout << std::endl;
}


template <class T, class N>
void Bin_tree<T,N>::printSubTree(const Nodo n) const{
	std::cout << "[" << read(n) << ", ";
	if (!sx_empty(n))
		printSubTree(sx(n));
	else std::cout << "NIL";
	std::cout << ", ";
	if (!dx_empty(n))
		printSubTree(dx(n));
	else std::cout << "NIL";
	std::cout << " ]";
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const Bin_tree<T, N>& t) {
    t.print();
    return out;
}



#endif /* _BINALBEROC_H_ */
