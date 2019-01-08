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
string Activity::getName() {
	return this->_name;
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