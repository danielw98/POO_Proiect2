#include "RegisterPage.h"

//Constructors and destructors
RegisterPage::RegisterPage(Person* student, vector<string> enrolledDisciplines) {
	this->_student = student;
	this->_enrolledDisciplines = enrolledDisciplines;
}
RegisterPage::~RegisterPage() {}

//Getters and Setters
Person* RegisterPage::getStudent() {
	return _student;
}

ostream& operator <<(ostream& out, const RegisterPage& src) {
	out << "________ Register Page ________" << endl;
	out << *(src._student) << endl;
	out << "Disciplines: ";
	if (!(src._enrolledDisciplines.empty())) {
		unsigned int size = src._enrolledDisciplines.size();
		out << src._enrolledDisciplines[0];
		for (unsigned int i = 1; i < size; i++) {
			out << ", " << src._enrolledDisciplines[i];
		}
	}
	out << endl;

	return out;
}