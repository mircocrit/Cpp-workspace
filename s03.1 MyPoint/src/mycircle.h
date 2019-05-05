/*
*Realizzare in C++ e testare in un main la struttura dati MyCircle
class MyCircle{
public:
	MyCircle();
	MyCircle(MyPoint, double);
	double getRadius();
	void setRadius(double);
	MyPoint getCenter();
	void setCenter(MyPoint);
	string toString(); // visualizza le informazioni sul cerchio tipo "MyCircle(radius=r,center=(x,y))"
	double getArea();
	double getCircumference();
	double distance(MyCircle); // restituisce la distanza dal centro al centro di un altro cerchio
private:
	MyPoint center;
	double radius;
};*/

#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "mypoint.h"
#include <string>
#include <cmath>


using namespace std;

class MyCircle{
  public:
    MyCircle() 	{			center=MyPoint(); 		radius=0; };
    MyCircle(MyPoint c, double r) { 		center=c; 		radius=r; };
    double getRadius() {	 return radius; };
    void setRadius(double r) { 		radius=r; };
    MyPoint getCenter() { 		return center; };
    void setCenter(MyPoint c) { 		center=c; };
    string toString() { return "MyCircle(radius="+to_string(radius)+",center="+center.toString()+")"; }; // visualizza le informazioni sul cerchio tipo "MyCircle(radius=r,center=(x,y))"
    double getArea() { 		return 3.14*pow(radius,2); } ;
    double getCircumference() { 		return 2*radius*3.14; };
    double distance(MyCircle c) { 		return c.getCenter().distance(center); } ; // restituisce la distanza dal centro al centro di un altro cerchio
  private:

    MyPoint center;
    double radius;
};

#endif
