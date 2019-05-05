/*
 * linkBinAlberi.h
 *
 *  Created on: 20 nov 2018
 *      Author: utente
 */

#ifndef LINKBINALBERI_H_
#define LINKBINALBERI_H_

#include <iostream>
#include "Bin_Tree.h"

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
};

template <class I>
class LinkBinAlberi : public Bin_tree<I , TreeNode<I>*>
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


	//ausiliarie
	//void mutation(node,node);
	int getlevel(node n){return n->level;};
	bool leaf(node)const;
	item read(node) const;
	void write(node , item);
	//inserimento-cancelazione
	void insRoot(item);
	void insSx(node , item);
	void insDx(node , item);
	void erase(node);

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
/*
template <class I>
void LinkBinAlberi<I>::mutation(node u , node v)
{
	node temp;
	if(u->parent != nullptr && v->parent != nullptr)
	{
		if(u->parent->sx == u)
		{
			temp = u->parent->sx;
			u->parent->sx = v;
		}

		if(u->parent->dx == u)
		{
			temp = u->parent->sx;
			u->parent->dx = v;
		}

		if(v->parent->sx == v)
			v->parent->sx = temp;

		if(v->parent->dx == v)
			v->parent->dx = temp;

		u->parent = v;
		v->parent = u;
	}

	if(u->parent != nullptr && v->parent == nullptr)
	{
		node temp1 = u->sx;
		node temp2 = u->dx;

		u->sx = v->sx;
		u->dx = v->dx;

		v->sx = temp;
		u->dx = temp;
	}

	if(u->parent == nullptr && v->parent == nullptr)
	{
		node temp1 = u->sx;
		node temp2 = u->dx;

		u->sx = v->sx;
		u->dx = v->dx;

		v->sx = temp1;
		v->dx = temp2;

		u->sx->parent = u;
		u->dx->parent = u;

		v->sx->parent = v;
		v->dx->parent = v;

	}
}
*/

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
void LinkBinAlberi<I>::insRoot(item i)
{
	this->_root = new TreeNode<I>();
	this->_root->item = i;
	this->_root->level = 0;
}

template <class I>
void LinkBinAlberi<I>::insSx(node n , item i)
{
	if(this->sxEmpty(n))
	{
	node newNode = new TreeNode<I>();
	newNode->item = i;
	n->sx = newNode;
	newNode->parent = n;
	newNode->level = this->getlevel(this->parent(newNode))+1;//(newNode->parent->level)+1;
	}
	else
		std::cout << "Nodo sinistro pieno" << std::endl;
}

template <class I>
void LinkBinAlberi<I>::insDx(node n , item i)
{
	if(this->dxEmpty(n))
	{
		node newNode = new TreeNode<I>();
		newNode->item = i;
		n->dx = newNode;
		newNode->parent = n;
		newNode->level = this->getlevel(this->parent(newNode))+1;//(newNode->parent->level)+1;
	}
	else
		std::cout << "Nodo destro pieno" << std::endl;
}
#endif /* LINKBINALBERI_H_ */
