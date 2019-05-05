#include <stdio.h>
#include "array.h"

#define alen(array) (sizeof(array)/sizeof(*array));

void main() {
	int a[]={4,2,5,1,9,3,10};
	int n=alen(a);
	printf("Gli elementi maggiori di 4 sono %d \n", greaterThan(n, a, 4));
	printf("Il vettore contiene 4 %s \n", member(n, a, 4)==0 ? "NO" : "SI");
	printf("Il vettore contiene 24 %s \n", member(n, a, 24)==0 ? "NO" : "SI");
	struct elempos r=largest(n, a);
	printf("L'elemento più grade del vettore è %d e si trova in posizione %d \n", r.elem, r.pos);
	printf("Tipo di ordinamento %d \n", ordering(n, a));
	int b[]={4,2,1,0};
	n=alen(b);
	printf("Tipo di ordinamento %d \n", ordering(n, b));
	int c[]={1,1,1,1};
	n=alen(c);
	printf("Tipo di ordinamento %d \n", ordering(n, c));
	int d[]={4,6,1,0,4,5};
	n=alen(d);
	printf("Tipo di ordinamento %d \n", ordering(n, d));
	n=alen(a);
	reverse(n, a);
	printf("Array invertito\n");
	for (int i=0;i<n;i++) {
		printf("%d, ",a[i]);
	}
	printf("\n");
	arrayRemove(n, a, 5);
	printf("Array dopo rimozione dell'elemento %d\n", 5);
	for (int i=0;i<n;i++) {
		printf("%d, ",a[i]);
	}
	printf("\n");
}
