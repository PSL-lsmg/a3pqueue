/*
* Event.cpp
* 
* Class Description: Models an event that has time, duration and type.
* Class Invariant: Time, length and type can be modified.
*
*
* Last modified on: July 2017
* Author: Jun Wei(Jason) Li, Priscilla (Fae Yein) Lee
*/

#include "Event.h"
#include <string>
#include <iostream>

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
// Postcondition: time and length will be 0. Type will be set based on argument
Event::Event(string aType)
{
	time = 0;
	length = 0;
	type = aType;
}

// Getters and setters
// Description: set the time of the event
void Event::setTime(int t)
{
	time = t;
}

// Description: set the duration of the event
void Event::setLength(int l)
{
	length = l;
}

// Description: set the type of the event
void Event::setType(string t)
{
    type = t;
}

// Description:: return the time of the event
int Event::getTime() const
{
	return time;
}

// Description: return the duration of the event
int Event::getLength() const
{
	return length;
}

// Description:: return the type of the event
string Event::getType() const
{
	return type;
}

// Description: insertion operator.
//				return the ostream with type, time and length of the event
ostream& operator<< (ostream& os, const Event& e)
{
	os << e.getType() << "/" << e.getTime() << "/" << e.getLength();
	return os;
}

// Description: Greater than operator. Compare the time of the events
//				return true if "this" time is greater than "rhs" time.
bool Event::operator>(const Event & rhs)
{
	if(time < rhs.time)
	{
		return true;
	} 
	else if( time == rhs.time )
	{
		if(type == "A")
		{
			return true;
		}
	}

	return false;
}
