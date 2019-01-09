#pragma once
#include "RepoTemplate.h"
#include "Room.h"

class RepoRoom : public RepoTemplate<Room> {
public:
	//Constructors and destructors
	RepoRoom();
	~RepoRoom();

	//Find functions
	Room* findByName(string name);
};