/*
* Event.cpp
*
*/

#include "Event.h"
#include <string>
#include <iostream>

using namespace std;

// Default Constructor
// Description: Create an empty event with no type, no time, no length
// Postcondition: time and length will be 0 and type will be ""
Event::Event()
{
	time = 0;
	length = 0;
	type = "";
}

// Parmeterized Constructor
// Description: Create an event with no time and length and a specific type
// Precondition: "A" for arrival type. "D" for departure type
// Postcondition: time and length will be 0. Type will be A (arrival) or D (departure)
Event::Event(string aType)
{
	time = 0;
	length = 0;
	type = aType;
}


void Event::setTime(int t)
{
	time = t;
}

void Event::setLength(int l)
{
	length = l;
}

void Event::setType(string t)
{
    // check that input is either A or D
    type = t;
}

int Event::getTime() const
{
	return time;
}

int Event::getLength() const
{
	return length;
}

string Event::getType() const
{
	return type;
}

ostream& operator<< (ostream& os, const Event& e)
{
	os << e.getType() << "/" << e.getTime() << "/" << e.getLength();
	return os;
}
