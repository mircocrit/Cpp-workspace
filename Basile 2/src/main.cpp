#include <iostream>
#include "studente.h"

int main() {
  try {
    Student s=Student(270342);
    s.setName("Pippo");
    std::cout << s.getId() << std::endl;
    s.print();
    Student s1=Student("Mario","Bianchi",260430,21);
    std::cout << s1.getId() << std::endl;
    s1.print();
    Student s2=Student("Giuseppe","Verdi",34,11);
    s2.print();
  } catch (char const* strException) {
    std::cerr << "Exception: " << strException << std::endl;
    system("pause");
    return 1;
  }
  system("pause");
  return 0;
}
