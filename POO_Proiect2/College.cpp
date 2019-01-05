#include "College.h"

College::College() {
	//Here we will create a scenario, for ease of testing
	//We create some rooms
	_rr.add(new Room("Camera1"));
	_rr.add(new Room("Camera2"));
	_rr.add(new Room("Camera3"));
	_rr.add(new Room("Camera4"));
	_rr.add(new Room("Camera5"));
	_rr.add(new Room("Camera6"));
	_rr.add(new Room("Camera7"));
};
College::~College() {}

//Rooms
void College::addRoom(string name)
{
	_rr.add(new Room(name));

	cout << "Succes room addition" << endl;
}
void College::delRoom(string name)
{
	if( _rr.remove(name) )
		cout << "Succes room deletion" << endl;
	else
		cout << "Something went wrong, probably the room does not exist" << endl;
}

//Persons
void College::addPerson(string name) {
	_rp.add(new Person(name, Person::Role::HEADMASTER));

	cout << "Succes Person addition" << endl;
}
void College::delPerson(string name) {

}

void College::listAll(unsigned int choice)
{
	if (choice == 0) {
		cout << "Rooms: \n";
		_rr.printAll();
	}
}

void getCurrentPersonRoles() {

}