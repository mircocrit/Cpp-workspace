/*
Una struttura dati acquisisce numeri interi da 1 a 9 che inserisce in tre code secondo il seguente schema.
Gli interi da 1 a 3 vengono inseriti nella prima coda, quelli da 4 a 6 nella seconda, e i restanti nella
terza.
La struttura mette a disposizione una serie di metodi che permettono di conoscere e cambiare il suo
stato.
Realizzare in C++ la seguente classe che implementa la struttura appena descritta.
class Bins {
// inserisce l'intero k nella corrispondente coda
void insert(int k);
// effettua un fuoriCoda dalla coda c
void delete(int c);
// restituisce la media dei valori attualmente memorizzati nella coda c
double mean(int c);
// restituisce il numero di elementi inseriti nella coda c
int freq(int c);
private:
coda<int> bin[3];
}
Prevedere un main che mostri a video il test dei metodi implementati.
1
 */


#include "coda.h"
#include "codaLineare.h"

#ifndef FUNZIONI_H_
#define FUNZIONI_H_


class Bins{
	public:
		void insert(int);	// inserisce l'intero k nella corrispondente coda
		void deleteElem(int);	// effettua un fuoriCoda dalla coda c
		double mean(int);	// restituisce la media dei valori attualmente memorizzati nella coda c
		int freq(int);	// restituisce il numero di elementi inseriti nella coda c

	private:
		Coda<int> bin[3];
};


void Bins::insert(int k){
	if(k>=1 && k<=3)
		bin[0].inCoda(k);
	else if(k>=4 && k<=6)
		bin[1].inCoda(k);
	else if(k>=7 && k<=9)
		bin[2].inCoda(k);

}

void Bins::deleteElem(int c){	//coda 0 1 o 2
	if(c==0)
		bin[0].fuoriCoda();
	else if(c==1)
		bin[1].fuoriCoda();
	else
		bin[2].fuoriCoda();
}

double Bins::mean(int c){
	int med=0,i=0;
	while(i<bin[c].getSize()){
		int n=bin[c].leggiCoda();
		med+=n;
		bin[c].fuoriCoda();
		bin[c].inCoda(n);
		i++;
	};
	return med/i+1;
};

int Bins::freq(int c){
	return bin[c].getSize();
}




#endif /* FUNZIONI_H_ */
