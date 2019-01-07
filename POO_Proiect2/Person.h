#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Activity.h"

class Activity;  //Forward declaration because we use Activity in Person and vice-versa

class Person {
public:
	Person(string name, string role);
	Person(string name, string cnp, string role);
	~Person();

	//Getter and setter
	string getName();
	string getCNP();
	string getRole();
	//Attending(Activity*)
	//StopAttending
	//Present yourself
	//Tell us what are you attending

	friend ostream& operator <<(ostream& out, const Person& src);

private:
	string _name;
	string _cnp;
	vector<Activity*> _activities;  //Can participate at multiple activities
	string _role;
};