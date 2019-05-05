/*Dizionari

*Esercizio 1
Estendere la classe hash_table aggiungendo i seguenti metodi:

1) containsValue(const E& e): restustuisce true se una o più chiavi sono mappate al valore e nel dizionario ok
2) values(): restituisce la lista dei valori memorizzati nel dizionario		ok
3) keys(): restituisce la lista delle chiavi memorizzate nel dizionario	ok
4) resize(): raddoppia la dimensione interna della tabella.		ok
Esistono due strategie:
a) Creare la nuova tabella,  iterare su tutti gli elementi nella vecchia tabella    reinserirli nella nuova
b) incremental resizing:
creare la nuova tabella e conservarsi la vecchia intatta;
effettuare ogni operazione di ricerca o eliminazione su entrambe le tabelle;
effettuare i nuovi inserimenti solo nella nuova tabella;
al verificarsi di un nuovo inserimento spostare anche k elemeti dalla vecchia tabella alla nuova;
deallocare la vecchia tabella quando diventa vuota.


*Esercizio 2
Dati due insiemi di interi S1 e S2, facendo uso di un dizionario, stabilire se S1 è un sottoinsieme di S2 o se sono esattamente uguali.
*/
/*
 create
 insert
 empty
 size
 find		// ritorna entry(key+chiave) dando una chiave
modify
erase
*/
#ifndef FUNZIONI_H_
#define FUNZIONI_H_

using namespace std;
#include "hash_table.h"


template<class K, class E>			//ricerca valore nel dizionario
bool containsValue(HashTable<K,E> &h, E & value){
  bool flag=false;
  for(int i=0;i< h.size();i++){
	 if ( (h.get_table(i))->get_value()==value){
		 cout<<"Value find at key  "<<(h.get_table(i))->get_key()<<endl;
		 flag= true;
	 	 }
 	 }
 	 return flag;
}

template<class K, class E>			//ricerca valore nel dizionario
void values(HashTable<K,E> &h) {
  std::cout<<"VALUE				"<<"POSITION			"<<std::endl;
  for(int i=0;i< h.size();i++){
		 cout<<(h.get_table(i))->get_value()<<"				"<<	h.search((h.get_table(i))->get_key())<<endl;
	 	 }
}

template<class K, class E>			//ricerca valore nel dizionario
void keys(HashTable<K,E>  &h){
  std::cout<<"KEY				"<<"POSITION			"<<std::endl;
  for(int i=0;i< h.size();i++){
		 cout<<(h.get_table(i))->get_key()<<"				"<<	h.search((h.get_table(i))->get_key())<<endl;
	 	 }
 }

template<class K, class E>			//stampa chiave e  valore
void print(HashTable<K,E>  &h){
  cout<<"KEY				"<<"VALUE			"<<std::endl;
  for(int i=0;i< h.size();i++){
	cout<<(h.get_table(i))->get_key()<<"				"<<	(h.get_table(i))->get_value()<<endl;
	 	 }
 }


//////////////////////////////////////////77777



/*
template<class K, class E>		//stanno nelle chiavi
bool compare(HashTable<K,E> &h1 ,HashTable < int, string> &s ){
  if(h1.size()!= s.size())					return false;
  else{
	  bool found;
	  for(int i=0;i< s.size();i++){								//{3,5,6,7,1,8};
		  found=false;
		  for(int j=0;j< h1.size() && found==false;j++){		//{7,8,3};
			if((	(h1.get_table(j))->get_key() )   ==s)
				found =true;
		  }
		  if (found == false)				return false;
	  }
	  return true;
   }
}
*/
template<class K, class E>		//quella che gli passo , h, e' piu grande
bool subset(HashTable<K,E>  &h1 ,HashTable < K, E> &h ){
	  bool found;
	  for(int i=0;i< h.size();i++){									//{7,8,1,5,6};
		  found=false;
		  for(int j=0;j< h1.size();j++){				//{3,5,6,7,1,8}
			if((h1.get_table(j))->get_key()==(h.get_table(i))->get_key()){
				found =true;
				cout<<"trovato"<<endl;
			}
		  }
		  if (found == false)
			  return false;
	  }
	  return true;

}

/*
template<class K, class E>
HashTable<K,E> HashTable<K,E>::resize(){
	 HashTable<K,E> tab(divisor*2);
	 for(int i=0;i<dsize;i++){
		 tab.table[i]->first=		this->table->first;
		 tab.table[i]->second=		this->table->second;
	 }
	 return tab;
}
*/

#endif /* FUNZIONI_H_ */
