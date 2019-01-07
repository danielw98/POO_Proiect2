#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Room.h"
#include "Person.h"

class Person;  //Forward declaration because we use Activity in Person and vice-versa

class Activity
{
public:
	//Constructors and destructors
	Activity(string name, string details, Room* room, Person* person);
	virtual ~Activity();

	//Getters and Setters
	string getName();

	virtual void printSpecificDetails() = 0; //This ensures this class is an interface and we can't instantiate it
	friend ostream& operator <<(ostream& out, const Activity& src);

protected:
	string _name;
	string _details;
	Room* _room;
	Person* _organizer;
	vector<Person*> _attendees;
};