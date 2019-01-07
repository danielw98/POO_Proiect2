#pragma once
#include <string>
#include <iostream>
using namespace std; 

class Room {
public:
	Room(string name);
	~Room();
	
	string getName();
	friend ostream& operator <<(ostream& out, const Room& src);

private:
	string _name;
};
