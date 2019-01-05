#include "Activity.h"

Activity::Activity(ActType type, string name, string details, Room* room)
	: _type(type), _name(name), _details(details), _room(room)
{}

Activity::~Activity()
{
}