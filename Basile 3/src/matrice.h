
#ifndef MATRICE_H
#define MATRICE_H

typedef double tipoelem;

class matrice {
 public:
	matrice(int, int); // costruttore
	~matrice();
	matrice(const matrice &);
	matrice & operator=(const matrice &);
	tipoelem leggimatrice(int, int) const;
	void scrivimatrice(int, int, tipoelem);
	void prodottoScalare(double);
	matrice trasposta();
  matrice prodotto(const matrice &);
	void stampa();
	void random();
 private:
	int righe;
	int colonne;
	tipoelem **elementi;
};

#endif
