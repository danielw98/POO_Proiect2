#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class RepoTemplate
{
public:
	//Constructors and destructors
	RepoTemplate();
	~RepoTemplate();

	void add(T* e);
	bool remove(T* e);
	void printAll();

protected:   //Because I want to see them in subClasses
	vector<T*> _entities;  //Using pointers so that there is actually an interaction
};

//We include the cpp here because we want it to be include here, 
//so that pragma once affects him and we only have him once. This is
//to avoid multiple defintions compile error.
//WE ALSO HAVE TO EXCLUDE FROM THE BUID!!!!

#include "RepoTemplate.cpp"