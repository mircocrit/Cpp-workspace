/*
 * Bin_Tree.h
 *
 *  Created on: 28 dic 2018
 *      Author: utente
 */

#ifndef _BINTREE_H_
#define _BINTREE_H_
#include <iostream>
#include "coda.h"

template <class T, class N>
class Bin_tree {
  static const int NIL = -1;

  public:

    // tipi
    typedef T value_type;
    typedef N Nodo;

    // operatori
    virtual void create() = 0;
    virtual bool empty() const =  0;

    virtual Nodo root() const = 0;
    virtual Nodo parent(Nodo) const =  0;
    virtual Nodo sx(Nodo) const = 0;
    virtual Nodo dx(Nodo) const = 0;
    virtual bool sxEmpty(Nodo) const = 0;
    virtual bool dxEmpty(Nodo) const = 0;

    //virtual void costr(Bin_tree<T,N>);
    virtual void erase(Nodo) = 0;

    virtual T read(Nodo) const = 0;
    virtual void write(Nodo , value_type ) = 0;

    virtual void insRoot(value_type) = 0;
    virtual void insSx(Nodo,value_type) = 0;
    virtual void insDx(Nodo,value_type) = 0;

    // funzioni di servizio da implementare qui
    //virtual void previsit(Nodo);
    //virtual void invisita(Nodo);
    //virtual void postvisit(Nodo);
    virtual void previsita(Nodo) const;
    virtual void postvisita(Nodo) const;
    virtual void visitaSimmetrica(Nodo) const;
    virtual void visitaAmpiezza(Nodo) const;

    virtual void print() const;

private:
    virtual void printSubTree(const Nodo) const;
  };

template <class T , class N>
void Bin_tree<T,N>::previsita(Nodo n) const
{
	std::cout << read(n) << std::endl;
	if(!sxEmpty(n))
		previsita(sx(n));
	if(!dxEmpty(n))
		previsita(dx(n));
}

template <class T , class N>
void Bin_tree<T,N>::postvisita(Nodo n) const
{
	if(!sxEmpty(n))
		previsita(sx(n));
	if(!dxEmpty(n))
		previsita(dx(n));
	std::cout << read(n) << std::endl;
}

template <class T , class N>
void Bin_tree<T,N>::visitaSimmetrica(Nodo n) const
{
	if(!sxEmpty(n))
		visitaSimmetrica(sx(n));
	std::cout << read(n) << std::endl;
	if(!dxEmpty(n))
		visitaSimmetrica(dx(n));
}

template <class T , class N>
void Bin_tree<T,N>::visitaAmpiezza(Nodo n) const
{
	Coda<Nodo> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		Nodo p = temp.leggiCoda();
		temp.fuoriCoda();
		std::cout << read(p) << std::endl;
		if(!sxEmpty(p))
			temp.inCoda(sx(p));
		if(!dxEmpty(p))
			temp.inCoda(dx(p));
	}
}

template <class T, class N>
void Bin_tree<T,N>::print() const{
	if (!empty())
		printSubTree(root());
	else
		std::cout << "[]" << std::endl;
	std::cout << std::endl;
}

template <class T, class N>
void Bin_tree<T,N>::printSubTree(const Nodo n) const{
	std::cout << read(n) << ": ";
		if(!sxEmpty(n))
		std::cout << read(sx(n)) << " ";
	else
		std::cout << "NIL" << " ";
	if(!this->dxEmpty(n))
		std::cout << read(dx(n));
	else
		std::cout << "NIL";
	std::cout << std::endl;
	if(!sxEmpty(n))
		printSubTree(sx(n));
	if(!dxEmpty(n))
		printSubTree(dx(n));
	/*
	std::cout << "[" << read(n) << ", ";
	if (!sxEmpty(n))
		printSubTree(sx(n));
	else std::cout << "NIL";
	std::cout << ", ";
	if (!dxEmpty(n))
		printSubTree(dx(n));
	else std::cout << "NIL";
	std::cout << " ]";
	*/
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const Bin_tree<T, N>& t) {
    t.print();
    return out;
}

#endif /* _BINALBEROC_H_ */
