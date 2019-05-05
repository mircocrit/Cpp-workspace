/*
3. Data una pila di interi, implementare in C++ una funzione che restituisca una nuova pila i cui elementi corrispondano a quelli presenti nella pila data e siano ordinati dall’alto
(top dello stack) al basso.
Prevedere una funzione nel main che contenga una procedura di inserimento automatico
e successivamente il test della funzione implementata.
 */

#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "pila.h"

int pivot(int A[], int primo, int ultimo)
{
  int x = A[primo];
  int j = primo;

  for (int i=primo; i<=ultimo; i++)
  {
    if (A[i] < x)
    {
      j++;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  A[primo] = A[j];
  A[j] = x;
  return j;
}

void quicksort_rec(int A[], int primo, int ultimo)
{
  if (primo < ultimo)
  {
    int j = pivot(A, primo, ultimo);
    quicksort_rec(A, primo, j-1);
    quicksort_rec(A, j+1, ultimo);
  }
}

void quicksort(int A[], int n)
{
  quicksort_rec(A, 0, n-1);
}

template < class I >
void ordinaPila(PilaLineare<int,I> &P)
{
	int i = 0 , n = P.getSize();
	std::cout << "n " << n << "\n";
	int *tmp = new int[n];

	while(!P.pilaVuota())
	{
		tmp[i] = P.leggiPila();
		P.fuoriPila();
		i++;
	}

	quicksort(tmp,n);

	for(int i=0;i<n;i++)
		P.inPila(tmp[i]);

	delete []tmp;
}

#endif /* FUNZIONI_H_ */
