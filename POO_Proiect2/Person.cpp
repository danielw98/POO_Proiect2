#include <iostream>
#include <algorithm>
#include "Person.h"
#include "DidacticActivity.h"

//Constructors and destructors
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
string Person::getRole() const{
	return this->_role;
}

//Attending functions
void Person::attendActivity(Activity* activity) {
	this->_activities.push_back(activity);
}
void Person::stopAttendingActivity(Activity* activity) {
	_activities.erase(std::remove(_activities.begin(), _activities.end(), activity), _activities.end());
}
void Person::listAttendingActivities() {
	unsigned int size = _activities.size();
	for (unsigned int i = 0; i < size; i++) {
		DidacticActivity* dCheck = dynamic_cast<DidacticActivity*>(_activities[i]);
		if (dCheck != NULL) {  //Este didactic activity
			cout << *dCheck << endl;
			continue;
		}

		cout << *_activities[i] << endl;
	}
}

ostream& operator <<(ostream& out, const Person& src) {
	out << "Name: " << src._name << endl;
	
	out << "CNP: ";
	if (!(src._cnp.empty()))
		out << src._cnp;
	out << endl;

	out << "Role: " << src._role << endl;
	out << "Participating Activities: ";
	if (!(src._activities.empty())) {
		unsigned int size = src._activities.size();
		out << src._activities[0]->getName();
		for (unsigned int i = 1; i < size; i++) {
			out << ", " << src._activities[i]->getName();
		}
	}

	out << endl;
	return out;
}