/*
 * linkBinAlberi.h
 *
 *  Created on: 20 nov 2018
 *      Author: utente
 */

#ifndef LINKBINALBERI_H_
#define LINKBINALBERI_H_

#include <iostream>
#include "coda.h"

template <class I>
class LinkBinAlberi;

template <class I>
class TreeNode
{
public:
	friend class LinkBinAlberi<I>;
private:
	TreeNode *parent = nullptr;
	TreeNode *sx = nullptr;
	TreeNode *dx = nullptr;
	I item;
	int level;
	bool tipoFiglio; //false figlio sinistro , true figlio destro
};

template <class I>
class LinkBinAlberi
{
public:
	typedef  I item;
	typedef  TreeNode<I>* node;

	LinkBinAlberi();
	~LinkBinAlberi();
	void create();
	bool empty() const;

	node root() const;
	node parent(node) const;
	node sx(node) const;
	node dx(node) const;
	bool sxEmpty(node) const;
	bool dxEmpty(node) const;
	bool isRoot(node) const;


	//ausiliarie
	bool isFiglioSx(node) const;
	bool isFiglioDx(node) const;
	int getlevel(node n){return n->level;};
	bool leaf(node)const;
	item read(node) const;
	void write(node , item);
	void printSubTree(node) const;
	void print()const;
	friend std::ostream& operator<<(std::ostream &os, const LinkBinAlberi &L)
	{
		L.print();
		return os;
	}
	//inserimento-cancelazione
	void insRoot(item&);
	void insSx(node , item&);
	void insDx(node , item&);
	void erase(node);
	//visite
	void preVisita(node);
	void postVisita(node);
	void inVisita(node,int);
	void ampiezza(node);
	void simmetrica(node);

private:
	node _root;
};

template <class I>
LinkBinAlberi<I>::LinkBinAlberi()
{
	create();
}

template <class I>
LinkBinAlberi<I>::~LinkBinAlberi()
{
	//this->erase(_root);
	delete this->_root;
}

template <class I>
void LinkBinAlberi<I>::create()
{
	this->_root = nullptr;
}

template <class I>
bool LinkBinAlberi<I>::empty()const
{
	return (this->_root == nullptr);
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::root()const
{
	return this->_root;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::parent(node n)const
{
	if(n->parent != nullptr)
		return n->parent;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::sx(node n)const
{
	if(n->sx != nullptr)
		return n->sx;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::dx(node n)const
{
	if(n->dx != nullptr)
		return n->dx;
}

template <class I>
bool LinkBinAlberi<I>::isFiglioSx(node n) const
{
	return n->tipoFiglio == false;
}

template <class I>
bool LinkBinAlberi<I>::isFiglioDx(node n) const
{
	return n->tipoFiglio == true;
}

template <class I>
bool LinkBinAlberi<I>::sxEmpty(node n)const
{
	return (n->sx == nullptr);
}

template <class I>
bool LinkBinAlberi<I>::dxEmpty(node n)const
{
	return (n->dx == nullptr);
}

template <class I>
bool LinkBinAlberi<I>::isRoot(node n)const
{
	return (n->parent == nullptr);
}

template <class I>
void LinkBinAlberi<I>::erase(node n)
{
	if(!this->sxEmpty(n))
		this->erase(this->sx(n));
	if(!this->dxEmpty(n))
		this->erase(this->dx(n));

	if(n == this->root())
		n = nullptr;
	else
	{
		node p = n->parent;
		if(p->sx == n)
		{
			p->sx = nullptr;
			delete this->sx(p);
		}
		else
		{
			p->dx = nullptr;
			delete this->dx(p);
		}
	}
}

template <class I>
bool LinkBinAlberi<I>::leaf(node n)const
{
	return(n->sx == nullptr && n->dx == nullptr);
}

template <class I>
typename LinkBinAlberi<I>::item LinkBinAlberi<I>::read(node n)const
{
	return n->item;
}

template <class I>
void LinkBinAlberi<I>::write(node n , item elem)
{
	n->item = elem;
}

template <class I>
void LinkBinAlberi<I>::insRoot(item &i)
{
	this->_root = new TreeNode<I>();
	this->_root->item = i;
	this->_root->level = 0;
	//this->_root->tipoFiglio = '0';
}

template <class I>
void LinkBinAlberi<I>::insSx(node n , item &i)
{
	if(this->sxEmpty(n))
	{
	node newNode = new TreeNode<I>();
	newNode->item = i;
	n->sx = newNode;
	newNode->parent = n;
	newNode->level = (newNode->parent->level)+1;
	newNode->tipoFiglio = false;
	}
	else
		std::cout << "Nodo sinistro pieno" << std::endl;
}

template <class I>
void LinkBinAlberi<I>::insDx(node n , item &i)
{
	if(this->dxEmpty(n))
	{
		node newNode = new TreeNode<I>();
		newNode->item = i;
		n->dx = newNode;
		newNode->parent = n;
		newNode->level = (newNode->parent->level)+1;
		newNode->tipoFiglio = true;
	}
	else
		std::cout << "Nodo destro pieno" << std::endl;
}

template <class I>
void LinkBinAlberi<I>::printSubTree(node n)const
{
	std::cout << this->read(n) << ": ";
	if(!this->sxEmpty(n))
		std::cout << this->read(n->sx) << " ";
	else
		std::cout << "NIL" << " ";
	if(!this->dxEmpty(n))
		std::cout << this->read(n->dx);
	else
		std::cout << "NIL";
	std::cout << std::endl;
	if(!this->sxEmpty(n))
		printSubTree(this->sx(n));
	if(!this->dxEmpty(n))
		printSubTree(this->dx(n));
	/*
	std::cout << this->read(n) << ": ";
	if(!this->sxEmpty(n))
		print(this->sx(n));
	else
		std::cout << "NIL";
	std::cout << " " ;
	if(!this->dxEmpty(n))
		print(this->dx(n));
	else
		std::cout << "NIL";
	*/
}

template <class I>
void LinkBinAlberi<I>::print()const
{
	if(!this->empty())
		this->printSubTree(this->root());
	else
		std::cout << "Albero binario vuoto";
	std::cout << std::endl;
}

template <class I>
void LinkBinAlberi<I>::preVisita(node n)
{
	std::cout << this->read(n) << std::endl;
	if(!this->sxEmpty(n))
		this->preVisita(this->sx(n));
	if(!this->dxEmpty(n))
		this->preVisita(this->dx(n));

}

template <class I>
void LinkBinAlberi<I>::postVisita(node n)
{
	if(!this->sxEmpty(n))
		this->preVisita(this->sx(n));
	if(!this->dxEmpty(n))
		this->preVisita(this->dx(n));
	std::cout << this->read(n) << std::endl;
}
/*da completare
template <class I>
void LinkBinAlberi<I>::inVisita(node n , int i)
{
	if(this->leaf(n))
		std::cout << this->read(n) << std::endl;
	else
	{
		int k = 0;

	}

}
*/
template <class I>
void LinkBinAlberi<I>::simmetrica(node n)
{
	if(!this->sxEmpty(n))
		this->simmetrica(this->sx(n));
	std::cout << this->read(n) << std::endl;
	if(!this->dxEmpty(n))
		this->simmetrica(this->dx(n));

}

template <class I>
void LinkBinAlberi<I>::ampiezza(node n)
{
	Coda<node> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		node p = temp.leggiCoda();
		temp.fuoriCoda();
		std::cout << p->item << "  " << p->level <<  std::endl;
		if(!this->sxEmpty(p))
			temp.inCoda(this->sx(p));
		if(!this->dxEmpty(p))
			temp.inCoda(this->dx(p));
	}
}

#endif /* LINKBINALBERI_H_ */
