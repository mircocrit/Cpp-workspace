#ifndef _STUDENT
#define _STUDENT

#include <string>
using namespace std;

class Student {
	public:
		Student(int id);
		Student(string name, string surname, int id, int age);
		void setName(string name);
		void setSurname(string surname);
		void setId(int id);
		void setAge(int age);
		string getName();
		string getSurname();
		int getId();
		int getAge();
		void print();
	private:
		string name;
		string surname;
		int id;
		int age;
};

#endif /* _STUDENT */
