#pragma once
#include "RepoTemplate.h"
#include "RegisterPage.h"

class RepoStudentsRegister : public RepoTemplate<RegisterPage> {
public:
	//Constructors and destructors
	RepoStudentsRegister();
	~RepoStudentsRegister();

	//Find functions
	RegisterPage* findByStudent(const Person* student);
};