#include "linked_list.h"
#include <iostream>
#include <string>
#include "funzioni.h"
using namespace std;

int main(){
  Linked_list<int> list,list2;
  int scelta=0,exit=0;
  string value="";
  //int temp=0;
  do{
	 cout<<"0) Esci"<<endl;
	 cout<<"1) Acquisizione"<<endl;
	 cout<<"2) Visual valore"<<endl;
	 cout<<"3) Somma"<<endl;
	 cout<<"Scelta		";
	 cin>>scelta;
     switch(scelta){
	  case 0:
		  exit=1;
		  break;

	  case 1:
		  cout<<"Valore intero:"<<endl;
		  cin>>value;
		  insert_integer(list,value);
		  cout<<list;
		  break;
	  case 2:
		  cout<<print_integer(list)<<endl;
		  break;

	  case 3:
		  cout<<"Valore intero:"<<endl;
		  cin>>value;
		  insert_integer(list2,value);
		  cout<<"Somma:"<<print_integer(list2)+print_integer(list)<<endl;
		  break;

     }

    }while(scelta>=0 && scelta<3 && exit==0);

  system("pause");
  return 0;

}
