/*Lab 2
Definire il tipo di dato studente, utilizzando il costrutto struct, contenente le seguenti componenti:
	matricola: intero
	nome: stringa
	cognome: stringa
	eta: intero
Implementare, inoltre, le funzioni per l'
1) inserimento
2) stampa delle componenti della struttura.

Vincoli da rispettare:
1) il numero di matricola è un numero a sei cifre, che varia fra 255312 e 499999;
2) nome e cognome sono stringhe di max 30 caratteri;
3) età è un intero positivo che varia fra 12 e 105.

Suggerimenti
1. Definire un progetto Dev-C++ contente i file studente.h, studente.cpp e provastudente.cpp
2. Nel file studente.h definire la struttura e i prototipi delle funzioni
Stralcio del file studente.h:
3. Nel file studente.cpp implementare le funzioni
Stralcio del file studente.cpp:
#include "studente.h"
...
// funzioni per l'inserimento dei valori degli elementi della struttura

int setMatricola(studente *Studente){

cin >> Studente->matricola;

}

// funzioni per ottenere i valori degli elementi della struttura
char * getNome(studente *Studente){
return (Studente->Nome);
}

4. Nel file provastudente.cpp implementare il main che definisce variabili di tipo studente e utilizza le
funzioni definite nella libreria studente.h.
Risolvere lo stesso esercizio definendo la classe studente (piuttosto che la struttura) avente come metodi le
precedenti funzioni.*/



#include "Studente.h"

using namespace std;

int main(){
	Studente *s=new Studente(643228,"Mirco","Sipone",22);
	s->visual_studente();

	Studente *t=new Studente();
	t->insert_studente();
	t->visual_studente();
	cout<<t->get_cognome()<<endl;
    system("pause");
    return 0;
}

