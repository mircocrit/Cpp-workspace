/*Programma per l'inserimento, in una lista, di tre elementi, visualizzazione degli elementi, e
rimozione del secondo elemento*/
//Relazione con i puntatori , elementi di tipo intero
#include <stdio.h>
#include <stdlib.h>
//no operatori , no classi ,no tipo template
typedef struct elemento_lista{		/* Definizione tipo nodo */
	int valore;
	struct elemento_lista *succ;
}nodo;

typedef nodo* lista;	/* Definizione tipo lista di interi */


int main(){
	lista iter, supp;
	lista L = NULL; /* creazione della lista */

	L = (lista) malloc (sizeof(nodo));		/* inserimento primo elemento */
	L->valore = 1; 			L->succ = NULL;

	iter = L;
	iter->succ = (lista) malloc (sizeof(nodo));		/* inserimento secondo elemento */
	iter->succ->valore = 2; 		iter->succ->succ = NULL;

	iter = iter->succ;
	iter->succ = (lista) malloc (sizeof(nodo));		/* inserimento terzo elemento */
	iter->succ->valore = 3; 		iter->succ->succ = NULL;

	iter = L;					 /* visualizzazione elementi */
	while (iter != NULL){
		printf("%d ",iter->valore);
		iter = iter->succ;
	}

	iter = L->succ;				/* eleminazione secondo elemento */
	L->succ = iter->succ;
	free(iter);
	system("pause");
	return 0;
}
