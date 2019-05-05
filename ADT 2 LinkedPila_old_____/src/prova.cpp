/*
 * prova.cpp
 *
 *  Created on: 22 ott 2018
 *      Author: utente
 */
#include "stack.h"

int main(int argc , char *argv[])
{
	Stack<int> pila;
	for(int i=0;i<20;i++)
		pila.inPila(i+1);
	pila.stampaPila();



	system("pause");
	return 0;
}

