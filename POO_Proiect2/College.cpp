#include "College.h"

College::College() {};
College::~College() {};

void College::addRoom(string name)
{
	_rooms.push_back(new Room(name));

	cout << "Succes room addition" << endl;
}
void College::delRoom(string name)
{
	for (int i = 0; i < _rooms.size(); i++)
		if (_rooms[i]->getName() ==  name)
		{
			delete _rooms[i]; //Free pointer before removing
			_rooms.erase(_rooms.begin() + i);
			i--;
			//_rooms[i] = _rooms.back();
			//_rooms.pop_back();
		}

	cout << "Succes room deletion" << endl;
}
void College::listRooms()
{
	cout << "Rooms: \n";
	int size = _rooms.size();
	for (int i = 0; i < size; i++)
		cout << _rooms[i]->getName() << endl;
}