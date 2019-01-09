#include <algorithm>
#include "Activity.h"

//Constructors and destructors
Activity::Activity(string name, string details, Room* room, Person* person) {
	this->_name = name;
	this->_details = details;
	this->_room = room;
	this->_organizer = person;
}
Activity::~Activity() {
	//We don't need to clean anything, because:
	//We only use the room, not create it
	//We only have an organizer, not create one
	//We only have attendees, not create them
}

//Getters and Setters
string Activity::getName() const{
	return this->_name;
}
const Person* Activity::getOrganizer() const {
	return this->_organizer;
}

//Attending functions
void Activity::addPersonToAttendes(Person* person) {
	_attendees.push_back(person);
}
void Activity::delPersonFromAttendes(Person* person) {
	_attendees.erase(std::remove(_attendees.begin(), _attendees.end(), person), _attendees.end());
}

ostream& operator <<(ostream& out, const Activity& src) {
	out << "___________ Activity ___________" << endl;
	out << "Name: " << src._name << endl;
	out << "   _____ Organizer _____   " << endl;
	out << *(src._organizer);
	out << "Room: " << *(src._room);
	out << "Details:";
	if (!(src._details.empty()))
		out << src._details;
	out << endl;

	return out;
}