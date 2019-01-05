#include <iostream>
#include "Person.h"

Person::Person(string name, Role role) {
	this->_name = name;
	this->_role = role;
}

Person::Person(string name, string cnp, Role role) {
	this->_name = name;
	this->_cnp = cnp;
	this->_role = role;
}

Person::~Person() {
	//Not much to do here. C++ ftw
}