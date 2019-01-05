#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class RepoTemplate
{
public:
	RepoTemplate();
	~RepoTemplate();

	void add(T* e);
	bool remove(string name); //We provide the name, because all subclasses have it
	void printAll();

protected:   //Because I want to see them in subClasses
	vector<T*> _entities;  //Using pointers so that there is actually an interaction
};

