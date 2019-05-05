/*
 * test.cpp
 *
 *  Created on: 07 gen 2019
 *      Author: utente
 */
#include "Bins.h"
#include <ctime>


void inserimento(Bins &);

int main(int argc , char *argv[])
{
	Bins b;
	inserimento(b);
	std::cout<<b.mean(0)<<std::endl;
	std::cout<<b.mean(1)<<std::endl;
	std::cout<<b.mean(2)<<std::endl;
	getchar();
	std::cout<<b.freq(0)<<std::endl;
	std::cout<<b.freq(1)<<std::endl;
	std::cout<<b.freq(2)<<std::endl;
	getchar();
	getchar();
	b.deleteElem(2);
	std::cout<<b.freq(2)<<std::endl;
	getchar();

	/*
	Coda<int> C;
	C.inCoda(4);
	C.inCoda(5);
	C.inCoda(2);

	C.inCoda(3);
	C.inCoda(6);
	C.inCoda(5);
	C.inCoda(8);

	std::cout<<C<<std::endl;
	*/
	getchar();
	return 0;
}


void inserimento(Bins &B){
	srand(time(NULL));

	int n = 30;

	for(int i=0;i<n;i++)
	{
		B.insert(rand()%9+1);
	}
}
