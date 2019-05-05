/*Lab 3
Realizzare in C++ la struttura dati matrice (che rappresenti l'ente geometrico matrice e le operazioni che la matematica prevede).
In particolare:
-definire il tipo tipoelem:			typedef double tipoelem;
-definire la classe matrice:
class matrice {
	public:
	matrice(int, int); // costruttore
	tipoelem leggimatrice(int, int);
	void scrivimatrice(int, int, tipoelem);
	private:
	int righe;
	int colonne;
	tipoelem **elementi;
};
// costruttore
matrice::matrice(int c, int r){
colonne = c;
righe = r;
// allocazione dinamica della matrice
int i;
elementi = new tipoelem* [righe];
for (i=0; i < righe; i++)
elementi[i] = new tipoelem[colonne];
// inizializzazione degli elementi
...
}

1. completare la definizione della classe fornendo le implementazioni per il costruttore, e per i metodi
leggimatrice (restituisce l'elemento in posizone i,j) e scrivimatrice (scrive l'elemento in posizione i,j)
2. realizzare il metodo prodottoScalare(double scalare) che moltiplica ogni elemento della matrice con uno scalare
3. realizzare il metodo trasposta(), che restituisce la trasposta di una matrice
4. realizzare il metodo prodotto(matrice M), che restituisce il prodotto di due matrici
ATTENZIONE
1. Definire nel file header matrice.h la definizione della classe
2. Implementare nel file matrice.cpp i metodi della classe matrice
3. Testare la classe matrice nel file TestMatrice.cpp
*/
#include "class_matrice.h"

int main(){
	Matrice a(4,4) , b(4,4);

	a.random();
	a.output_matrice();
	std::cout << std::endl;

	b.random();
	b.output_matrice();
	std::cout << std::endl;
	b.trasposta();
	b.output_matrice();

	system("pause");
	return 0;
}


