#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "listap.h"

typedef cella* posizione;
typedef cella* Lista; //la lista e' un ARRAY DI CELLE
//tipoelem int

void crealista(Lista L){//PASSO UN ARRAY DI CELLE
	//tipoelem ElementoNullo;
	L = (Lista) malloc(sizeof(cella));
	L->succ = L;
	L->prec = L;
}

bool listavuota(Lista L){	return ((L->succ == L) && (L->prec == L));}
posizione primoLista(Lista L){	return(L->succ);}//posiz=ptat a struhttura
posizione succlista(posizione p){	return p->succ;}
posizione preclista(posizione p){	return p->prec;}
bool finelista(posizione p, Lista L){	return (p==L);}//lista circolare
tipoelem leggilista(posizione p) {	return p->elemento;}
//tipoelem leggilista(posizione p, Lista L) {	return L.elementi[p];}
void scrivilista(tipoelem a, posizione p){		p->elemento = a;}

void inslista(tipoelem a, posizione p){
	posizione temp = (Lista) malloc(sizeof(cella));
	temp->elemento = a;
	temp->prec = p->prec;
	temp->succ = p;

	p->prec->succ = temp;
	p->prec = temp;
	p=temp;
}

void canclista(posizione p){
	posizione temp;
	temp=p;
	p->succ->prec = p->prec;
	p->prec->succ = p->succ;
	p=p->succ;
	free(temp);
}
