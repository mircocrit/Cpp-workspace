#include "class_matrice.h"
#include <cstdlib>

Matrice::Matrice(int r , int c) : righe(r),colonne(c){
	elementi = new tipo_elem *[righe];
	for(int i=0;i<righe;i++)
		elementi[i] = new tipo_elem[colonne];
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] = 0;
}

Matrice::~Matrice(){
	for(int j=0;j<colonne;j++)
		delete[] elementi[j];
	delete[]elementi;
}

Matrice::Matrice(const Matrice& old){
	righe = old.righe;
	colonne = old.colonne;
	elementi = new tipo_elem *[righe];
	for(int i=0;i<righe;i++)
		elementi[i] = new tipo_elem [colonne];
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] = old.elementi[i][j];
}

Matrice &Matrice::operator=(const Matrice& m){
	if(&m == this)
		return *this;
	else{
		if( colonne != m.colonne  || righe != m.righe){
		this->~Matrice();
		righe = m.righe;
		colonne = m.colonne;
		elementi = new tipo_elem*[righe];
		for(int i=0;i<righe;i++)
			elementi[i] = new tipo_elem[colonne];
	}
		for(int i=0;i<righe;i++)
		    for(int j=0;j<colonne;j++)
			    elementi[i][j] = m.elementi[i][j];
	}
	return *this;
}

Matrice::tipo_elem Matrice::leggi_matrice(int r , int c){		return elementi[r][c];}

void Matrice::scrivi_matrice(int r,int c,tipo_elem val){	elementi[r][c] = val;}

void Matrice::output_matrice(){
	for(int i=0;i<righe;i++){
		for(int j=0;j<colonne;j++)
			std::cout << leggi_matrice(i,j) << " ";
		std::cout << std::endl;
	}
}

void Matrice::prodotto_scalare(tipo_elem val){
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] *= val;
}

Matrice Matrice::trasposta(){
	Matrice trasposta(colonne,righe);
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			trasposta.scrivi_matrice(j,i,elementi[i][j]);
	return trasposta;
}

void Matrice::random(){
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] = rand() % 100;
}
