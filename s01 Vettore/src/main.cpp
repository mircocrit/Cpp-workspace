/*Scrivere in C/C++ in un file array.c l'implementazione delle seguenti funzioni che operano su array di elementi di tipo integer.
1) greaterThan:
    ha in input un array A ed un intero k				restituisce il numero di elementi di A che sono maggiori di k;
2) member:
    ha in input un array A ed un intero k					restituisce true se k è presente in A;
3) largest:
	ha in input un array A					restutuisce il valore del più grande elemento presente in A e la sua posizione;
4) remove:
 	 ha in input un array A ed un intero k		elimina la prima occorrenza di k in A facendo uno shift a sinistra di tutti gli elementi che seguono k e scrivendo zero alla fine dell'array;
5) ordering:
 	 ha in input un array A			stabilisce se gli elementi in A sono in ordine crescente, descrescente o costante;
6) reverse:
	 ha in input un array A					lo modifca invertendone gli elementi.*/

#include "vect.h"

using namespace std;

int main(){
	vector <int> arr= {1,3,1,2,4,6,7,4,3,2,2,3,1,3,40},temp;
	int scelta;
	vector<int>::iterator it;

	do{
		cout<< "0 - Esci"<<endl;
		cout<< "1 - Numero elementi piu grandi di k"<<endl;
		cout<< "2 - Elemento presente nell'array?"<<endl;
		cout<< "3 - Valore piu grande elemento dell'array e la sua posizione"<<endl;
		cout<< "4 - Eliminazione e shift"<<endl;
		cout<< "5 - Elementi in ordine crescente decrescente o costante"<<endl;
		cout<< "6 - Inversione elementi"<<endl;
		cout<< "7 - Stampa"<<endl;

		cout<< "Scelta:";
		cin>>scelta;

	   switch(scelta){

	   case 0:
		   break;

		case 1:
			cout<<greatherThan(arr,3)<<endl;
			break;

		case 2:
			member(arr,40);
			break;

		case 3:
			cout<<largest(arr)<<endl;
			break;
		case 4:
			remove(arr,3);
			print_array(arr);
			break;

		case 5:
			temp= ordering(arr);
			if(temp==arr)
				cout<<"Ordinamento crescente"<<endl;
			else{
				cout<<"Ordinamento non crescente"<<endl;
			}
			break;

		case 6:
			invert(arr);
			print_array(arr);
			break;

		case 7:
			print_array(arr);
			break;
	  }
	}while(scelta>=0 && scelta <8);

    system("pause");
    return 0;
}

