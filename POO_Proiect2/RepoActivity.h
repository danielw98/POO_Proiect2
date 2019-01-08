#pragma once
#include "RepoTemplate.h"
#include "Activity.h"

class RepoActivity : public RepoTemplate<Activity> {
public:
	RepoActivity();
	~RepoActivity();

	Activity* findByName(string name);
	Activity* findByRoom(string name);
	Activity* findByOrganizer(string name);

	void printSummary();
};