#include "PromotingActivity.h"

//Constructors and destructors
PromotingActivity::PromotingActivity(string name, string details, Room* room, Person* person)
	:Activity(name, details, room, person)
{
	
}
PromotingActivity::~PromotingActivity() {}

void PromotingActivity::printSpecificDetails() {

}