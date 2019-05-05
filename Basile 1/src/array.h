//definisce una struct per memorizzare un intero con la relativa posizione
struct elempos {
	int elem;
	int pos;
};

//ha in input un array A e un intero k e restituisce il numero di elementi di A che sono maggiori di k
int greaterThan(int, int *, int);

//ha in input un array A e un intero k e restituisce true se k è presente in A
int member(int, int *, int k);

//ha in input un array A e restutuisce il valore del più grande elemento presente in A e la sua posizione
struct elempos largest(int, int *);

//ha in input un array A e un intero k e elimina la prima occorrenza di k in A facendo uno shift a sinistra di tutti gli elementi che seguono k e scrivendo zero alla fine dell'array
void arrayRemove(int, int *, int);

//ha in input un array A e stabilisce se gli elementi in A sono in ordine crescente, descrescente o costante
int ordering(int, int *);

//ha in input un array A e lo modifca invertendone gli elementi
void reverse(int, int *);

int greaterThan(int n, int *a, int k) {
	int g=0;
	for (int i=0;i<n;i++) {
		if (*a>k)
			g++;
		*a++;
	}
	return g;
}

int member(int n, int *a, int k) {
	for (int i=0;i<n;i++) {
		if (*a==k)
			return 1;
		*a++;
	}
	return 0;
}

struct elempos largest(int n, int *a) {
	struct elempos e={0,-1};
	if (n>0) {
		e.elem=*a;
		e.pos=0;
		*a++;
		for (int i=1;i<n;i++) {
			if (*a>e.elem) {
				e.elem=*a;
				e.pos=i;
			}
			*a++;
		}
	}
	return e;
}

void arrayRemove(int n, int *a, int k) {
	int i=0;
	while (i<n && *a!=k) {
		*a++;
		i++;
	}
	i++;
	while (i<n) {
		*a=*(a+1);
		i++;
		*a++;
	}
	*a=0;
}

// 0 - crescente
// 1 - decrescente
// 2 - costante
// -1 - none
int ordering(int n, int *a) {
	int i=0;
	while (i<n-1 && *a<=*(a+1)) {
		*a++;
		i++;
	}
	if (i==n-1) return 0;
	i=0;
	while (i<n-1 && *a>=*(a+1)) {
		*a++;
		i++;
	}
	if (i==n-1) return 1;
	i=0;
	while (i<n-1 && *a==*(a+1)) {
		*a++;
		i++;
	}
	if (i==n-1) return 0;
	return -1;
}

void reverse(int n, int *a) {
	int c=n/2;
	int *b=(a+n-1);
	for (int i=0;i<c;i++) {
		int tmp=*a;
		*a=*b;
		*b=tmp;
		*a++;
		*b--;
	}
}
