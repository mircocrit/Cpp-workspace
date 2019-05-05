#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Studente{
	private:
		int matricola;
		string nome;
		string cognome;
		int eta;
	public:
		Studente(int matr,string name,string surn,int age);
		Studente(int matr,string name,string surn);
		Studente(int matr,string name);
		Studente(int matr);
		Studente();

		void set_matr(int matr);
		void set_nome(string name);
		void set_cognome(string surn);
		void set_eta(int age);

		int get_eta();
		string get_nome();
		string get_cognome();
		int get_matricola();

		void insert_studente();
		void visual_studente();

		//~Studente();
};


