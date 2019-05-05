#include <stdio.h>
#include <iostream>
#include <exception>

template<class T>
void cambiaDimensione(T*& a, int vecchiaDim, int nuovaDim){
	if (nuovaDim < 0)
	throw illegalParameterValue(“la nuova lunghezza deve essere >= 0”);
	T* temp = new T[nuovaDim];
	int number;
	if (vecchiaDim < nuovaDim) then
	number = vecchiaDim;
	else
	number = nuovaDim;
	for (int i=0; i<number; i++)
	temp[i]=a[i];
	delete [] a;
	a = temp;
};
