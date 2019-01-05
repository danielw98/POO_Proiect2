#pragma once
#include "Room.h"
#include <string>

using namespace std;

class Activity
{
public:
	enum class ActType {     //We define the activity types
		DIDACTIC,
		PROMOTING,
		MAINTENANCE
	};

	Activity(ActType type, string name, string details, Room* room);  //We force the user to use the predefined activities
	~Activity();

private:
	ActType _type;
	string _name;
	string _details;
	Room* _room;
};