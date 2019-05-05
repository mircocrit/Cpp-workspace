#include "pilavt.h"
#include "MultipleStack.h"
#include <iostream>
#include <string>

using namespace std;
#define num 20

int main(){
	string array[10]={"0","1","2","3","4","5","6","7","8","9"};
	string s[10]={"Anna","Dafne","Giovanni","Giulia","Luca","Mirco","Nicola","Ninny","Raffaele","Ruggiero"};
	int i=0;
	MultipleStack<string> M(2);
	for(i=0;i<10;i++)
		M.Push(array[i],0);

	for(i=0;i<10;i++)
		M.Push(s[i],1);

	while(M.get_length(0)!=0){
		cout<<M.read(0)<<endl;
		M.Pop(0);
	}

	while(M.get_length(1)!=0){
		cout<<M.read(1)<<endl;
		M.Pop(1);
	}
	system("pause");
	return 0;

}
