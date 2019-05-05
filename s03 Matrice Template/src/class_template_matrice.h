#ifndef CLASS_TEMPLATE_MATRICE_H_
#define CLASS_TEMPLATE_MATRICE_H_

#include <cstdlib>
#include <iostream>

template <class T>
class Matrice{
	public:
		Matrice(int r,int c): righe(r),colonne(c){
			elementi = new T*[righe];
			for(int i=0;i<righe;i++)
				elementi[i] = new T[colonne];
			for(int i=0;i<righe;i++)
				for(int j=0;j<colonne;j++)
					elementi[i][j] = 0;

		};

		Matrice(const Matrice& m){
			righe = m.righe;
			colonne = m.colonne;
			elementi = new T*[righe];
			for(int i=0;i<righe;i++)
				elementi[i] = new T[colonne];
			for(int i=0;i<righe;i++)
				for(int j=0;j<colonne;j++)
					elementi[i][j] = m.elementi[i][j];
		};
		Matrice& operator=(const Matrice& m){
			if(&m == this)
				return *this;
			else
			{
				if(righe != m.righe || colonne != m.colonne)
				{
					righe = m.colonne;
					colonne = m.righe;
					this->~Matrice();
					elementi = new T*[righe];
					for(int i=0;i<righe;i++)
						elementi[i] = new T[colonne];
					for(int i=0;i<righe;i++)
						for(int j=0;j<colonne;j++)
							elementi[i][j] = 0;
				}
			}
			return *this;
		};
		T leggi_matrice(int r,int c){
			return elementi[r][c];
		};
		void scrivi_matrice(int r , int c , T val){
			elementi[r][c] = val;
		};
		void output_matrice(){
			for(int i=0;i<righe;i++)
			{
				for(int j=0;j<colonne;j++)
					std::cout << elementi[i][j] << " "<<std::endl;
				std::cout <<std::endl;
			}
		};
		void random(){
			for(int i=0;i<righe;i++)
				for(int j=0;j<colonne;j++)
					elementi[i][j] = rand() % 100;
		};
		void prodotto_scalare(T val){
			for(int i=0;i<righe;i++)
				for(int j=0;j<colonne;j++)
					elementi[i][j] *= val;
		};
		Matrice trasposta(){
			Matrice<T> m(colonne,righe);

			for(int i=0;i<righe;i++)
				for(int j=0;j<colonne;j++)
					/*m.elementi[i][j] =*/ scrivi_matrice(j,i,elementi[i][j]);
			return m;
		};
		~Matrice(){
			for(int j=0;j<colonne;j++)
				delete[] elementi[j];
			delete[] elementi;
		};

	private:
		int righe;
		int colonne;
		T **elementi;
};

//#include "class_template_matrice.h"
/*
template <typename T>
Matrice<T>::Matrice(int r , int c): righe(r),colonne(c)
{
	elementi = new T*[righe];
	for(int i=0;i<righe;i++)
		elementi[i] = new T[colonne];
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] = 0;

}
*/
/*
template <typename T>
Matrice<T>::~Matrice()
{
	for(int j=0;j<colonne;j++)
		delete[] elementi[j];
	delete[] elementi;
}
*/
/*
template<typename T>
Matrice<T>::Matrice(const Matrice<T>& m)
{
	righe = m.righe;
	colonne = m.colonne;
	elementi = new T*[righe];
	for(int i=0;i<righe;i++)
		elementi[i] = new T[colonne];
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] = m.elementi[i][j];
}
*/
/*
template<typename T>
Matrice<T>& Matrice<T>::operator=(const Matrice<T>& m)
{
	if(&m == this)
		return *this;
	else
	{
		if(righe != m.righe || colonne != m.colonne)
		{
			righe = m.colonne;
			colonne = m.righe;
			this->~Matrice();
			elementi = new T*[righe];
			for(int i=0;i<righe;i++)
				elementi[i] = new T[colonne];
			for(int i=0;i<righe;i++)
				for(int j=0;j<colonne;j++)
					elementi[i][j] = 0;
		}
	}
	return *this;
}
*/
/*
template <typename T>
T Matrice<T>::leggi_matrice(int r , int c)
{
	return elementi[r][c];
}

template <typename T>
void Matrice<T>::scrivi_matrice(int r ,int c, T val)
{
	elementi[r][c] = val;
}
*/
/*
template <typename T>
void Matrice<T>::output_matrice()
{
	for(int i=0;i<righe;i++)
	{
		for(int j=0;j<colonne;j++)
			std::cout << elementi[i][j] << " ";
		std::cout << std::endl;
	}
}
*/
/*
template <typename T>
void Matrice<T>::random()
{
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] = rand() % 100;
}
*/
/*
template <typename T>
void Matrice<T>::prodotto_scalare(T val)
{
	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			elementi[i][j] *= val;
}

template <typename T>
Matrice<T> Matrice<T>::trasposta()
{
	Matrice<T> m(colonne,righe);

	for(int i=0;i<righe;i++)
		for(int j=0;j<colonne;j++)
			m.elementi[i][j] = scrivi_matrice(j,i,elementi[i][j]);
	return m;
}
*/


#endif /* CLASS_TEMPLATE_MATRICE_H_ */
