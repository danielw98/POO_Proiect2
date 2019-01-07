#pragma once
#include "RepoTemplate.h"
#include "Room.h"

class RepoRoom : public RepoTemplate<Room> {
public:
	RepoRoom();
	~RepoRoom();

	Room* findByName(string name);
};