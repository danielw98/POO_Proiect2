#include "DidacticActivity.h"

//Constructors and destructors
DidacticActivity::DidacticActivity(string name, string details, Room* room, Person* person, vector<string> disciplines)
	:Activity(name, details, room, person)
{
	this->_acceptedDisciplines = disciplines;
}
DidacticActivity::~DidacticActivity() {}

void DidacticActivity::printSpecificDetails() {

}