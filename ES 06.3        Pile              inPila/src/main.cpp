#include "pilavt.h"
#include <iostream>
#include <string>

#include "Pila_dup.h"

using namespace std;

int main(){

	int array[10]={0,1,2,2,4,5,1,7,3,5};
	int i=0,value;
	Pila_dup<int> p;

	for(i=0;i<10;i++){
		p.inPilaD(p,array[i]);
	}
	cout<<"Elemento:";
	cin>>value;
	p.inPilaD(p,value);

	while(!p.pilaVuota()){
		cout<<p.leggiPila()<<endl;
		p.fuoriPila();
	}

    system("pause");
    return 0;

}
