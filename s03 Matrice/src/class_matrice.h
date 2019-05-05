#ifndef CLASS_MATRICE_H_
#define CLASS_MATRICE_H_

#include <cstdlib>
#include <iostream>

class Matrice{
	public:
		using tipo_elem = double;
		Matrice(int,int);
		~Matrice();
		Matrice(const Matrice&);
		Matrice& operator= (const Matrice&);
		tipo_elem leggi_matrice(int,int);
		void scrivi_matrice(int,int,tipo_elem);
		void output_matrice();
		void prodotto_scalare(tipo_elem);
		Matrice trasposta();
		void random();
	private:
		int righe;
		int colonne;
		tipo_elem **elementi;
};

#endif /* CLASS_MATRICE_H_ */
