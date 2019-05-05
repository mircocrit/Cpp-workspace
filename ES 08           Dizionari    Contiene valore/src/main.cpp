#include "hash_table.h"
#include <iostream>
#include <string>
#include <time.h>
#include "funzioni.h"

using namespace std;

int main(){

	string str_vec[10]={"Anna","Dafne","Giova","Giulia","Luca","Mirco","Nicola","Ninny","Raffa","Raffa"};
	int dim=10;
    HashTable<string,string> hashtable(10);
    HashTable<string,string> hashtable2(20);

   // cout<<  hashtable.empty()<<endl;

    for(int i=0;i<dim;i++){
    	struct Entry<string,string> e;
    	const string chiave = to_string((i+3+19)*223);	//genero chiave

		e.first=chiave;				//temp
		e.second=str_vec[i];	//vector mette in valori in valore
    	hashtable.insert(e);
    }

    values(hashtable);
    cout<<endl;

    keys(hashtable);

    string temp="Raffa";

    cout<<containsValue(hashtable,temp)<<endl;

    //hashtable2=resize(hashtable2);
    //values(hashtable);





/*
	int str_vec2[6]={3,5,6,7,1,8};
	int dim=6;
    HashTable<int,string> hashtable2(6);
    for(int i=0;i<dim;i++){
    	struct Entry<int,string> e;
		e.first=str_vec2[i];				//temp
		e.second="";
    	hashtable2.insert(e);
    }

    cout<<endl;
    print(hashtable2);

    int str_vec3[4]={7,8,1,6};
	int dim3=4;
    HashTable<int,string> hashtable3(4);

    for(int i=0;i<dim3;i++){
    	struct Entry<int,string> e2;
		e2.first=str_vec3[i];				//temp
		e2.second="";
    	hashtable3.insert(e2);
    }

    cout<<endl;
    print(hashtable3);
   // cout<<compare(hashtable2,hashtable3)<<endl;
    cout<<subset(hashtable3,hashtable2)<<endl;	//stabilisce se la tabella hash 1 e' sottoins di 2: 1<2

    cout<<endl;

    */
    system("pause");
    return 0;
}

