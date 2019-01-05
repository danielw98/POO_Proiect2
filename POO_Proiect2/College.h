#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Room.h"
#include "Activity.h"
#include "RepoRoom.h"

class College
{
public:
	College();
	~College();

	//Functions for college
	void addRoom(string name);
	void delRoom(string name);
	void listAll(unsigned int choice);

private:
	RepoRoom _rr;
};