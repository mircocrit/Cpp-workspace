#ifndef _LISTAP_H
#define _LISTAP_H

#include <stdio.h>
#include <stdlib.h>

typedef short int bool;
typedef int tipoelem;		//scegliere tipo lista

typedef struct _cella {
	tipoelem elemento;
	struct _cella* prec;
	struct _cella* succ;
} cella;

typedef cella* posizione;	//
typedef cella* Lista;	//strsso tipo

//operatori

void crealista(Lista);
bool listavuota(Lista);
tipoelem leggilista(posizione);
void scrivilista(tipoelem, posizione);//dove sta posizionenposso passare lista e viceversa
posizione primoLista(Lista);
bool finelista(posizione, Lista);
posizione succlista(posizione);
posizione preclista(posizione);
void inslista(tipoelem,posizione);
void canclista(posizione);

#endif // _LISTAP_H
