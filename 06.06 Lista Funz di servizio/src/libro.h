#ifndef _LIBRO_H
#define _LIBRO_H

#include <string>
#include <iostream>

using namespace std;

class Libro{
	public:
		Libro();
		Libro(string);

		void setTitolo(string);
		string getTitolo() const;
		bool operator ==(Libro);//2 libri uguali se hanno stesso titolo
	private:
		string titolo;
};
#endif // _LIBRO_H
