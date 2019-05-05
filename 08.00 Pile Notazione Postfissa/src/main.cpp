#include <iostream>
#include <string>
#include <cstring>
#include "pilavt.h"

using namespace std;

int main(){
	string a ="1 7 3 / 1 4 - 2 * / +";	//		//5 10 2 * +
	Pila<int> postf(a.length());
	cout<<postf.Postfissa(a)<<endl;
	postf.stampaPila();
	system("pause");
	return 0;
}
