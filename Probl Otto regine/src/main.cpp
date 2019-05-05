#include <cstdlib>
#include <iostream>

using namespace std;

bool verifica(int V[], int dim);
bool calcolo_reg(int V[],bool successo,int dim);


int main(){
	bool successo=true;

	int vett[8]={0,0,0,0,0,0,0,0};
	int dim=8;
	for(int i=0;i<dim;i++)
			cout<<vett[i]<<endl;
	cout<<"                 "<<endl<<endl;
	successo=calcolo_reg(vett,successo,dim);
	cout<<successo<<endl<<endl;
	for(int i=0;i<dim;i++)
		cout<<vett[i]<<endl;

    system("pause");
    return 0;
}

bool verifica(int V[], int dim){
	for(int i=0;i<dim;i++){
		for(int j=1;i<dim;j++){
			if(V[i]==V[j])
				return true;
		}
	}
	for(int h=0;h<dim;h++){
		for(int k=1;k<dim;k++){
				if(abs(V[h]-V[k])==abs(h-k))	return true;
		}
	}
	return false;
}


bool calcolo_reg(int V[],bool successo,int dim){
	int k;
	bool b,a;
	k=1;
	V[k]=1;
	successo=false;
	do{
		a=verifica(V,dim);
		if (a==true){
			do{
				if (V[k]<dim){
					b=true;
					V[k]=V[k] +1;
				}
				else{
					b=false;
					k=k-1;
				}
			}while(b==true || k==0);
		}else
			if (k==dim){
				successo=true;
			}
			else{
				k=k+1;
				V[k]=1;
			}
	}while(successo==true || k==0);
	return successo;
}
