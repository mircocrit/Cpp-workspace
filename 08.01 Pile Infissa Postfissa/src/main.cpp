//trasforma infissa in postfissa


#include <iostream>
#include <string>
#include <cstring>
#include "pilavt.h"

using namespace std;

int main(){
	string a = "5 + (1 * 2)";
	Pila<int> inf(a.length());
	inf.Inf2Postf(a);		//5 1 2 * +
	cout << endl;
	system("pause");
	return 0;
}

