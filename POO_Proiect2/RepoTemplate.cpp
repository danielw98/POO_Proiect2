#include "RepoTemplate.h"

template<class T>
RepoTemplate<T>::RepoTemplate() {}

template<class T>
RepoTemplate<T>::~RepoTemplate() {
	//Clean-up TIME
	for (unsigned int i = 0; i < _entities.size(); i++)
		delete _entities[i]; //Free pointers
	_entities.clear();
}

template<class T>
void RepoTemplate<T>::add(T* e) {
	_entities.push_back(e);
}

template<class T>
bool RepoTemplate<T>::remove(string name) {
	bool succes = false;
	for (unsigned int i = 0; i < _entities.size(); i++)
		if (_entities[i]->getName() == name)
		{
			delete _entities[i]; //Free pointer before removing
			_entities.erase(_entities.begin() + i);
			i--;

			succes = true;
		}

	return succes;  //Return to see if succesfull
}

template<class T>
void RepoTemplate<T>::printAll() {
	int size = _entities.size();
	for (int i = 0; i < size; i++)
		cout << _entities[i]->getName() << endl;
}