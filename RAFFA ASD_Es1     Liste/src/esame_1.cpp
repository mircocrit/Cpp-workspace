//esercizio 1 esami ASD



#include "linear_list.h"
#include <map>
#include <cstdlib>
#include "linked_list.h"

using namespace std;



template<class P>
int freq(Linear_list<int,P> &L, int mult){
	
	int res=0;
	if(!L.empty()){
		typename Linear_list<int,P>::position it=L.begin();
		while(!L.end(it)){
			if(L.read(it)%mult==0)	res++;
			it=L.next(it);
		}
	}
	else
	{
		//lista vuota -> impossibile eseguire il metodo. Verrà restituito un valore speciale
		res=-1;
	}
	return res;
}


template<class P>
void hist(Linear_list<int,P> &L){
	if(!L.empty()){
		map<int, int> freq;
		typename Linear_list<int,P>::position it= L.begin();
		while(!L.end(it)){
			freq[L.read(it)]++;
			it=L.next(it);
		}
		//stampa degli elementi e delle frequenze
		cout<<"La lista contiene: "<<endl;
		for(map<int,int>::iterator i=freq.begin();i!=freq.end();++i){
			cout<<i->first<<"=>"<<i->second<<endl;
		}
	}
	else	cout<<"La lista e' vuota!";
}


template<class P>
void remp(Linear_list<int,P> &l){
	if(!l.empty()){
		//itero sulla lista
		typename Linear_list<int,P>::position it=l.begin();
		while(!l.end(it)){
			if((l.read(it)%2)==1 && it!=l.begin()){
				l.erase(l.previous(it));
			}
			it=l.next(it);
		}
	}
}


int main(){
	Linked_list<int> pippo;
	for(int i=0;i<10;i++){
		pippo.insert(i,pippo.begin());
	}
	
	
	//cout<<"I numeri pari sono "<<freq(pippo,2)<<endl;
	//hist(pippo);
	
	
	cout<<"Pre-Pippo: "<<endl<<pippo;
	remp(pippo);
	cout<<"Post-Pippo: "<<endl<<pippo;
}

