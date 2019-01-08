#pragma once
#include <vector>
#include <string>
using namespace std;
#include "Person.h"


class RegisterPage {
public:
	//Constructors and destructors
	RegisterPage(Person* student, vector<string> enrolledDisciplines);
	~RegisterPage();

	//Getters and Setters
	Person* getStudent();

	friend ostream& operator <<(ostream& out, const RegisterPage& src);

private:
	Person* _student;  //Person with student role
	vector<string> _enrolledDisciplines;
};