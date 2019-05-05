/*
 * codaPriorità.h
 *
 *  Created on: 03 dic 2018
 *      Author: utente
 */

#ifndef CODAPRIORITA_H_
#define CODAPRIORITA_H_

#include "codaPrioritaLineare.h"
#include "linkBinAlberi.h"

template <class I>
class CodaPriorita : public CodaPrioritaLineare<I,TreeNode<I>*>
{
public:
	typedef typename CodaPrioritaLineare<I,TreeNode<I>*>::tipoElem tipoElem;
	typedef typename CodaPrioritaLineare<I,TreeNode<I>*>::posizione node;

	CodaPriorita();
	~CodaPriorita();
	void creaPrioriCoda();
	void inserisci(tipoElem);
	tipoElem min() const;
	void cancellaMin();
private:
	LinkBinAlberi<I> priorityQueue;
	node lastLeaf;


};

template <class I>
CodaPriorita<I>::CodaPriorita()
{
	creaPrioriCoda();
	this->lastLeaf = nullptr;
}

template <class I>
CodaPriorita<I>::~CodaPriorita()
{
	priorityQueue.~LinkBinAlberi();
}

template <class I>
void CodaPriorita<I>::creaPrioriCoda()
{
	priorityQueue.create();
}

template <class I>
void CodaPriorita<I>::inserisci(tipoElem i)
{
	node p;

	if(this->priorityQueue.empty())
	{
		this->priorityQueue.insRoot(i);
		this->lastLeaf = this->priorityQueue.root();
	}

	else if(this->priorityQueue.sxEmpty(this->priorityQueue.root()) && this->priorityQueue.dxEmpty(this->priorityQueue.root()))
	{
		this->priorityQueue.insSx(this->priorityQueue.root(),i);
		this->lastLeaf = this->priorityQueue.sx(this->priorityQueue.root());
	}

	else if(this->priorityQueue.isFiglioSx(lastLeaf))//(this->priorityQueue.getTipoFiglio(lastLeaf) == 's')//if(!this->priorityQueue.sxEmpty(this->priorityQueue.parent(this->lastLeaf)) && this->priorityQueue.dxEmpty(this->priorityQueue.parent(this->lastLeaf)))
	{
		this->priorityQueue.insDx((this->priorityQueue.parent(this->lastLeaf)),i);
		this->lastLeaf = this->priorityQueue.dx(this->priorityQueue.parent(this->lastLeaf));
	}

	else
	{

		p = this->lastLeaf;

		while(this->priorityQueue.isFiglioDx(p))//(this->priorityQueue.getTipoFiglio(p) == 'd')//this->priorityQueue.dx(this->priorityQueue.parent(p)) == p)
		{
			//std::cout << this->priorityQueue.read(p);
			p = this->priorityQueue.parent(p);
		}
		if(!this->priorityQueue.isRoot(p))
			p = this->priorityQueue.dx(this->priorityQueue.parent(p));
		else
			p = this->priorityQueue.root();

		while(!this->priorityQueue.leaf(p))
		{
			p = this->priorityQueue.sx(p);
		}

		//std::cout << this->priorityQueue.read(p);

		this->priorityQueue.insSx(p,i);
		this->lastLeaf = this->priorityQueue.sx(p);
		//std::cout << this->priorityQueue.read(lastLeaf);
	}

	p = lastLeaf;

	while(!this->priorityQueue.isRoot(p) && this->priorityQueue.read(p) < this->priorityQueue.read(this->priorityQueue.parent(p)))
	{
		if(this->priorityQueue.read(p) < this->priorityQueue.read(this->priorityQueue.parent(p)))
		{
		typename LinkBinAlberi<I>::item tmp = this->priorityQueue.read(p);
		this->priorityQueue.write(p,this->priorityQueue.read(this->priorityQueue.parent(p)));//p->item = p->parent->item;
		this->priorityQueue.write(this->priorityQueue.parent(p),tmp);//p->parent->item = tmp;
		}

		p = this->priorityQueue.parent(p);
	}
}

template <class I>
void CodaPriorita<I>::cancellaMin()
{
	node p;

	if(!this->priorityQueue.empty())
	{
		if(this->priorityQueue.leaf(this->priorityQueue.root()))
			this->priorityQueue.erase(this->priorityQueue.root());
		else
		{
			this->priorityQueue.write(this->priorityQueue.root(),this->priorityQueue.read(lastLeaf));
			this->priorityQueue.erase(lastLeaf);
		}
		// inizio della modifica della struttura
		if(this->priorityQueue.isFiglioDx(lastLeaf))//(this->priorityQueue.getTipoFiglio(lastLeaf) == 'd')
			lastLeaf = this->priorityQueue.sx(this->priorityQueue.parent(lastLeaf));
		else
		{
			p = lastLeaf;
			while(this->priorityQueue.isFiglioDx(p))//(this->priorityQueue.getTipoFiglio(p) == 's')
				p = this->priorityQueue.parent(p);
			if(!this->priorityQueue.isRoot(p))
				p = this->priorityQueue.sx(this->priorityQueue.parent(p));
			while(!this->priorityQueue.leaf(p))
				p = this->priorityQueue.dx(p);
			lastLeaf = p;
		}
	}

	// inizio della fase di aggiornamento delle priorità partendo dalla radice
	p = this->priorityQueue.root();
	while(!this->priorityQueue.leaf(p) && (this->priorityQueue.read(p) > this->priorityQueue.read(this->priorityQueue.sx(p)) && this->priorityQueue.read(p) > this->priorityQueue.read(this->priorityQueue.dx(p))))
	{
		node max;
		if(!this->priorityQueue.sxEmpty(p) && !this->priorityQueue.dxEmpty(p))
		{
			if(this->priorityQueue.read(this->priorityQueue.sx(p)) < this->priorityQueue.read(this->priorityQueue.dx(p)))
				max = this->priorityQueue.sx(p);
			else
				max = this->priorityQueue.dx(p);
		}
		else
			max = this->priorityQueue.sx(p);

		//typename LinkBinAlberi<I>::item tmp;
		tipoElem tmp;
		tmp = this->priorityQueue.read(p);
		this->priorityQueue.write(p,this->priorityQueue.read(max));
		this->priorityQueue.write(max,tmp);

		p = max;
		//scambio max con p;
		//in p max
	}
}

template <class I>
typename CodaPriorita<I>::tipoElem CodaPriorita<I>::min() const
{
	return this->priorityQueue.read(this->priorityQueue.root());
}


#endif /* CODAPRIORITA_H_ */
