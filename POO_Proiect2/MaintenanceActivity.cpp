#include "MaintenanceActivity.h"

//Constructors and destructors
MaintenanceActivity::MaintenanceActivity(string name, string details, Room* room, Person* person)
	:Activity(name, details, room, person)
{

}
MaintenanceActivity::~MaintenanceActivity() {}

void MaintenanceActivity::printSpecificDetails() {

}