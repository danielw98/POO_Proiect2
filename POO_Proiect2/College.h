#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Room.h"
#include "Activity.h"
#include "RepoRoom.h"
#include "RepoPerson.h"

class College
{
public:
	College();
	~College();

	//Functions for college
	//Rooms
	void addRoom(string name);
	void delRoom(string name);

	//Persons
	void addPerson(string name);
	void delPerson(string name);

	void listAll(unsigned int choice);

	//College functions
	void getCurrentPersonRoles();

private:
	RepoRoom _rr;
	RepoPerson _rp;
};