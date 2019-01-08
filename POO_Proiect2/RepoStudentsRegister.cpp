#include "RepoStudentsRegister.h"

//Constructors and destructors
RepoStudentsRegister::RepoStudentsRegister() {}
RepoStudentsRegister::~RepoStudentsRegister() {}

RegisterPage* RepoStudentsRegister::findByStudent(Person* student) {
	unsigned int size = _entities.size();
	for (unsigned int i = 0; i < size; i++)
	{
		if (_entities[i]->getStudent() == student)
			return _entities[i];
	}

	return NULL;
}