#pragma once
#include "Activity.h"

class MaintenanceActivity : public Activity {
public:
	//Constructors and destructors
	MaintenanceActivity(string name, string details, Room* room, Person* person);
	~MaintenanceActivity();

	void printSpecificDetails();
};