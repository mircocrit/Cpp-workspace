#ifndef MULTIPLESTACK_H_
#define MULTIPLESTACK_H_

/*Esercizio 2
Progettare ed implementare un classe MultipleStack che fornisca la gestione di m stack(pila).
La dichiarazione della classe dovrebbe essere simile a qualcosa del genere:
class MultipleStack
{
    // ...
public:
    MultipleStack (unsigned int);//n stack
    void Push (Object&, unsigned int);
    Object& Pop (unsigned int);
    // ...
};
Il costruttore ha in input un argomento di tipo intero che specifica il numero di stack da gestire
la funzione Push ha due argomenti. Il primo è l'oggetto da inserire e il secondo specifica lo stack in cui inserirlo
la funzione Pop ha in input un solo intero che specifica lo stack da cui eliminare un oggetto

Scegliere una delle seguenti implementazioni:
1) tenere tutti gli stack in un solo array
2) usare un array di oggetti di tipo Stack
3) Usare una lista collegata di oggetti di tipo Stack

*/

#include <iostream>
using namespace std;

#define MAX 10
#include "pilavt.h"

template <class T>
class MultipleStack{
  public:
    typedef T tipoelem;

    MultipleStack(int);
    ~MultipleStack();
    bool isEmpty() const{       		return n==0;};
    void DeleteStack(int);
    void Pop(int);	//ha in input un intero che specifica lo stack da cui eliminare un oggetto
    void Push(tipoelem&,int);//ha come argomenti l'oggetto da inserire e lo stack in cui inserirlo
    int get_length(int);
    tipoelem read(int i) const{      	return stack[i].leggiPila();};
  private:
    Pila<T> stack[MAX];
    int n;
 };


template <class T>
MultipleStack<T>::MultipleStack(int num){
	n=0;
	for(int i=0;i<num;i++){
		stack[i].creaPila();
		n++;
	}
}


template <class T>
MultipleStack<T>::~MultipleStack(){
	for(int i=0;i<n;i++){
		delete[] &stack[i];
	}
}

template <class T>
void MultipleStack<T>::DeleteStack(int i){
		delete &stack[i];
		n--;
	}


template <class T>
void MultipleStack<T>::Pop(int i){
	stack[i].fuoriPila();
}

template <class T>
void MultipleStack<T>::Push(tipoelem &elem, int i){
	stack[i].inPila(elem);
}

template <class T>
int MultipleStack<T>::get_length(int i){
	return stack[i].lungh();
}
#endif /* MULTIPLESTACK_H_ */
