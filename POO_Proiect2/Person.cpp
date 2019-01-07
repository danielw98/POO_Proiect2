#include <iostream>
#include "Person.h"

Person::Person(string name, string role) {
	this->_name = name;
	this->_role = role;
}

Person::Person(string name, string cnp, string role) {
	this->_name = name;
	this->_cnp = cnp;
	this->_role = role;
}

Person::~Person() {
	//Not much to do here. C++ ftw
}

//Getter and setter
string Person::getName() {
	return this->_name;
}
string Person::getCNP() {
	return this->_cnp;
}
string Person::getRole() {
	return this->_role;
}

ostream& operator <<(ostream& out, const Person& src) {
	out << "Name: " << src._name << endl;
	
	out << "CNP: ";
	if (!(src._cnp.empty()))
		out << src._cnp;
	out << endl;

	out << "Role: " << src._role << endl;;
	
	return out;
}