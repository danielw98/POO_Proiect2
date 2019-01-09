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
	cout << "12. List student register" << endl;
	cout << "13. Person perspective" << endl;
	cout << "0. Leave App" << endl;
	cout << endl;
	cout << "Make your pick: ";
}
void print_personPerspective_banner(const Person* person) {
	cout << "______ You are ______" << endl;
	cout << *person << endl;
	cout << "1. Enroll to activity" << endl;
	cout << "2. Stop attending" << endl;
	cout << "3. List my attending activities" << endl;
	cout << "0. Leave submenu" << endl;
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

	unsigned int option = -1;
	
	while (option != 0) {
		system("cls");
		print_banner();
		cin >> option;
		cout << endl;

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
		case 12:
			C.listAll(3);
			pause();
			break;
		case 13:
		{
			//Ask for the person you want to be
			system("cls");
			cout << "Please insert your name: ";
			string name;
			getline(cin >> ws, name);

			Person* person = C.getPersonByName(name);
			if (person == NULL) {
				cout << "Something went wrong, probably the person does not exist." << endl;
				cout << "Leaving submenu.";
				pause();
				break;
			}

			unsigned int person_option = -1;
			while (person_option != 0) {
				system("cls");
				print_personPerspective_banner(person);
				cin >> person_option;
				cout << endl;

				switch (person_option)
				{
				case 1:
					//You have to go to college to see the activities and enroll
					C.enrollToActivity(person);
					pause();
					break;
				case 2:
					C.stopAttendingToActivity(person);
					pause();
					break;
				case 3:
					C.listAttendingActivities(person);
					pause();
					break;
				case 0:
					cout << "Good Bye" << endl;
					person_option = 0;
					break;
				default:
					cout << "Invalid option. Leaving submenu." << endl;
					person_option = 0;
					pause();
				}
			}
			break;
		}
		case 0:
			cout << "Good Bye" << endl;
			option = 0;
			break;
		default:
			cout << "Invalid option. Bye" << endl;
			option = 0;
		}
	}
	
	return 0;
}