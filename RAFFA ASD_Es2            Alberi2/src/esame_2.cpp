//esercizio 2 esami ASD 



//implemetare una funzione  che preso in input un albero n-ario di interi, restituisca il livello in cui si ha il numero di nodi massimo

#include<iostream>

#include"..\\esercitazioni\\R_CODE\\Linked_Queue.h"


#include"..\\esercitazioni\\alb_nari\\TreeLink.h"



template<class P>
int	max_level(Std_Tree<int, P> &T){
	
	
	
	//verifica della pre-scondizione
	if(!T.empty()){
		
		//creo una coda ausiliaria che mi tiene il conto del livello e del numero dei nodi presenti nella coda
		Linked_Queue< typename Std_Tree<int,P>::node> level;
		typename Std_Tree<int,P>::node it= T.root();
		
		
		//radice nella coda
		typename Std_Tree<int,P>::node temp=it;
		level.insert(temp);

		int max=0;//variabile da restituire
		int max_l=0;
		int k=0;
		while(!level.empty()){
			int n=level.size_q();
			for(int i=0;i<n;i++)
			{
				it=level.read();//leggo il nodo
				//metto nella coda i figli di it
				if(T.leaf(it)==false){
					it=T.firstChild(it);
					do{
						temp=it;
						level.insert(temp);
						if(!T.lastSibling(it)){
							it=T.nextSibling(it);
						}
					}while(!T.lastSibling(it));
				}
				level.erase();//elimino il nodo analizzato
			}//ho messo i figli dei nodi 
			
			//calcolo il massimo
			if(max<level.size_q())
			{
				max=level.size_q();
				max_l=k;
			}	
			k++;
		}
		return max_l;	
	}
	return -1;//vuol dire che l'albero è vuoto
	
	
}






int main(){
	
	TreeLink<int> paolo;
	paolo.insRoot(10);
	paolo.insFirst(paolo.root(),80);
//	int i;
//	for(i=2;i<6;i++)
//	{
//		paolo.ins(paolo.root(),i);
//	}
//	paolo.print(paolo.root());
	cout<<"risultato livello massimo: "<<max_level(paolo);
	
}





