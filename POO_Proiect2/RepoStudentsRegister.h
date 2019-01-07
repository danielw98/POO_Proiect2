#pragma once
#include "RepoTemplate.h"
#include "RegisterPage.h"

class RepoStudentsRegister : public RepoTemplate<RegisterPage> {
public:
	RepoStudentsRegister();
	~RepoStudentsRegister();

	//RegisterPage* findByName(string name);
};