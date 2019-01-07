#include<iostream>
#include<conio.h>
using namespace std;
#include "College.h"

//Console view functions
void print_banner() {
	cout << "1. Add room" << endl;
	cout << "2. Delete room" << endl;
	cout << "3. List rooms" << endl;
	cout << "4. Add person (only name)" << endl;
	cout << "5. Add person (name and CNP)" << endl;
	cout << "6. Delete person by name" << endl;
	cout << "7. Delete person by CNP" << endl;
	cout << "8. List persons" << endl;
	cout << "9. Add activity" << endl;
	cout << "10. Delete activity" << endl;
	cout << "11. List activities" << endl;
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
		cin >> option;

		switch (option)
		{
		case 1:
			C.addRoom();
			pause();
			break;
		case 2:
			C.delRoom();
			pause();
			break;
		case 3:
			C.listAll(0);
			pause();
			break;
		case 4:
			C.addPerson(0); //We ask only for name
			pause();
			break;
		case 5:
			C.addPerson(1); //We ask for name and CNP
			pause();
			break;
		case 6:
			C.delPerson(0); //Del by name
			pause();
			break;
		case 7:
			C.delPerson(1); //Del by CNP
			pause();
			break;
		case 8:
			C.listAll(1);
			pause();
			break;
		case 9:
			C.addActivity(); //Full add
			pause();
			break;
		case 10:
			C.delActivity();  //Del by name
			pause();
			break;
		case 11:
			C.listAll(2);
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