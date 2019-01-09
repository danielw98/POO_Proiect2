#pragma once
#include "RepoTemplate.h"
#include "Person.h"

class RepoPerson : public RepoTemplate<Person> {
public:
	//Constructors and destructors
	RepoPerson();
	~RepoPerson();

	//Find functions
	Person* findByName(string name);
	Person* findByCNP(string cnp);

	void printStudentsOnly();  //It's the job of the Repo to filter what we need
};