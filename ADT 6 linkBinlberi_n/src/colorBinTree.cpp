/*
 * testBinAlberi.cpp
 *
 *  Created on: 20 nov 2018
 *      Author: utente
 */

#include "linkBinAlberi.h"
#include "stack.h"
#include <cstdlib>
#include <cstring>

template <class I>
int levelRed(LinkBinAlberi<I>&, typename LinkBinAlberi<I>::node);

template <class I>
int greenLeafs(LinkBinAlberi<I>&, typename LinkBinAlberi<I>::node);

int main(int argc , char *argv[])
{
	/*prove di funzionamento BinAlbero
	LinkBinAlberi<int> bin1;

	bin1.insRoot(0);
	bin1.insSx(bin1.root(),1);
	bin1.insDx(bin1.root(),2);
	bin1.insSx(bin1.sx(bin1.root()),3);
	bin1.insDx(bin1.sx(bin1.root()),4);

	bin1.print();
	bin1.erase(bin1.sx(bin1.root()));
	std::cout << bin1;

	std::cout << bin1;

	std::cout << "preVisita:" << std::endl;
	bin1.preVisita(bin1.root());

	std::cout << "postVisita:" << std::endl;
	bin1.postVisita(bin1.root());

	std::cout << "simmetrica:" << std::endl;
	bin1.simmetrica(bin1.root());

	std::cout << "ampiezza:" << std::endl;
	bin1.ampiezza(bin1.root());


	LinkBinAlberi<char> binColori;

	binColori.insRoot('r');//0
	binColori.insSx(binColori.root(),'w');//1
	binColori.insDx(binColori.root(),'g');//1
	binColori.insSx(binColori.sx(binColori.root()), 'r');//2
	binColori.insDx(binColori.sx(binColori.root()), 'g');
	binColori.insSx(binColori.dx(binColori.root()), 'w');
	//binColori.insDx(binColori.dx(binColori.root()), 'r');
	binColori.insSx(binColori.sx(binColori.sx(binColori.root())),'w');
	//binColori.insDx(binColori.sx(binColori.sx(binColori.root())),'g');
	//binColori.insDx(binColori.dx(binColori.dx(binColori.root())),'w');

	std::cout << "GreenLeafs: " << greenLeafs(binColori,binColori.root()) << std::endl;
	std::cout << "LevelRed: " << levelRed(binColori,binColori.root()) << std::endl;
	std::cout << binColori;
	std::cout << "Ampiezza: " << std::endl;
	binColori.ampiezza(binColori.root());
	*/

	LinkBinAlberi<int> binInteri;
	binInteri.insRoot(1);
	binInteri.insSx(binInteri.root(),3);
	binInteri.insDx(binInteri.root(),5);
	binInteri.insSx(binInteri.sx(binInteri.root()), 8);
	binInteri.insDx(binInteri.sx(binInteri.root()), 10);
	//binInteri.insSx(binInteri.dx(binInteri.root()), 12);

	LinkBinAlberi<int> bin1;

	bin1.insRoot(50);
	bin1.insSx(bin1.root(),150);
	bin1.insDx(bin1.root(),200);
	//bin1.insSx(bin1.sx(bin1.root()),250);
	//bin1.insDx(bin1.sx(bin1.root()),300);


	std::cout << "binInteri\n" << binInteri << std::endl;
	std::cout << "bin1\n" << bin1 << std::endl;

	bin1.mutation(bin1.dx(bin1.root()),binInteri.sx(binInteri.root()));
	//bin1.mutation(bin1.root(),binInteri.root());

	std::cout << "binInteri\n" << binInteri << std::endl;
	std::cout << "bin1\n" << bin1 << std::endl;

	//std::cout << "Albero interi:" << std::endl << binInteri;

	//binInteri.cancFogliaPari(binInteri.root());

	//std::cout << "Albero interi:" << std::endl << binInteri;
	//binInteri.printWithNumNode(binInteri.root());

	char espressione[] = "(1 + 2)";
	int n = strlen(espressione);
	Stack<char> espr;
	Coda<char> post;

	for (int i=0;i<n;i++)
	{
		if(espressione[i] >= '0' && espressione[i] <= '9')
		{
			post.inCoda( espressione[i]);
		}

		if(espressione[i] == '+' || espressione[i] == '*')
			espr.inPila(espressione[i]);

		if(espressione[i] == ')')
		{
			post.inCoda(espr.leggiPila());
		}
	}


	system("pause");
	return 0;
}

template <class I>
int levelRed(LinkBinAlberi<I> &L, typename LinkBinAlberi<I>::node n)
{
	int countLevelRed = 0;
	Coda<typename LinkBinAlberi<I>::node> temp;

	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		typename LinkBinAlberi<I>::node p = temp.leggiCoda();
		temp.fuoriCoda();
		if(L.getlevel(p) %2 == 0)
		{
			if(L.read(p) == 'r' && (L.read(L.sx(p)) == 'w' || (L.read(L.dx(p))) == 'w'))
				countLevelRed++;
		}
		if(!L.sxEmpty(p))
			temp.inCoda(L.sx(p));
		if(!L.dxEmpty(p))
			temp.inCoda(L.dx(p));
	}
	return countLevelRed;
}

template <class I>
int greenLeafs(LinkBinAlberi<I> &L, typename LinkBinAlberi<I>::node n)
{
	int countGreenLeafs = 0;

	if(L.leaf(n) && L.read(n) == 'g')
		countGreenLeafs++;
	else
	{
		countGreenLeafs = 0;
		if(!L.sxEmpty(n))
			countGreenLeafs += greenLeafs(L,L.sx(n));
		if(!L.dxEmpty(n))
			countGreenLeafs += greenLeafs(L,L.dx(n));
	}

	return countGreenLeafs;
}
