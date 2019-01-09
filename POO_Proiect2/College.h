#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Room.h"
#include "Activity.h"
#include "DidacticActivity.h"
#include "PromotingActivity.h"
#include "MaintenanceActivity.h"
#include "RepoRoom.h"
#include "RepoPerson.h"
#include "RepoActivity.h"
#include "RepoStudentsRegister.h"

class College
{
public:
	//Constructors and destructors
	College();
	~College();

	//Rooms
	void addRoom();
	void delRoom();

	//Persons
	void addPerson(unsigned int insertType);
	void delPerson(unsigned int delType);

	//Activities
	void addActivity();
	void delActivity();

	//Student Register
	void listStudentsOnly();

	//Person Perspective
	Person* getPersonByName(string name); //Const person, so we can't modify the object. Considering its 'outside' use
	Activity* getActivityByIndex(unsigned int index);
	void enrollToActivity(Person* person);
	void stopAttendingToActivity(Person* person);
	void listAttendingActivities(Person* person);

	void listAll(unsigned int choice);

	//Public Relationships functions
	void listAcceptedRoles();
	void listAcceptedActivityTypes();
	void listActivities();

private:
	//Repositories
	RepoRoom _rr;  //Repo Rooms
	RepoPerson _rp;  //Repo Persons
	RepoActivity _ra;  //Repo Activities
	RepoStudentsRegister _rsr;  //Registru studenti


	//Roles and activities. These are asigned by the institute.
	//In this case, this very college
	vector<string> _acceptedRoles;
	vector<string> _acceptedActivityTypes;

	//Institute functions
	bool isThisRoleAccepted(unsigned int index);
	string getRoleByIndex(unsigned int index);
	bool isThisActivityTypeAccepted(unsigned int index);
	string getActivityTypeByIndex(unsigned int index);
	bool isRoleAndActivityTypeCompatible(unsigned int typeIndex, string role);
	bool canRoleParticipateToActivity(string role, string actType);
	bool canStudentParticipateToDidactic(vector<string> studentDisciplines, vector<string> didacticDisciplines);
};