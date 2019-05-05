#include <stdio.h>
#include <stdlib.h>

typedef struct _lista{			/* Definizione tipo lista di interi */
	int elementi [3];
	int nelem;
}lista;

int main(){
	int i,nelem=0;

	lista L;					/* creazione della lista */
	L.nelem = 0;

	L.elementi[nelem] = 10;		/* inserimento primo elemento */
	L.nelem++;
	nelem++;

	L.elementi[nelem] = 20;		/* inserimento secondo elemento */
	L.nelem++;
	nelem++;
	L.elementi[nelem] = 30;		/* inserimento terzo elemento */
	L.nelem++;
	nelem++;

	i=0;						/* visualizzazione elementi */
	while (i < L.nelem){
		printf("%d ", L.elementi[i]);
		printf("\n");
		i++;
	}

	L.elementi[1] = L.elementi[2];printf("\n");		// eleminazione secondo elemento
	L.nelem--;

	i=0;
	while (i < L.nelem){
		printf("%d ", L.elementi[i]);printf("\n");
		i++;
	}

	system("pause");
	return 0;
}
