#pragma once
#include "Room.h"
#include "Activity.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class College
{
public:
	College();
	~College();

	//Functions for college
	void addRoom(string name);
	void delRoom(string name);
	void listRooms();

private:
	vector<Room*> _rooms;
};