#pragma once
#include "RepoTemplate.h"
#include "RegisterPage.h"

class RepoStudentsRegister : public RepoTemplate<RegisterPage> {
public:
	//Constructors and destructors
	RepoStudentsRegister();
	~RepoStudentsRegister();

	RegisterPage* findByStudent(Person* student);
};