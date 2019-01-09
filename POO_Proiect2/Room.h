#pragma once
#include <string>
#include <iostream>
using namespace std; 

class Room {
public:
	//Constructors and destructors
	Room(string name);
	~Room();
	
	//Getters and Setters
	string getName();

	friend ostream& operator <<(ostream& out, const Room& src);

private:
	string _name;
};
