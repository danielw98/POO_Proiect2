#include "RepoPerson.h"

//Constructors and destructors
RepoPerson::RepoPerson() {}
RepoPerson::~RepoPerson() {}

//Find functions
Person* RepoPerson::findByName(string name) {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (_entities[i]->getName() == name)
			return _entities[i];
	}

	return NULL;
}
Person* RepoPerson::findByCNP(string cnp) {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (_entities[i]->getCNP() == cnp)
			return _entities[i];
	}

	return NULL;
}

void RepoPerson::printStudentsOnly() {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (_entities[i]->getRole() == "STUDENT")
			cout << *(_entities[i]);
	}
}