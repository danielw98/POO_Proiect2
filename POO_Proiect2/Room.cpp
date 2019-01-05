#include "Room.h"

Room::Room(string name) {
	this->_name = name;
}
Room::~Room() {}

string Room::getName() {
	return this->_name;
}