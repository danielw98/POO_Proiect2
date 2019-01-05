#pragma once
#include <string>
#include <iostream>
using namespace std; 

class Room {
public:
	Room(string name);
	~Room();
	
	string getName();

private:
	string _name;
};
