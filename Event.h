/*
* Event.h
*
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
	Event();
	Event(string type);
	void setType(string type);
	void setTime(int time);
	void setLength(int length);
	string getType();
	int getTime();
	int getLength();

};
