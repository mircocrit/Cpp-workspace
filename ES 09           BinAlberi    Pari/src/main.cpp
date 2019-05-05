#include "Bin_treec.h"
#include <iostream>
#include "funzioni.h"

using namespace std;

int main(){
	Bin_treec<int> T;
	typename Bin_treec<int>::Nodo n1=0, n2, n3 , n4;
	//inserimento
	T.create();

	T.ins_root(n1);
	T.write(n1,1);

	n2 = T.root();
	T.ins_sx(n2);
	T.ins_dx(n2);
	T.write(T.sx(n1),2);
	T.write(T.dx(n1), 3);

	n3=T.dx(n2);
	T.ins_sx(n3);
	T.ins_dx(n3);
	T.write(T.sx(n3), 4);
	T.write(T.dx(n3), 5);

	n4=T.sx(n2);
	T.ins_sx(n4);
	T.ins_dx(n4);
	T.write(T.sx(n4), 6);
	T.write(T.dx(n4), 7);

	//cout << T;
	cout<<endl<<endl;
	visitaSimmetrica(T,T.root());
	cout<<endl<<endl;
	visitaAmpiezza(T,T.root());
	system("pause");
	return 0;
}
/*
void inserimento(LinkAlberi<int> &L)
{

	srand(time(NULL));

	L.insRoot(rand()%10);

	Coda<LinkAlberi<int>::node> tmp;
	tmp.inCoda(L.root());
	bool terminaInserimento = false;

	while(!tmp.codaVuota() && terminaInserimento == false )
	{
		int numFigli = rand()% 4;
		LinkAlberi<int>::node p = tmp.leggiCoda();
		tmp.fuoriCoda();

		L.insFirst(p,rand()%10);
		for(int i=0;i<numFigli-1;i++)
			L.insFirst(p,rand()%10);

		terminaInserimento = false;

		p = L.firstChild(p);
		while(!L.lastSibling(p))
		{
			tmp.inCoda(p);
			p = L.nextSibling(p);
		}

	}

}
*/

