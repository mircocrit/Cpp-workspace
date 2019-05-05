#include "class_template_matrice.h"

int main(int argc, char *argv[]){
	Matrice<int> a(4,4) , b(4,4);

	a.random();
	a.output_matrice();
	std::cout << std::endl;

	b.random();
	b.output_matrice();
	std::cout << std::endl;
	b.trasposta();
	b.output_matrice();

	system("pause");
	return 0;
}
