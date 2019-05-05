/*
 * test.cpp
 *
 *  Created on: 28 dic 2018
 *      Author: utente
 */
#include "linkAlberi.h"
#include "funzAuxAlberi.h"

int main(int argc , char *argv[])
{
		LinkAlberi<char> tree , tree1;
		LinkAlberi<char>::node iter;

		tree1.insRoot('a');
		tree1.insFirst(tree1.root() , 'd');
		tree1.insFirst(tree1.root() , 'c');
		tree1.insFirst(tree1.root() , 'b');
		tree1.insFirst(tree1.firstChild(tree1.root()) , 'f');
		tree1.insFirst(tree1.firstChild(tree1.root()) , 'e');
		tree1.insFirst(tree1.nextSibling(tree1.firstChild(tree1.root())),'h');
		tree1.insFirst(tree1.nextSibling(tree1.firstChild(tree1.root())),'g');
		tree1.insFirst(tree1.nextSibling(tree1.nextSibling(tree1.firstChild(tree1.root()))),'j');
		tree1.insFirst(tree1.nextSibling(tree1.nextSibling(tree1.firstChild(tree1.root()))),'i');
		std::cout << "tree1:" << std::endl;
		std::cout << tree1;
	/*
		tree.insRoot('a');

		tree.insFirst(tree.root(), 'b');
		tree.insFirst(tree.root(), 'c');
		tree.ins(tree.firstChild(tree.root()),'d');


		tree.insFirst(tree.firstChild(tree.root()), 'e');
		tree.insFirst(tree.firstChild(tree.root()), 'f');

		std::cout << "tree:" << std::endl;
		tree.print(tree.root());

		tree.insSubTree(tree.firstChild(tree.root()),tree1);
		std::cout << "dopo insSubTree" << std::endl;
		tree.print(tree.root());


		std::cout << "remove c" << std::endl;
		tree.removeSubTree(tree.firstChild(tree.root()));
	    tree.print(tree.root());

	    std::cout << "Previsita" << std::endl;
	    tree.preVisita(tree.root());

	    std::cout << "Postvisita" << std::endl;
	    tree.postVisita(tree.root());

	    std::cout << "Invisita" << std::endl;
	    tree.invisita(tree.root(),0);
		*/

		std::cout << "Ampiezza tree1" << std::endl;
		tree1.ampiezza(tree1.root());
		std::cout << "profondita tree1 --> " << profondita(tree1,tree1.root()) << std::endl;
		std::cout << "larghezza tree1  --> " << larghezza(tree1,tree1.root()) << std::endl ;
		/*
	    std::cout << "Ampiezza tree" << std::endl;
	    tree.ampiezza(tree.root());
	    std::cout << "profondita tree--> " << tree.profondita(tree.root()) << std::endl;
		*/

	getchar();
	return 0;
}
