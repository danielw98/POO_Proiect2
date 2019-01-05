#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Activity.h"


class Person {
public:
	enum class Role {
		PROFESSOR,
		STUDENT,
		HEADMASTER,
		PROMOTER
	};

	Person(string name, Role role);
	Person(string name, string cnp, Role role);
	~Person();

	//Getter and setter
	//Attending(Activity*)
	//StopAttending
	//Present yourself
	//Tell us what are you attending

private:
	string _name;
	string _cnp;
	vector<Activity*> _activities;  //Can participate at multiple activities
	Role _role;
};