#include "Room.h"

//Constructors and destructors
Room::Room(string name) {
	this->_name = name;
}
Room::~Room() {}

//Getters and Setters
string Room::getName() {
	return this->_name;
}

ostream& operator <<(ostream& out, const Room& src) {
	out << src._name << endl;
	return out;
}