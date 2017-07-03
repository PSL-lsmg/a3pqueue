/*
* Event.h
* 
* Class Description: Models an event that has time, duration and type.
* Class Invariant: Time, length and type can be modified.
*
*
* Last modified on: July 2017
* Author: Jun Wei(Jason) Li, Priscilla (Fae Yein) Lee
*/

#pragma once
#include <string>
using namespace std;

class Event{

private:
	string type;
	int time;
	int length;

public:
	// Default Constructor
	// Description: Create an empty event with no type, no time, no length
	// Postcondition: time and length will be 0 and type will be ""
	Event();

	// Parmeterized Constructor
	// Description: Create an event with no time and length and a specific type
	// Postcondition: time and length will be 0. Type will be set based on argument
	Event(string type);

	// Getters and setters
	// Description: set the type of the event
	void setType(string type);

	// Description: set the time of the event
	void setTime(int time);

	// Description: set the length of the event
	void setLength(int length);

	// Description:: return the type of the event
	string getType() const;

	// Description:: return the time of the event
	int getTime() const;

	// Description:: return the length of the event
	int getLength() const;

	// Description: insertion operator.
	//				return the ostream with type, time and length of the event
	friend ostream& operator<< (ostream& os, const Event& e);

	// Description: Greater than operator. Compare the time of the events
	//				return true if "this" time is greater than "rhs" time.
	bool operator>(const Event & rhs);
};
// end of Event.h
