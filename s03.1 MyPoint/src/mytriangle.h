/*
*Realizzare in C++ e testare in un main la struttura dati MyTriangle
class MyCircle{
public:
	MyTriangle(MyPoint, MyPoint, MyPoint);
	string toString(); // visualizza le informazioni sul triangolo tipo "MyTriangle(v1=(x,y),v2=(x,y),v3=(x,y))"
	double getArea();
	double getPerimeter();
	string getType(); // restituisce "Equilatero", "Isoscele" o "Scaleno"
private:
	MyPoint v1;
	MyPoint v2;
	MyPoint v3;
};
*/

#ifndef MYTRIANGLE_H
#define MYTRIANGLE_H

#include "mypoint.h"
#include <string>
#include <cmath>

using namespace std;

class MyTriangle {
  public:
    MyTriangle(MyPoint iv1, MyPoint iv2, MyPoint iv3 ) : v1(iv1), v2(iv2), v3(iv3) {};		//costruttore
    string toString(); 		// visualizza le informazioni sul triangolo tipo "MyTriangle(v1=(x,y),v2=(x,y),v3=(x,y))"
    double getArea(); 				//calcolo dell'area con il metodo del determinante
    double getPerimeter() ;
    string getType();  				// restituisce "Equilatero", "Isoscele" o "Scaleno"
  private:
    MyPoint v1;
    MyPoint v2;
    MyPoint v3;
};

string MyTriangle::toString(){
	return "MyTriangle(v1="+v1.toString()+",v2="+v2.toString()+",v3="+v3.toString()+")";}
double MyTriangle::getArea(){
	return 0.5*abs(v1.getX()*v2.getY()+v1.getY()*v3.getX()+v2.getX()*v3.getY()-v3.getX()*v2.getY()-v3.getY()*v1.getX()-v2.getX()*v1.getY());
}
double MyTriangle::getPerimeter(){		 return v1.distance(v2)+v2.distance(v3)+v3.distance(v1); };//chiamo il metdoo distance di point

string MyTriangle::getType(){
    int d1=v1.distance(v2);	//calcolo le 3 distanze
    int d2=v2.distance(v3);
    int d3=v3.distance(v1);
    if (d1==d2 && d2==d3) {	//se sono tutte uguali
      return "Equilatero";
    } else if (d1==d2 || d2==d3 || d1==d3) {		//una coppia uguale
      return "Isoscele";
    } else return "Scaleno";
  };

#endif
