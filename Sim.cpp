/*
* Sim.cpp
*
*
*/
#include "Event.h"
#include <string>
#include <iostream>

int main()
{
	cout << "start" << endl;
	Event a("A");
	a.setTime(5);
	cout << a.getTime() << endl;
	


	cout << "end" << endl;
}
