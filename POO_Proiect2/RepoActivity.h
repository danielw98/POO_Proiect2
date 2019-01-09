#pragma once
#include "RepoTemplate.h"
#include "Activity.h"

class RepoActivity : public RepoTemplate<Activity> {
public:
	//Constructors and destructors
	RepoActivity();
	~RepoActivity();

	//Find functions
	Activity* findByName(string name);
	Activity* findByIndex(unsigned int index);
	Activity* findByRoom(string name);
	Activity* findByOrganizer(string name);

	void printSummary();
};