/*Lab 3.1
*Realizzare in C++ e testare in un main la struttura dati MyPoint
class MyPoint {
public:
	MyPoint();
	MyPoint(int, int);
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	double distance(MyPoint); // restituisce la distanza con un altro punto
	string toString(); // visualizza le coordinate del punto del tipo "MyPoint(x,y)"
private:
	double x;
	double y;
};*/

#ifndef MYPOINT_H
#define MYPOINT_H

#include <string>
#include <cmath>

using namespace std;
//CLASSE PUNTO

class MyPoint {
  public:
    MyPoint() {	 MyPoint(0,0); };
    MyPoint(int ix, int iy) { 	x=ix; y=iy; };
    int getX() { 	return x; };
    int getY() { 	return y; };
    void setX(int c) { 		x=c; };
    void setY(int c) { 		y=c; };
    double distance(MyPoint p) { 		return sqrt(pow(p.x-x,2)+pow(p.y-y,2)); } // restituisce la distanza con un altro punto
    string toString() { 	return ""+to_string(x)+","+to_string(y)+")"; } ; // visualizza le coordinate del punto del tipo "MyPoint(x,y)"
  private:
    double x;
    double y;
};

#endif
