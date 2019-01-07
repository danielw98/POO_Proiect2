#pragma once
#include <vector>
#include <string>
using namespace std;
#include "Person.h"


class RegisterPage {
public:
	RegisterPage();
	~RegisterPage();

private:
	Person* _student;  //Person with student role
	vector<string> _enrolledDisciplines;
};