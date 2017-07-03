/*
* Sim.cpp
*
* Class Description: Simulates a bank and calculate its customers' wait time.
* 					 In this case, the bank only has 1 teller. It will simulate
*					 the bank line and customers, and then print out the total
*					 customers and the average wait time.
*
* Created on: June 2017
* Last modified on: July 2017
* Author: Jun Wei(Jason) Li, Priscilla (Fae Yein) Lee
*/
#include "Event.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include "PriorityQueue.h"
#include <iomanip>
using namespace std;

// Function prototypes
void processArrival(Event& aEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable);
void processDeparture(Event& dEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable, double& waitTime);

// Description: Bank customers wait time simulation. Print customers' average wait time
int main()
{
	cout << "Simulation Begins" << endl;
	PriorityQueue<Event> eventPriorityQueue;
	Queue<Event> bankLine;
	bool tellerAvailable = true;
	int customerCount = 0;
	double waitTime = 0;

	//Get input and create events from file and enqueue them into priority queue
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
	int currentTime = 0;	//inititalize time
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

		//Display the current task. Print format based on the sample outputs provided from instructor
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
	//Print statistics found from the simulation
	cout << "Final Statistics:  " << endl;
	cout << "	Total number of people processed:  " << customerCount << endl;
	cout << "	Average amount of time spent waiting: " << setprecision(3) << waitTime/customerCount;
}

// Description: Process the arrival event and manipulate the event priority queue and bank line.
void processArrival(Event& aEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable)
{
	eventPriorityQueue.dequeue();

	//update bank line
	if(bankLine.isEmpty() && tellerAvailable)	//directly process the event without putting into bank line
	{
		Event departureEvent("D");	//create new departure event
		departureEvent.setTime(aEvent.getTime() + aEvent.getLength());
		eventPriorityQueue.enqueue(departureEvent);
		tellerAvailable = false;
	}
	else	//put the event into the bank line
	{
		bankLine.enqueue(aEvent);
	}
}

// Description: Process the departure event and manipulate the event priority queue and bank line.
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

