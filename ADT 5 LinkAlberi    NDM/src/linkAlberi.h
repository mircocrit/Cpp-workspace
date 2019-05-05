/*
 * linkAlberi.h
 *
 *  Created on: 09 nov 2018
 *      Author: utente
 */

#ifndef LINKALBERI_H_
#define LINKALBERI_H_

#include <iostream>

#include "Tree.h"
#include "coda.h"

template<class I>
class LinkAlberi;

template<class I>
class TreeNode
{
	friend class LinkAlberi<I>;
	private:
	TreeNode<I> * _parent = nullptr;
	TreeNode<I> * _firstChild = nullptr;
	TreeNode<I> * _nextSibling = nullptr;
	I _item;
};


template<class I>
class LinkAlberi : public Tree <I,TreeNode<I>*>
{
 public:

	typedef I item;
	typedef TreeNode<I>* node;

	// Costruttori e distruttore
	LinkAlberi();
	~LinkAlberi();
	void create () ; //crea
	bool empty () const ; //albero vuoto
	void insRoot (item) ;
	node root () const ;
	node parent (node) const ;
	bool leaf (node) const ; //foglia ?
	node firstChild (node) const ;
	bool lastSibling (node) const ;//ultimo fratello
	node nextSibling (node) const ;//next fratello
	// Inserimenti / cancellazioni
	void insFirstSubTree (node, LinkAlberi&) ;
	void insSubTree (node, LinkAlberi&) ;
	void removeSubTree (node) ;
	void insFirst(node, item);
	void ins(node,item);

	//ausiliarie
	void writeNode (node,item) ;
	item readNode (node) const ;
	//int profondita(node);
	//int larghezza(node);
	//int numFoglie(node);
	//int contaFigli(node);

	//visite
	//void preVisita(node);
	//void postVisita(node);
	//void invisita(node,int);
	//void ampiezza(node);

 private:
	node _root;

};

template <class I>
LinkAlberi<I>::LinkAlberi()
{
	create();
}


template <class I>
LinkAlberi<I>::~LinkAlberi()
{
	//this->removeSubTree(this->root());
	delete this->_root;
}


template <class I>
void LinkAlberi<I>::create()
{
	_root = nullptr;
}

template <class I>
bool LinkAlberi<I>::empty() const
{
	return(_root==nullptr);
}

template <class I>
void LinkAlberi<I>::insRoot (item i)
{
	_root=new TreeNode<I>();
	_root->_item=i;
}

template <class I>
typename LinkAlberi<I>::node LinkAlberi<I>::root () const
{
	return _root;
}

template <class I>
typename LinkAlberi<I>::node LinkAlberi<I>::parent (node n) const
{
	if (n->_parent!=nullptr)
		return n->_parent;
}

template <class I>
bool LinkAlberi<I>::leaf(node n) const
{
	return (n->_firstChild==nullptr);
}

template <class I>
typename LinkAlberi<I>::node LinkAlberi<I>::firstChild (node n) const
{
	if (!leaf(n)){
		return n->_firstChild;
	}
}

template <class I>
bool LinkAlberi<I>::lastSibling (node n) const
{
	return (n->_nextSibling==nullptr);
}

template <class I>
typename LinkAlberi<I>::node LinkAlberi<I>::nextSibling (node n) const
{
	if (!lastSibling(n))
	{
		return n->_nextSibling;
	}
}


// inserisce un node come firstChild di n
template <class I>
void LinkAlberi<I>::insFirst(node n, item el)
{
	node newnode=new TreeNode<I>();
	newnode->_item=el;
	newnode->_nextSibling=n->_firstChild;
	newnode->_parent=n;
	n->_firstChild=newnode;
}

// inserisce un node come fratello di n
template <class I>
void LinkAlberi<I>::ins(node n, item el)
{
	node newnode=new TreeNode<I>();
	newnode->_item=el;
	newnode->_nextSibling=n->_nextSibling;
	newnode->_parent=n->_parent;
	n->_nextSibling=newnode;
}

template <class I>
void LinkAlberi<I>::insFirstSubTree(node n , LinkAlberi<I> &A)
{
	A.root()->_nextSibling = n->_firstChild;
	A.root()->_parent = n;
	n->_firstChild = A.root();
}

template <class I>
void LinkAlberi<I>::insSubTree(node n , LinkAlberi<I> &A)
{
	A.root()->_nextSibling = n->_nextSibling;
	A.root()->_parent = n->_parent;
	n->_nextSibling = A.root();
}

template <class I>
void LinkAlberi<I>::removeSubTree (node n)
{
	node p;
	if (!leaf(n))
	{
		p=n->_firstChild;
    	while (!lastSibling(p))
    	{
    		removeSubTree(p);
    		p=p->_nextSibling;
		}
		removeSubTree(p);
	}
	p = parent(n)->_firstChild;
	if (p==n)
	{
		parent(n)->_firstChild=p->_nextSibling;
		delete n;
	}
	else
	{
		while (!lastSibling(p) || p->_nextSibling!=n)
		{
			p=p->_nextSibling;
		}
		p->_nextSibling=p->_nextSibling->_nextSibling;
		delete p->_nextSibling;
	}
}

template <class I>
void LinkAlberi<I>::writeNode (node n, item el)
{
	n->_item=el;
}

template <class I>
typename LinkAlberi<I>::item LinkAlberi<I>::readNode (node n) const
{
	return n->_item;
}
/*
template <class I>
int LinkAlberi<I>::profondita(node n)
{
	node p;
	int max , temp;
	if(this->leaf(n))
		return 0;
	else
	{
		p = this->firstChild(n);
		max = 0;
		while(!this->lastSibling(p))
		{
			temp = this->profondita(p);
			if(max <= temp)
				max = temp;
			p = this->nextSibling(p);
		}
		max++;
	}
	return max;
}
*/
/*
template <class I>
void LinkAlberi<I>::preVisita(node n)
{
	node p;
	std::cout << n->_item << std::endl;
	if(!this->leaf(n))
	{
		p = this->firstChild(n);
		while(!this->lastSibling(p))
		{
			this->preVisita(p);
			p = this->nextSibling(p);
		}
		this->preVisita(p);
	}
}

template <class I>
void LinkAlberi<I>::postVisita(node n)
{
	node p;
	if(!this->leaf(n))
	{
		p = this->firstChild(n);
		while(!this->lastSibling(p))
		{
			this->postVisita(p);
			p = this->nextSibling(p);
		}
		this->postVisita(p);
	}
	std::cout << n->_item << std::endl;
}

template <class I>
void LinkAlberi<I>::invisita(node n , int i)
{
	if(this->leaf(n))
		std::cout << n->_item << std::endl;
	else
	{
		node p = this->firstChild(n);
		int k = 0;
		while(!this->lastSibling(p) && k < i)
		{
			k += 1;
			this->invisita(p , i);
			p = this->nextSibling(p);
		}
		std::cout << n->_item << std::endl;
		while(!this->lastSibling(p))
		{
			this->invisita(p , i);
			p = this->nextSibling(p);
		}

	}
}

template <class I>
void LinkAlberi<I>::ampiezza(node n)
{
	Coda<node> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		node p = temp.leggiCoda();
		temp.fuoriCoda();
		std::cout << p->_item << std::endl;
		p = this->firstChild(p);
		while(p)
		{
			temp.inCoda(p);
			p = this->nextSibling(p);
		}
	}
}
*/
/*
template <class I>
int LinkAlberi<I>::larghezza(node n)
{
	int count = 1;
	int larghezza = 1;
	Coda<node> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		node p = temp.leggiCoda();
		temp.fuoriCoda();
		node v = this->firstChild(p);
		while(v)
		{
			temp.inCoda(v);
			v = this->nextSibling(v);
		}
		count -= 1;
		if(count == 0)
		{
			count = temp.getSize();
			if(count > larghezza)
				larghezza = count;
		}
	}
	return larghezza;
}
*/
/*
template <class I>
int LinkAlberi<I>::contaFigli(node n)
{
	int count = 0;
	if(n->_parent == nullptr && n->_firstChild == nullptr)
		return 0;
	if(n->_firstChild == nullptr)
		return 0;
	else
	{
		node p = this->firstChild(n);
		count = 1;
		while(!this->lastSibling(p))
		{
			count++;
			p = this->nextSibling(p);
		}
	}
	return count;
}

template <class I>
int LinkAlberi<I>::numFoglie(node n)
{
	if(this->empty())
		return 0;

	if(this->leaf(n))
		return  1 + numFoglie(n->_nextSibling);
	else
		return numFoglie(n->_firstChild) + numFoglie(n->_nextSibling);

}
*/
#endif /* LINKALBERI_H_ */
