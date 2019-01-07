#pragma once
#include "Activity.h"

class PromotingActivity : public Activity {
public:
	//Constructors and destructors
	PromotingActivity(string name, string details, Room* room, Person* person);
	~PromotingActivity();

	void printSpecificDetails();
};