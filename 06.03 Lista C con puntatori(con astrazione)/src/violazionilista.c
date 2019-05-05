//VIOLAZIONI
/*
#include "listap.h"
int main(){
	Lista l;
	posizione p, indiceElemento;
	crealista(l);
	crealista(p); // violazione 1 //
	indiceElemento = primoLista(l);
	tipoelem a;
	a = 1;
	p = l; // violazione 2 //
	p->elemento = 12; // violazione 3 //
	inslista(a,indiceElemento);
	a = 2;
	p = p->succ; // violazione 4 //
	p->elemento = 31; // violazione 5 //
	p = p->prec; // violazione 6 //
	p = NULL; // violazione 7 //
	return 0;
}
*/
