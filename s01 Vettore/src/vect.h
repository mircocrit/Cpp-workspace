#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_array(const vector<int>&);
int greatherThan(const vector<int>&,int);
void member(const vector<int>&,int value);
int largest(const vector<int> &);
void remove(vector<int>&,int);
vector<int> ordering (vector<int>, bool fun(int,int));
bool cresc(int,int);
bool decresc(int,int);
void invert(vector<int>&);

void print_array(const vector<int> &v){
    for (unsigned int i=0; i<v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;
}

int greatherThan(const vector<int> &v,int value){
	int count=0;
	for (unsigned int i=0; i<v.size(); i++)
		if(v.at(i)>value)		count++;
	return count;
}


void member(const vector<int> &v,int value){
	//auto value2=std::find(v.begin(), v.end(), value);
	if ((std::find(v.begin(), v.end(), value)) != v.end())
	    std::cout << "Elemento trovato in posizioine: " << std::distance(v.begin(), (std::find(v.begin(), v.end(), value))) << '\n';
	  else
	    std::cout << "Elemento non trovato\n";
}


int largest(const vector<int> &v){
	int result = *max_element(v.begin(), v.end());
	std::cout<< distance(v.begin(), (std::find(v.begin(), v.end(), result)))<<endl;
	return result;
}

void remove(vector<int> &v,int value){
	v.erase(std::find(v.begin(), v.end(), value));
	v.push_back(0);
}

vector<int> ordering (const vector<int> v){
	vector<int> v1=v;
	std::sort (v1.begin(), v1.end());
	return v1;
}

bool cresc(int i, int j) { return i < j; }
bool decresc(int i, int j) { return i < j; }

void invert( vector<int> &v){
	std::reverse(v.begin(), v.end());
}

