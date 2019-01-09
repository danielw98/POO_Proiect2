#include "RepoRoom.h"

//Constructors and destructors
RepoRoom::RepoRoom() {}
RepoRoom::~RepoRoom() {}

//Find functions
Room* RepoRoom::findByName(string name) {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (_entities[i]->getName() == name)
			return _entities[i];
	}

	return NULL;
}