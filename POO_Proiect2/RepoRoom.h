#pragma once
#include "RepoTemplate.h"
#include "RepoTemplate.cpp"
#include "Room.h"

class RepoRoom : public RepoTemplate<Room> {
public:
	RepoRoom();
	~RepoRoom();
};