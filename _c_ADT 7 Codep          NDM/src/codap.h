#ifndef _CODAPO_H_
#define _CODAP_H_

#include "assert.h"

template < class T >
class CodaP {
	public:
	  typedef T _tipoelem;

	  CodaP ():  MAXLUNG (100){
		  heap = new _tipoelem[MAXLUNG];
		  creaPrioriCoda ();											//
		};;
	  CodaP (int maxN):   MAXLUNG (maxN) {
		  heap = new _tipoelem[MAXLUNG];
		  creaPrioriCoda ();
		};;
	  ~CodaP (){				delete[]heap;};;

	  void creaPrioriCoda () { 				ultimo = 0;};;
	  void inserisci (_tipoelem);
	  _tipoelem min (){				 assert (ultimo != 0);			  return (heap[0]);};
	  void cancellaMin ();
////////////////////////////////
	private:
	  int MAXLUNG;
	  _tipoelem *heap;
	  int ultimo;

	  void fixUp ();										//salire il nodo
	  void fixDown (int, int);
};
//////////////////////////////////////////////////////////////////////////////////////////////////

template < class T > void CodaP < T >::inserisci (_tipoelem e) {
  assert (ultimo < MAXLUNG);		//si blocca
  heap[++ultimo - 1] = e;			//metto elem a fine: ultimo punta a prima cella libera vettore:: incremento ultimo!
  fixUp ();		//risalire ultimo tc figli <padre
};

//template < class T > typename CodaP < T >::_tipoelem CodaP < T >::min ()

template < class T > void CodaP < T >::cancellaMin () {
  assert (ultimo != 0);
  heap[0] = heap[ultimo - 1];
  ultimo--;	//ultimo = prima cell libera-> decrememnto
  fixDown (1,ultimo);
};


/* Per ripristinare i vincoli dello heap quando la priorità di un nodo è    cresciuta, ci spostiamo nello heap verso l'alto, scambiando, se necessario,* il nodo in posizione k con il suo nodo padre (in posizione k/2),           * continuando fintanto che heap[k]<heap[k/2] oppure fino a quando            * raggiungiamo la cima dello heap.                                           */

template < class T > void CodaP < T >::fixUp () {
  int k = ultimo;	//dala fine all'inizio
  while (k > 1 && heap[k - 1] < heap[k / 2 - 1]) {		//no radice e figlio minre del padre
      _tipoelem tmp;
      tmp = heap[k - 1];		//scambio
      heap[k - 1] = heap[k / 2 - 1];
      heap[k / 2 - 1] = tmp;
      k = k / 2;
    }

}

/* Per ripristinare i vincoli dello heap quando la priorità di un nodo si è   *
 * ridotta, ci spostiamo nello heap verso il basso, scambiando, se necessario,*
 * il nodo in posizione k con il minore dei suoi nodi figli e arrestandoci    *
 * quando il nodo al posto k non è più grande di almeno uno dei suoi figli    *
 * oppure quando raggiungiamo il fondo dello heap. Si noti che se N è pari e  *
 * k è N/2, allora il nodo in posizione k ha un solo figlio: questo caso      *
 * particolare deve essere trattato in modo appropriato.                      */

template < class T > void CodaP < T >::fixDown (int k, int N) {		//da 1 a n
  short int scambio = 1;		//bool
  while (k <= N / 2 && scambio) {		//padre< n/2
      int j = 2 * k;		//figlio
      _tipoelem tmp;
      if (j < N && heap[j - 1] > heap[j])		//no fuori array e quali dei due figli scegliere
				j++;		//mi sposto
      if (scambio = (heap[j - 1] < heap[k - 1])) {		//figlio piu piccolo del padre?
				tmp = heap[k - 1];
				heap[k - 1] = heap[j - 1];
				heap[j - 1] = tmp;
				k = j;
			}
  }
};

#endif /* _CODAP_H_ */
