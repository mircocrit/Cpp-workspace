/*
 * Tree.h
 *
 *  Created on: 28 dic 2018
 *      Author: utente
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include "coda.h"

template<class I, class N>
	class Tree {
 public:
	typedef I item;
	typedef N node;

	virtual void create () = 0;
	virtual bool empty () const = 0;
	virtual void insRoot (item) = 0;
	virtual node root () const = 0;
	virtual node parent (node) const = 0;
	virtual bool leaf (node) const = 0;
	virtual node firstChild (node) const = 0;
	virtual bool lastSibling (node) const = 0;
	virtual node nextSibling (node) const = 0;
	virtual void print() const;
	virtual int getLivello(node);

	// DA IMPLEMENTARE
	//virtual void insFirstSubTree (node, Tree &) = 0;
	//virtual void insSubTree (node, Tree &) = 0;
	virtual void removeSubTree (node) = 0;

	virtual void writeNode (node, item) = 0;
	virtual item readNode (node) const = 0;

	//template<class V> void BFS(node);
	//template<class V> void preorder(node);
	//template<class V> void postorder(node);
	virtual void preVisita(node) const;
	virtual void postVisita(node) const;
	virtual void invisita(node,int) const;
	virtual void ampiezza(node) const;

 private:
	virtual void printSubTree(const node) const;

};

template <class I , class N>
void Tree<I,N>::preVisita(node n) const
{
	node p;
	std::cout << readNode(n) << std::endl;
	if(!leaf(n))
	{
		p = firstChild(n);
		while(!lastSibling(p))
		{
			preVisita(p);
			p = nextSibling(p);
		}
		preVisita(p);
	}
}
template <class I , class N>
void Tree<I,N>::postVisita(node n) const
{
	node p;
	if(!leaf(n))
	{
		p = firstChild(n);
		while(!lastSibling(p))
		{
			postVisita(p);
			p = nextSibling(p);
		}
		postVisita(p);
	}
	std::cout << readNode(n) << std::endl;
}

template <class I, class N>
void Tree<I,N>::invisita(node n , int i) const
{
	if(leaf(n))
		std::cout << readNode(n) << std::endl;
	else
	{
		node p = firstChild(n);
		int k = 0;
		while(!lastSibling(p) && k < i)
		{
			k += 1;
			invisita(p , i);
			p = nextSibling(p);
		}
		std::cout << readNode(n) << std::endl;
		while(!lastSibling(p))
		{
			invisita(p , i);
			p = nextSibling(p);
		}

	}
}

template <class I , class N>
void Tree<I,N>::ampiezza(node n) const
{
	Coda<node> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		node p = temp.leggiCoda();
		temp.fuoriCoda();
		std::cout << readNode(p) << std::endl;
		p = firstChild(p);
		while(p)
		{
			temp.inCoda(p);
			p = nextSibling(p);
		}
	}
}

template <class I, class N>
void Tree<I,N>::print() const{
	if (!empty())
		printSubTree(root());
	else
		std::cout << "[]" << std::endl;
	std::cout << std::endl;
}

template <class I, class N>
void Tree<I,N>::printSubTree(const node n) const
{
	node p;
	std::cout << readNode(n) << ":";
	if (!leaf(n))
	{
		p=firstChild(n);
		while (!lastSibling(p))
		{
			std::cout << " " << readNode(p);
			p=nextSibling(p);
		}
		std::cout << " " << readNode(p) << std::endl;
		p=firstChild(n);
		while (!lastSibling(p))
		{
			printSubTree(p);
			p=nextSibling(p);
		}
		printSubTree(p);
	}
	else
	{
		std::cout << std::endl;
	}
}

template<class T, class N>
std::ostream& operator<<(std::ostream& out, const Tree<T, N>& t) {
    t.print();
    return out;
}
#endif /* TREE_H_ */
