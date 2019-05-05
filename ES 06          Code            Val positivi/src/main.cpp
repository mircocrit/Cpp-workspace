#include "coda.h"
#include <iostream>
#include <string>
#include "funzioni.h"

using namespace std;
#define num 10

int main(){

	int scelta,exit=0;
	Coda<int> queue;
	Coda<int> pari;

    do{
	 cout<<"0) Esci"<<endl;
	 cout<<"1) Acquisizione"<<endl;
	 cout<<"2) Visualizzazione"<<endl;
	 cout<<"3) Pari"<<endl;
	 cout<<"Scelta		";
	 cin>>scelta;
     switch(scelta){
	  case 0:
		  exit=1;
		  break;

	  case 1:
		    for(int i=0;i<num;i++){	//0 1 2 3 4 5 6  7 8
		    	 queue.inCoda(i);
		      }
		  break;
	  case 2:
		 while(!queue.codaVuota()){
			cout<<" "<<queue.leggiCoda();
			queue.fuoriCoda();
		   }
		  cout<<endl;
		  break;

	  case 3:
		  estrai_pari(queue,pari);		//0 2 4 6 8

		  while(!pari.codaVuota()){
			  cout<<" "<<pari.leggiCoda();
			  pari.fuoriCoda();
		   }
		  cout<<endl;

		  break;

     }

    }while(scelta>=0 && scelta<4 && exit==0);

  system("pause");
  return 0;

}
