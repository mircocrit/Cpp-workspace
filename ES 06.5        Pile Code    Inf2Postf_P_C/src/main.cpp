#include <iostream>
#include <string>
#include <cstring>
#include "linked_list.h"
#include "funzioni.h"

using namespace std;

int main(){
	char *a = "3+7*(4-9)-7";
	Linked_list<char> list;
	Linked_list<char>::position p=list.begin();
	for(int i=0;i<strlen(a);i++){
	  	  list.insert(a[i], p);
	   }
	cout << list;

	Pila<char> stack(30);
	Coda<char> queue(30);
	Coda<char> result(30);

	result=converti(list,stack,queue);

	while(!result.codaVuota()){
		cout<<" "<<result.leggiCoda();
		result.fuoriCoda();
	}
	cout<<endl;

	system("pause");
	return 0;
}

