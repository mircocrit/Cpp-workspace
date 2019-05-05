#include "dequeue.h"
#include <iostream>
#include <string>

using namespace std;
#define num 20

int main(){
	Dequeue<int> queue1;
	int x;
	x = 1;
	queue1.insert_head(x);//inserimento in testa
	x = 2;
	queue1.insert_head(x);
	x = 3;
	queue1.insert_head(x);
	x = 4;
	queue1.insert_head(x);
	cout << "queue=" << queue1<<endl;
	queue1.erase_head();
	queue1.erase_head();
	queue1.erase_head();
	queue1.erase_head();
	cout << "queue=" << queue1<<endl;

	x = 1;
	queue1.insert_tail(x);
	x = 2;
	queue1.insert_tail(x);
	x = 3;
	queue1.insert_tail(x);
	x = 4;
	queue1.insert_tail(x);
	cout << "queue=" << queue1<<endl;
	queue1.erase_tail();
	queue1.erase_tail();
	queue1.erase_tail();
	queue1.erase_tail();
	cout << "queue=" << queue1<<endl;

    system("pause");
    return 0;

}
