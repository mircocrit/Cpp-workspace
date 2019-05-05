#include "Studente.h"

Studente::Studente(int matr,string name,string surn,int age): matricola(matr),nome(name),cognome(surn),eta(age){}
Studente::Studente(int matr,string name,string surn):Studente(matr,name,surn,0){};
Studente::Studente(int matr,string name):Studente(matr,name,"",0){};
Studente::Studente(int matr):Studente(matr,"","",0){};
Studente::Studente():Studente(0,"","",0){};

void Studente::set_matr(int matr){
	if(matr<255312 || matr> 499999 )
		throw invalid_argument("Errore,matricola fra 255312 e 499999");
	this->matricola = matr;

		}		//setter

void Studente::set_nome(string name) {
	if(name.length()>30)
		throw invalid_argument("Errore, nome con piu di 30 cifre");
	this->nome=name;

};

void Studente::set_cognome(string surn){
	if(surn.length()>30)
		throw invalid_argument("Errore, cognome con piu di 30 cifre");
	this->cognome = surn;
}

void Studente::set_eta(int age){//12 105.
	if(age<12 || age> 105 )
		throw invalid_argument("Errore,eta deve essere fra 12 e 105");
	this->eta = age;
}

int Studente::get_eta(){return this->eta;}
string Studente::get_nome(){return this->nome;}
string Studente::get_cognome(){return this->cognome;}
int Studente::get_matricola(){return this->matricola;}

void Studente::insert_studente(){
	string name,surname;
	int matr,age;

	cout<<"Nome"<<endl;
	cin>>name;
	try{
		set_nome(name);
	}
	catch(invalid_argument& e){
		cerr << e.what() << endl;
		return;
	}

	cout<<"Cognome"<<endl;
	cin>>surname;
	try{
		set_cognome(surname);
	}
	catch(invalid_argument& e){
		cerr << e.what() << endl;
		return;
	}

	cout<<"Eta"<<endl;
	cin>>age;
	try{
		set_eta(age);
	}catch(invalid_argument& e){
		cerr << e.what() << endl;
		return;
	}

	cout<<"Matricola"<<endl;
	cin>>matr;
	try{
		set_matr(matr);
	}catch(invalid_argument& e){
		cerr << e.what() << endl;
		return;
	}
}

void Studente::visual_studente(){
	cout<<"Nome:	"<<get_nome()<<endl;
	cout<<"Cognome:	"<<get_cognome()<<endl;
	cout<<"Eta:	"<<get_eta()<<endl;
	cout<<"Matricola:	"<<get_matricola()<<endl;

}
