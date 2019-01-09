#pragma once
#include <string>
#include <vector>
using namespace std;
#include "Activity.h"

class Activity;  //Forward declaration because we use Activity in Person and vice-versa

class Person {
public:
	//Constructors and destructors
	Person(string name, string role);
	Person(string name, string cnp, string role);
	~Person();

	//Getters and Setters
	string getName();
	string getCNP();
	string getRole() const;

	//Attending functions
	void attendActivity(Activity* activity);
	void stopAttendingActivity(Activity* activity);
	void listAttendingActivities();

	friend ostream& operator <<(ostream& out, const Person& src);

private:
	string _name;
	string _cnp;
	vector<Activity*> _activities;  //Can participate at multiple activities
	string _role;
};