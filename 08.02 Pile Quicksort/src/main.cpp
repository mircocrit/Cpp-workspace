#include <iostream>
#include <string>
#include <cstring>
#include "pilavt.h"

using namespace std;

int main(){
	Pila<int> inf(10);
	int arr[]={2,6,3,5,2,3,42,12};		//8
	inf.quickSort(arr,8);
	for(int i=0;i<8;i++)
		cout<<arr[i]<<endl;

	system("pause");
	return 0;
}
