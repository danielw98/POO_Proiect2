#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Activity.h"

class DidacticActivity : public Activity {
public:
	//Constructors and destructors
	DidacticActivity(string name, string details, Room* room, Person* person, vector<string> disciplines);
	~DidacticActivity();

	//Getters and Setters
	vector<string> getAcceptedDisciplines() const;

	void printSpecificDetails();
	friend ostream& operator <<(ostream& out, const DidacticActivity& src);
private:
	vector<string> _acceptedDisciplines;
};