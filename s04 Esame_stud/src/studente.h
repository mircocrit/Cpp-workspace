#include "esame.h"
#include <iostream>

using namespace std;

class studente{
 public:
		//COSTRUTTORE
	studente(string name1,string name2,string name3,string name4,string name5){
		esami[0].setEsame(name1);
		esami[1].setEsame(name2);//settera il sostenuto a false
		esami[2].setEsame(name3);
		esami[3].setEsame(name4);
		esami[4].setEsame(name5);
	}
	studente(): studente("Basi","ASD","Fisica","calcolo","Map"){}

	void setMatricola(string m) { 	matricola = m;}
	void setNome(string m){ 		nome = m;}
	string getMatricola() const{ 		return matricola;}
	string getNome() const{ 			return nome;}
	int getTotEsami(){ return this->num_esami;};
	int getNumEsami(){
		int count;
		for(int i=0;i<num_esami;i++)
			if(esami[i].isSostenuto()==true)
				count++;
		return count;
	}

	void setEsame(int vot, int num_esame){		esami[num_esame-1].setVoto(vot);}		//NUMERO ESAME SOSTENUTO: 0 1 2 3 4//VOTO DA AGGIUNGERE
	friend std::ostream & operator << (std::ostream &os,  studente &Stud){
		os << "[ ";
		os << "\t"<< Stud.getMatricola()<< "		";
		os << Stud.getNome() << "  "<<endl;
		os<< "Esami"<<"Voto"<<"Sostenuto";
		for(int i=0;i<5;i++){
			os<< esami[i].getEsame();
			if((esami[i].getVoto())!=-1){
				os<< esami[i].getVoto<<"			";
				os << "Sostenuto"<<endl;
			}
			else
				os<< "Non Sostenuto"<<endl;
		}
		os << " ]"<<endl;
		return os;
}
	int getVotoEsame (int index){	return esami[index].getVoto();};
	string  getNomeEsame (int index)  {	return esami[index].getEsame();}
	int getSostenuto (int index) {	return esami[index].isSostenuto();}
	double getMedia() {
		int c = 0;
		double mean = 0;
		for (int i=0;i<num_esami;i++)
			if (esami[i].isSostenuto()){
				c++;
				mean += esami[i].getVoto();
			}
		return mean/c;
	}

	void print(){
		for (int i=0;i<5;i++)
			if (esami[i].isSostenuto()){
				cout << esami[i].getEsame() << " " << esami[i].getVoto() << endl;
			}
	}

 private:
	const int num_esami=5;
	esame esami[5];
	string matricola;
	string nome;
};




