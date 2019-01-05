#include<iostream>
#include<conio.h>
using namespace std;
#include "College.h"

//Console view functions
void print_banner() {
	cout << "1. Add room" << endl;
	cout << "2. Delete room" << endl;
	cout << "3. List rooms" << endl;
	cout << "0. Leave App" << endl;
	cout << endl;
	cout << "Make your pick: ";
}

void pause() {
	fflush(stdin);
	cout << "\nPress any key to go back...";
	_getch();
	fflush(stdin);
}

int main() {
	College C;

	int option = -1;
	
	while (option != 0) {
		system("cls");
		print_banner();
		string res;
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Room name: " << endl;
			getline(cin >> ws, res);  //We use ws for getline to work
			C.addRoom(res);
			pause();
			break;
		case 2:
			cout << "Room name: " << endl;
			getline(cin >> ws, res);
			C.delRoom(res);
			pause();
			break;
		case 3:
			C.listAll(0);
			pause();
			break;
		case 0:
			cout << "Good Bye" << endl;
			option = 0;
			break;
		default:
			cout << "Invalid option. Bye" << endl;
			option = 0;;
		}
	}
	
	return 0;
}