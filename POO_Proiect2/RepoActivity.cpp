#include "RepoActivity.h"

//Constructors and destructors
RepoActivity::RepoActivity() {}
RepoActivity::~RepoActivity() {}

//Find functions
Activity* RepoActivity::findByName(string name) {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (_entities[i]->getName() == name)
			return _entities[i];
	}

	return NULL;
}
Activity* RepoActivity::findByIndex(unsigned int index) {
	unsigned int size = _entities.size();
	
	if (index < 0 || index >= size)
		return NULL;

	return _entities[index];
}

void RepoActivity::printSummary() {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		cout << i << ". " << *(_entities[i]) << endl;
	}
}