#include "DidacticActivity.h"

//Constructors and destructors
DidacticActivity::DidacticActivity(string name, string details, Room* room, Person* person, vector<string> disciplines)
	:Activity(name, details, room, person)
{
	this->_acceptedDisciplines = disciplines;
}
DidacticActivity::~DidacticActivity() {}

//Getters and Setters
vector<string> DidacticActivity::getAcceptedDisciplines() const {
	return this->_acceptedDisciplines;
}

void DidacticActivity::printSpecificDetails() {

}
ostream& operator <<(ostream& out, const DidacticActivity& src) {
	out << "___________ Activity ___________" << endl;
	out << "Name: " << src._name << endl;
	out << "   _____ Organizer _____   " << endl;
	out << *(src._organizer);
	out << "Room: " << *(src._room);
	out << "Details:";
	if ( !(src._details.empty()) )
		out << src._details;
	out << "Disciplines: ";
	if (!(src._acceptedDisciplines.empty())) {
		unsigned int size = src._acceptedDisciplines.size();
		out << src._acceptedDisciplines[0];
		for (unsigned int i = 1; i < size; i++) {
			out << ", " << src._acceptedDisciplines[i];
		}
	}
	out << endl;

	return out;
}