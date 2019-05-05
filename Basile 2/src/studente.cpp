#include "studente.h"
#include <iostream>


const int MIN_ID=255312;
const int MAX_ID=499999;

const int MIN_AGE=12;
const int MAX_AGE=105;

Student::Student(int id) {
  setId(id);
  Student::name="";
  Student::surname="";
  Student::age=-1;
}

Student::Student(string name, string surname, int id, int age) {
  setName(name);
  setSurname(surname);
  setId(id);
  setAge(age);
}

void Student::setName(string name) {
  if (name.length()<31)
    Student::name=name;
  else
    throw "No valid name";
}

void Student::setSurname(string surname) {
  if (surname.length()<31)
    Student::surname=surname;
  else
    throw "No valid surname";
}

void Student::setId(int id) {
  if (id>=MIN_ID && id<=MAX_ID)
    Student::id=id;
  else throw "No valid id";
}

void Student::setAge(int age) {
  if (age>=MIN_AGE && age<=MAX_AGE)
    Student::age=age;
  else throw "No valid age";
}

string Student::getName() {
  return name;
}

string Student::getSurname() {
  return surname;
}

int Student::getId() {
  return id;
}

int Student::getAge() {
  return age;
}

void Student::print() {
  std::cout << "Name: " << getName() << " Surname: " << getSurname() << " Id: " << getId() << " Age: " << getAge() << std::endl;
}
