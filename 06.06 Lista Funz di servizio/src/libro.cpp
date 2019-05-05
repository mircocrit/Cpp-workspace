#include <iostream>
#include "libro.h"
using namespace std;
//IMPLEMENTAZIONI

Libro::Libro(){ titolo = ""; }	//costruttori

Libro::Libro(string t){ setTitolo(t); }

void Libro::setTitolo(string t){titolo = t;}		//setter

string Libro::getTitolo() const{return (titolo);}	//getter

bool Libro::operator==(Libro l){				// sovraccarico dell'operatore ==
	return (getTitolo() == l.getTitolo());
}
