#pragma once
#include "RepoTemplate.h"
#include "Person.h"

class RepoPerson : public RepoTemplate<Person> {
public:
	RepoPerson();
	~RepoPerson();

	Person* findByName(string name);
	Person* findByCNP(string cnp);
};