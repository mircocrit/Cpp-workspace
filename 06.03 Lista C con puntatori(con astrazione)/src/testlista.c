#include <stdio.h>
#include <stdlib.h>
#include "listap.h"

int main(){
	Lista l;
	crealista(l);
//NON POSSO FARLO, DEVO PRIMA POPOLARLA
	posizione indiceElemento;
	tipoelem a;

	a = 1;
	inslista(a,indiceElemento);

	a = 2;
	indiceElemento = succlista(indiceElemento);
	inslista(a,indiceElemento);

	a = 3;
	indiceElemento = succlista(indiceElemento);
	inslista(a,indiceElemento);
	//posizione indiceElemento = primoLista(l);

	system("pause");
	return 0;
}
