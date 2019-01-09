#include "College.h"
#include <algorithm>  //So we can use find

//Constructor and destructor
College::College() {
	//Here we will create a scenario, for ease of testing

	//We create the roles accepted in this college
	_acceptedRoles.push_back("PROFFESSOR");  //0
	_acceptedRoles.push_back("STUDENT");  //1
	_acceptedRoles.push_back("HEADMASTER");  //2
	_acceptedRoles.push_back("PROMOTER");  //3

	//We create the activity types accepted in this college
	_acceptedActivityTypes.push_back("DIDACTIC");  //0
	_acceptedActivityTypes.push_back("PROMOTING");  //1
	_acceptedActivityTypes.push_back("MAINTENANCE");  //2

	//We create some rooms
	_rr.add(new Room("Camera1"));
	_rr.add(new Room("Camera2"));
	_rr.add(new Room("Camera3"));
	_rr.add(new Room("Camera4"));
	_rr.add(new Room("Camera5"));
	_rr.add(new Room("Camera6"));
	_rr.add(new Room("Camera7"));

	//We create some persons
	_rp.add(new Person("Persoana1", "1234567890123", "PROFFESSOR"));
	_rp.add(new Person("Persoana2", "1234567890124", "PROFFESSOR"));
	_rp.add(new Person("Persoana3", "1234567890125", "STUDENT"));
	_rp.add(new Person("Persoana4", "1234567890126", "STUDENT"));
	_rp.add(new Person("Persoana5", "1234567890127", "STUDENT"));
	_rp.add(new Person("Persoana6", "1234567890128", "HEADMASTER"));
	_rp.add(new Person("Persoana7", "1234567890129", "PROMOTER"));

	//Also create the register, for now. Because it is AUTO MANAGED
	_rsr.add(new RegisterPage(_rp.findByName("Persoana3"), vector<string> {"Math", "English"}));
	_rsr.add(new RegisterPage(_rp.findByName("Persoana4"), vector<string> {"Physics", "Chemestry"}));
	_rsr.add(new RegisterPage(_rp.findByName("Persoana5"), vector<string> {"Math", "Biology"}));

	//We create some activities
	_ra.add(new DidacticActivity("Didactic1", "DDetails", _rr.findByName("Camera1"), _rp.findByName("Persoana1"), vector<string> {"Math", "English", "Sport"}));
	_ra.add(new DidacticActivity("Didactic2", "DDetails", _rr.findByName("Camera2"), _rp.findByName("Persoana2"), vector<string> {"Physics", "English"}));
	_ra.add(new DidacticActivity("Didactic3", "DDetails", _rr.findByName("Camera3"), _rp.findByName("Persoana1"), vector<string> {"Math", "Chemestry", "Biology"}));
	_ra.add(new DidacticActivity("Didactic4", "DDetails", _rr.findByName("Camera1"), _rp.findByName("Persoana2"), vector<string> {"Chemestry", "Algebra"}));
	_ra.add(new MaintenanceActivity("Maintenance1", "MDetails", _rr.findByName("Camera5"), _rp.findByName("Persoana6")));
	_ra.add(new PromotingActivity("Promoting1", "PDetails", _rr.findByName("Camera7"), _rp.findByName("Persoana7")));
};
College::~College() {}

//Rooms
void College::addRoom() {
	string name;

	cout << "Please insert the room name: ";
	getline(cin >> ws, name);  //We use ws for getline to work
	
	_rr.add(new Room(name));

	cout << "Succes room addition" << endl;
}
void College::delRoom() {
	string name;

	cout << "Please insert the room name: ";
	getline(cin >> ws, name);

	Room* roomToDel = _rr.findByName(name);
	if (roomToDel)
	{
		if (_rr.remove(roomToDel))
			cout << "Succes room deletion" << endl;
	}
	else
		cout << "Something went wrong, probably the room does not exist" << endl;
}

//Persons
void College::addPerson(unsigned int insertType) {
	string name;
	string cnp;  //Defaults to empty
	unsigned int roleIndex;

	this->listAcceptedRoles(); //We ask college for roles

	cout << "Please insert the person name: ";
	getline(cin >> ws, name);
	
	if (insertType == 1) { //We ask for cnp also
		cout << "Please insert the CNP of this person: ";
		getline(cin >> ws, cnp);
	}

	cout << "Please pick a role (index) for this person: ";
	cin >> roleIndex;

	//We ask for disciplines if it is a student
	vector<string> disciplines;
	if (roleIndex == 1) {  //We just know the right index. It is the same if we knew the right name for this role, so no biggie
		string discipline;

		cout << "This is a student, so I need to know the the disciplines for him." << endl;
		cout << "Please insert a discipline and hit enter. To stop type \"Quit\"." << endl;

		getline(cin >> ws, discipline);
		while (discipline != "Quit") {
			disciplines.push_back(discipline);

			getline(cin >> ws, discipline);
		}
	}

	if (isThisRoleAccepted(roleIndex))
	{
		Person* person = new Person(name, cnp, getRoleByIndex(roleIndex));
		_rp.add(person);
		cout << "Succes Person addition" << endl;

		//We AUTO add the student to the students register
		if (roleIndex == 1)
			_rsr.add(new RegisterPage(person, disciplines));
	}
	else
		cout << "This role is not accepted in this college." << endl;
}
void College::delPerson(unsigned int delType) {
	Person* personToDel = NULL;

	if (delType == 0) {
		string name;
		cout << "Please insert the person name: ";
		getline(cin >> ws, name);
		personToDel = _rp.findByName(name);
	}
	else if (delType == 1) {
		string CNP;
		cout << "Please insert the CNP: ";
		getline(cin >> ws, CNP);
		personToDel = _rp.findByCNP(CNP);
	}

	//If the person was found
	if (personToDel)
	{
		//If this a student, we first delete it (register page) from the register, to avoid accessing NULL pointers
		if (personToDel->getRole() == "STUDENT")
			_rsr.remove(_rsr.findByStudent(personToDel));

		if (_rp.remove(personToDel))
			cout << "Succes person deletion" << endl;
	}
	else
		cout << "Something went wrong, probably the person does not exist." << endl;
}

//Activities
void College::addActivity() {
	string name;
	string details;
	string rName;
	string cnp;
	Room* room = NULL;
	Person* person = NULL;
	unsigned int typeIndex;

	cout << "Please insert the activity name: ";
	getline(cin >> ws, name);
	
	cout << "Please insert some details: ";
	getline(cin >> ws, details);
	
	cout << "Please pick a room (name of room): ";
	getline(cin >> ws, rName);
	room = _rr.findByName(rName);
	while (room == NULL) {
		cout << "This room doesn't exist. Try again. Type \"Quit\" to quit.\n...: ";
		getline(cin >> ws, rName);
		if (rName == "Quit")
			return;
		room = _rr.findByName(rName);
	}

	cout << "Please insert the organizer CNP: ";
	getline(cin >> ws, cnp);
	person = _rp.findByCNP(cnp);
	while (room == NULL) {
		cout << "This person doesn't exist. Try again. Type \"Quit\" to quit.\n...: ";
		getline(cin >> ws, cnp);
		if (rName == "Quit")
			return;
		room = _rr.findByName(cnp);
	}

	this->listAcceptedActivityTypes();
	cout << "Tell us, what activity type this is (index): ";
	cin >> typeIndex;

	//Verificam compatibilitatea
	if (!(this->isRoleAndActivityTypeCompatible(typeIndex, person->getRole()))) {
		cout << "We are sorry, this role is not compatible with the actiity. Try again, if you whis." << endl;
		return;
	}

	if (typeIndex == 0) {  //Didactic
		string discipline;
		vector<string> disciplines;

		cout << "This is a didactic activity, so I need to know the Disciplines involved." << endl;
		cout << "Please insert a discipline and hit enter. To stop type \"Quit\"." << endl;

		getline(cin >> ws, discipline);
		while (discipline != "Quit") {
			disciplines.push_back(discipline);

			getline(cin >> ws, discipline);
		}

		_ra.add(new DidacticActivity(name, details, room, person, disciplines));
	}
	else if (typeIndex == 1) {  //Promoting
		_ra.add(new PromotingActivity(name, details, room, person));
	}
	else if (typeIndex == 2) {  //Maintenance
		_ra.add(new MaintenanceActivity(name, details, room, person));
	}

	cout << "Activity successfully added" << endl;

}
void College::delActivity() {
	Activity* actToDel = NULL;
	string name;

	cout << "Please insert the activity name: ";
	getline(cin >> ws, name);
	actToDel = _ra.findByName(name);

	//If the activity was found
	if (actToDel)
	{
		if (_ra.remove(actToDel))
			cout << "Succes activity deletion" << endl;
	}
	else
		cout << "Something went wrong, probably the activity does not exist" << endl;
}

//Student Register
void College::listStudentsOnly() {
	//We use a repo function to get what we want. Just like a man accessing an app with filter field
	cout << "Students: \n";
	_rp.printStudentsOnly();
}

//Person Perspective
Person* College::getPersonByName(string name) {
	return _rp.findByName(name);
}
Activity* College::getActivityByIndex(unsigned int index) {
	return _ra.findByIndex(index);
}
void College::enrollToActivity(Person* person) {
	//We print the activities and indexex
	this->listActivities();

	unsigned int activityIndex;
	cout << "Please pick the activity (index) you want to participate: ";
	cin >> activityIndex;

	Activity* act = this->getActivityByIndex(activityIndex);
	if (act == NULL) {
		cout << "Something went wrong, probably the activity does not exist." << endl;
		return;
	}

	//Check to see if you are the organizer
	if (act->getOrganizer() == person) {
		cout << "You are the organizer. You already participate..." << endl;
		return;
	}

	string actType;
	//We check the activity type
	const DidacticActivity* dCheck = dynamic_cast<const DidacticActivity*>(act);
	if (dCheck != NULL)
		actType = "DIDACTIC";
	const PromotingActivity* pCheck = dynamic_cast<const PromotingActivity*>(act);
	if (pCheck != NULL)
		actType = "PROMOTING";
	const MaintenanceActivity* mCheck = dynamic_cast<const MaintenanceActivity*>(act);
	if (mCheck != NULL)
		actType = "MAINTENANCE";

	if (!(this->canRoleParticipateToActivity(person->getRole(), actType))) {
		cout << "We are sory, but your role doesn't allow you to participate at this activity. Try again, if you wish." << endl;
		return;
	}

	//We check to see if disciplines match, only for students
	if (person->getRole() == "STUDENT" && actType == "DIDACTIC") {
		vector<string> studentDisciplines = _rsr.findByStudent(person)->getDisciplines();
		vector<string> activityDIsciplines = dCheck->getAcceptedDisciplines();

		if (!(canStudentParticipateToDidactic(studentDisciplines, activityDIsciplines))) {
			cout << "We are sorry, but your discipline doesn't allow you to participate to this didactic activity." << endl;
			return;
		}
	}

	//Finally add activity to person and viceversa
	act->addPersonToAttendes(person);
	person->attendActivity(act);

	cout << "Enrolled with succes" << endl;
}
void College::stopAttendingToActivity(Person* person) {
	Activity* actToDel = NULL;
	string name;

	cout << "Please insert the activity name you want to stop attending: ";
	getline(cin >> ws, name);
	actToDel = _ra.findByName(name);

	//If the activity was found
	if (!actToDel)
	{
		cout << "Something went wrong, probably the activity does not exist" << endl;
		return;
	}

	//Remove act from person and viceversa
	person->stopAttendingActivity(actToDel);
	actToDel->delPersonFromAttendes(person);

	cout << "You stoped participating to this activity" << endl;
}
void College::listAttendingActivities(Person* person) {
	cout << "Attending activities: " << endl;
	person->listAttendingActivities();
}

void College::listAll(unsigned int choice)
{
	if (choice == 0) {
		cout << "Rooms: \n";
		_rr.printAll();
	}
	else if (choice == 1) {
		cout << "Persons: \n";
		_rp.printAll();
	}
	else if (choice == 2) {
		cout << "Activities: \n";
		_ra.printAll();
	}
	else if (choice == 3) {
		cout << "Registru studenti: \n";
		_rsr.printAll();
	}
}

//Public Relationships functions
void College::listAcceptedRoles() {
	cout << "These are the available roles for new persons..." << endl;
	unsigned int size = _acceptedRoles.size();
	for (unsigned int i = 0; i < size; i++)
		cout << i << ". " << _acceptedRoles[i] << endl;
}
void College::listAcceptedActivityTypes() {
	cout << "These are the available activity types for new activities..." << endl;
	unsigned int size = _acceptedActivityTypes.size();
	for (unsigned int i = 0; i < size; i++)
		cout << i << ". " << _acceptedActivityTypes[i] << endl;
}
void College::listActivities() {
	_ra.printSummary();
}

//Institute functions
bool College::isThisRoleAccepted(unsigned int index) {
	/*
	//Using iterators instead of basic for loops
	if (find(_acceptedRoles.begin(), _acceptedRoles.end(), name) != _acceptedRoles.end())
		return true;
	else
		return false;
	*/

	if (index < 0 || index >= _acceptedRoles.size())
		return false;
	else
		return true;
}
string College::getRoleByIndex(unsigned int index) {
	return _acceptedRoles[index];
}
bool College::isThisActivityTypeAccepted(unsigned int index) {
	/*
	//Using iterators instead of basic for loops
	if (find(_acceptedActivityTypes.begin(), _acceptedActivityTypes.end(), name) != _acceptedActivityTypes.end())
		return true;
	else
		return false;
	*/

	if (index < 0 || index >= _acceptedActivityTypes.size())
		return false;
	else
		return true;
}
string College::getActivityTypeByIndex(unsigned int index) {
	return _acceptedActivityTypes[index];
}
bool College::isRoleAndActivityTypeCompatible(unsigned int typeIndex, string role) {
	if (typeIndex == 0 && role == "PROFFESSOR")  //Didactic si profesor
		return true;
	if (typeIndex == 1 && role == "PROMOTER") //Promoting si promoter
		return true;
	if (typeIndex == 2 && role == "HEADMASTER")  //Maintenance si HeadMaster
		return true;

	//Pe viitor odata cu adaugarea rolurilor si activitatilor se pot adauga noi combinatii

	return false;
}
bool College::canRoleParticipateToActivity(string role, string actType) {
	if (role == "PROFFESSOR") //The proffessors can participate to anything
		return true;
	if (role == "HEADMASTER") //The headmaster have to participate to anything
		return true;
	if (role == "PROMOTER") {
		if (actType == "PROMOTING")
			return true;
	}
	if (role == "STUDENT") {
		if (actType == "DIDACTIC")
			return true;
		if (actType == "PROMOTING")
			return true;
	}

	return false;
}
bool College::canStudentParticipateToDidactic(vector<string> studentDisciplines, vector<string> didacticDisciplines) {
	unsigned int stdSize = studentDisciplines.size();
	unsigned int actSize = didacticDisciplines.size();

	for (unsigned int i = 0; i < stdSize; i++) {
		for (unsigned int j = 0; j < actSize; j++) {
			if (studentDisciplines[i] == didacticDisciplines[j])
				return true;
		}
	}

	return false;
}