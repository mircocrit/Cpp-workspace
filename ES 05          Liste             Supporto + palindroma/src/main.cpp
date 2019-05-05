
#include "linked_list.h"
#include "funzioni.h"
#include <iostream>

using namespace std;

void inserimento(Linked_list<string> &);

int main(){
  Linked_list<string> list,list2,list3;
  string value="";
  int flag=0,scelta=0,exit=0;

  inserimento(list);
  cout << list;

  inserimento(list2);
  cout <<list2;

  do{
	 cout<<"0) Esci"<<endl;
	 cout<<"1) Inversione"<<endl;
	 cout<<"2) Palindroma"<<endl;
	 cout<<"3) Inserimento ordinato"<<endl;
	 cout<<"4) Ricerca binaria:"<<endl;
	 cout<<"5) Merge"<<endl;
	 cout<<"6) Insertion"<<endl;
	 cout<<"Scelta		";
	 cin>>scelta;
     switch(scelta){
	  case 0:
		  exit=1;
		  break;

	  case 1:
		  inverti_valori(list);
		  cout << list;
		  Insertion_sort(list);
		  cout << list;
		  break;
	  case 2:
		  cout<<palindroma(list)<<endl;
		  break;

	  case 3:
		  do{
			  cout << list;
			  cout<<"Valore stringa:"<<endl;
			  cin>>value;
			  Insertion_sort(list);
			  insert_ordered(list,value);
			  cout << list;
			  cout<<"Ripetere? 1=y 0=n"<<endl;
			  cin>>flag;
		  }while(flag==1);
		  break;

	  case 4:
		  cout<<"Nome da cercare:	";
		  cin>>value;
		  cout<<list.read(ricerca_binaria(list,value))<<endl;
		  //cout<<position_c(list,q)<<endl;
		  break;

	  case 5:
		  merge(list,list2,list3);
		  Insertion_sort(list3);
		  cout<<list3;
		  break;
	  case 6:
		  Insertion_sort(list);
		  cout << list;
		  break;
     }


    }while(scelta>=0 && scelta<7 && flag==0);

  system("pause");
  return 0;

}


void inserimento(Linked_list<string> &L)
{
	Linked_list<string>::position p = L.begin();
	string d[15]={"Anna","Dafne","Francesca","Giorgia","Giovanni","Giulia","Luca","Maria","Martina","Mirco","Nicola","Ninny","Raffaele","Ruggiero","Teresa"};
	for(int i=0;i<5;i++)
	{
	 L.insert(d[rand()%15],p);
	 p = L.next(p);
	}
}
