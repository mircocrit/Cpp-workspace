/*
 * stack.h
 *
 *  Created on: 22 ott 2018
 *      Author: utente
 */

#ifndef STACK_H_
#define STACK_H_

#include "linearStack.h"
#include <iostream>

template <class T>
class Stack;

template <class T>
class Nodo
{
public:
	friend class Stack<T>;
private:
	T valore;
	Nodo<T> *succ;
};

template <class T>
class Stack : public linearStack < T , Nodo<T>*>
{
public:
	typedef typename linearStack <T , Nodo<T>*>::valore valore;
	typedef typename linearStack <T , Nodo<T>*>::posizione posizione;

	Stack();
	~Stack();
	Stack(Stack<T>&);
	void creaPila();
	bool pilaVuota()const;
	valore leggiPila()const;
	void fuoriPila();
	void inPila(const valore&);
	void stampaPila();
	void stampaPilaRicorsiva(Stack<T>&);
	int size(){return numNodi;}
	Stack<T>& operator=(Stack<T>&);

private:
	Nodo<T> *head;
	int numNodi;

};

template <class T>
Stack<T>::Stack()
{
	head = new Nodo<T>;
	head->succ = head;
	numNodi = 0;
}

template <class T>
Stack<T>::~Stack()
{
	while(!pilaVuota())
		fuoriPila();
	delete head;
}

template <class T>
Stack<T>::Stack(Stack<T> &S)
{
	Stack<T> temp;
	this->numNodi = S.size();

	head = new Nodo<T>;
	head->succ = head;

	while(!S.pilaVuota())
	{
		valore elemento = S.leggiPila();
		temp.inPila(elemento);
		S.fuoriPila();
	}

	while(!temp.pilaVuota())
	{
		valore elemento = temp.leggiPila();
		inPila(elemento);
		S.inPila(elemento);
		temp.fuoriPila();
	}
}

template <class T>
void Stack<T>::creaPila()
{
	numNodi = 0;
}

template <class T>
bool Stack<T>::pilaVuota()const
{
	return(head->succ == head);
}

template <class T>
typename Stack<T>::valore Stack<T>::leggiPila()const
{
	return head->succ->valore;
}

template <class T>
void Stack<T>::fuoriPila()
{
	posizione nodo = new Nodo<T>;
	if(!pilaVuota())
	{
		nodo = head->succ;
		head->succ = head->succ->succ;
		delete nodo;
		numNodi--;
	}
	else
		std::cout << "Pila vuota" << std::endl;
}

template <class T>
void Stack<T>::inPila(const valore &V)
{
	posizione nodo = new Nodo<T>;
	nodo->valore = V;

	nodo->succ = head->succ;
	head->succ = nodo;
	numNodi++;

}

template <class T>
void Stack<T>::stampaPila()
{
	if(!pilaVuota())
	{
	while(!pilaVuota())
	{
		valore elemento = leggiPila();
		fuoriPila();
		std::cout << elemento << std::endl;
	}
	}
	else
		std::cout << "Pila vuota" << std::endl;
}

template <class T>
void Stack<T>::stampaPilaRicorsiva(Stack<T> &S)
{
	valore elemento;
	while(!S.pilaVuota())
	{
		elemento = S.leggiPila();
		S.fuoriPila();
		stampaPilaRicorsiva(S);
		std::cout << elemento;
		S.inPila(elemento);
	}
}

template <class T>
Stack<T>& Stack<T>::operator =(Stack<T> &S)
{
	if(this == &S)
		return *this;
	else
	{
		this->numNodi = S.size();
		this->~Stack();
		head = new Nodo<T>;
		head->succ = head;

		Stack<T> temp;

		while(!S.pilaVuota())
		{
			valore elemento = S.leggiPila();
			temp.inPila(elemento);
			S.fuoriPila();
		}

		while(!temp.pilaVuota())
		{
			valore elemento = temp.leggiPila();
			this->inPila(elemento);
			S.inPila(elemento);
			temp.fuoriPila();
		}

	}
	return *this;
}
#endif /* STACK_H_ */
