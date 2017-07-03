/*
* Sim.cpp
*
*
*/
#include "Event.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include "PriorityQueue.h"
#include <iomanip>

void processArrival(Event& aEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable);
void processDeparture(Event& dEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, double& waitTime);

int main(int argc, char** argv)
{
	cout << "Simulation Begins" << endl;
	PriorityQueue<Event> eventPriorityQueue;
	Queue<Event> bankLine;
	bool tellerAvailable = true;
	int customerCount = 0;
	double waitTime = 0;

	//Get input and create events from file
	int num;
	while(cin >> num)
	{
		Event anEvent("A");
		anEvent.setTime(num);
		cin >> num;
		anEvent.setLength(num);
		eventPriorityQueue.enqueue(anEvent);
	}

	//Event loop
	int currentTime = 0;
	while(!eventPriorityQueue.isEmpty())
	{
		//update event priority queue
		Event currentEvent = eventPriorityQueue.peek();
		currentTime = currentEvent.getTime();	//get current time

		if(currentEvent.getType() == "A")	//process arrival
		{
			processArrival(currentEvent, eventPriorityQueue, bankLine, tellerAvailable);
			customerCount++;
		}
		else	//process departure
		{
			processDeparture(currentEvent, eventPriorityQueue, bankLine, tellerAvailable, waitTime);
		}

		//Print
		if(currentEvent.getType() == "A")
		{
			cout << "Processing an arrival event at time:" << right << setw(5) << currentTime << endl;
		}
		else
		{
			cout << "Processing a departure event at time:" << right << setw(4) << currentTime << endl;
		}
	}
	cout << "Simulation Ends" << endl << endl;
	cout << "Final Statistics:  " << endl;
	cout << "	Total number of people processed:  " << customerCount << endl;
	cout << "	Average amount of time spent waiting: " << setprecision(3) << waitTime/customerCount;
}

void processArrival(Event& aEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable)
{
	eventPriorityQueue.dequeue();

	//update bank line
	if(bankLine.isEmpty() && tellerAvailable)
	{
		Event departureEvent("D");
		departureEvent.setTime(aEvent.getTime() + aEvent.getLength());
		eventPriorityQueue.enqueue(departureEvent);
		tellerAvailable = false;
	}
	else
	{
		bankLine.enqueue(aEvent);
	}
}

void processDeparture(Event& dEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, double& waitTime)
{
	eventPriorityQueue.dequeue();

	//update bank line
	if(!bankLine.isEmpty())
	{
		//add into total wait time
		waitTime = waitTime + dEvent.getTime() - bankLine.peek().getTime();

		Event departureEvent("D");
		departureEvent.setTime(dEvent.getTime() + bankLine.peek().getLength());
		bankLine.dequeue();
		eventPriorityQueue.enqueue(departureEvent);
	}
	else
	{
		tellerAvailable = true;
	}
}

