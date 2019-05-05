/*Alberi Binari
 *
-Esercizio 1:
Scrivere un programma ricorsivo che cancella da un albero binario di nodi con valore intero tutte le foglie di valore pari.

-Esercizio 2:
Modificare la struttura cella in modo da poter memorizzare per ogni nodo n il numero di nodi che si trovano nel sottoalbero con radice in n.
Modificare di conseguenza la stampa di un albero binario in modo che visualizzi, per ogni nodo n, l'etichetta di n e il numero di nodi del sottoalbero radicato in n.

-Esercizio 3:
Dati due alberi binari A e B, e due nodi u e v, con u appartenente ad A e v appartenente a B,
implementare la funzione mutation che scambia i sottoalberi con radice u e v.
Realizzare la ADT Alberi Binari mediante vettore sequenziale e mediante puntatori.

-Esercizio 4:
Scrivere un programma in grado di acquisire e rappresentare con un albero di analisi (parse tree) un'espressione aritmetica.
Fornire la funzione per la valutazione dell'espressione rappresentata da un albero.
*/
#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "Bin_tree.h"

template <class T,class P>
void visitaSimmetrica(Bin_tree<T,P> &t, typename Bin_tree<T,P>::Nodo u) {
	if(	!t.sx_empty(u)){
		visitaSimmetrica(t,t.sx(u));
	}
	std::cout<<t.read(u)<<"	";
	if (!t.dx_empty(u)) {
		visitaSimmetrica(t,t.dx(u));
	}
}

template <class T, class P>
void visitaAmpiezza(Bin_tree<T,P> &t,typename Bin_tree<T,P>::Nodo u) {
	//if(is_root(u))	std::cout<<read(u)<<"	";

	if(!t.sx_empty(u)){
		std::cout<<t.read(t.sx(u))<<"	";
	}
	if (!t.dx_empty(u)) {
		std::cout<<t.read(t.dx(u))<<"	";
	}
	visitaSimmetrica(t,t.sx(u));
	visitaSimmetrica(t,t.dx(u));
}


#endif /* FUNZIONI_H_ */
