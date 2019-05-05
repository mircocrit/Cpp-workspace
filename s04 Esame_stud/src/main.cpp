/*Esercizio 4
Obiettivi: classi: costruttori e composizione di classi
1) Definire la classe esame nel file esame.h contenente le seguenti componenti:
metodi
	costruttore di default esame()
	costruttore esame(string): imposta solo il nome dell'esame
	costruttore esame(string,int): imposta nome e voto ottenuto dell'esame
	getEsame: restituisce il nome dell'esame
	setEsame(string nome): imposta il nome dell'esame
	getVoto: restituisce il voto ottenuto per l'esame se sostenuto
	setVoto: imposta il voto ottenuto per l'esame
	isSostenuto: restituisce true se l'esame � stato sostenuto
campi di esemplare
	Nome esame: stringa
	Sostenuto: boolean
	Voto esame: intero

esame.h
#ifndef _ESAME_H
#define _ESAME_H
#include
class esame{
public:
esame();
esame(string);
esame(string, int);
// ... da completare ...
private:
string nome;
// ... da completare ...
};
#endif // _ESAME_H

2) Implementare la classe esame nel file esame.cpp esame.cpp
#include
esame::esame(){}
// ... da completare ...
3) Testare la classe esame utilizando un tester TestEsame.cpp

4) Definire la classe studente nel file studente.h e implementa rla nel file studente.cpp: (Si suppone che uno studente debba fare al massimo 5 esami)
metodi:
	costruttore di default studente(): imposta i nomi di default dei 5 esami e i rispettivi flag
	sostenuto a false
	costruttore studente(nome1, nome2, nome3, nome4, nome5): imposta in nomi dei 5 esami
	usando i parametri nome1, ... e i rispettivi flag sostenuto a false
	setMatricola, setNome, getMatricola, getNome
	getNumEsami: restituisce 5 (numero massimo di esami da sostenere)
	setEsame(Voto,i): imposta il voto dell'esame i-esimo
	getVotoEsame(i), getNomeEsame(i), getSostenuto(i)
	getMedia(): restituisce la media degli esami sostenuti
	printStudente(): visualizza tutte le informazioni dello studente compresi gli esami sostenuti e i rispettivi voti
campi di esemplare
	matricola: string
	nome: string
	esami: vettore di 5 esami
	const numesami: intero
5) Testare la classe studente utilizando un tester Studente.cpp
6) Definire la classe studenti avente come campo di esemplare un vettore di 3 studenti e implementare alcuni
metodi di set, get e print.
*/



#include "studente.h"

int main(){
	studente a, b;
	a.print();
	a.setEsame(21, 2);
	a.print();
	cout << a.getMedia();
	cout << a;
	system("pause");
	return 0;
}
