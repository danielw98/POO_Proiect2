#include "RepoTemplate.h"
#include <algorithm>

//Constructors and destructors
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
bool RepoTemplate<T>::remove(T* e) {
	delete e; //Free pointer before removing and destroying
	//To remove the specific item we will use erase and remove
	_entities.erase(std::remove(_entities.begin(), _entities.end(), e), _entities.end());
	return true;
}
template<class T>
void RepoTemplate<T>::printAll() {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
		cout << *_entities[i] << endl;  //Derefrencing. Also impling operator overload for all
}