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
#include <fstream>

void processArrival(Event& aEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable);
void processDeparture(Event& dEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable);

int main(int argc, char** argv)
{
	cout << "start" << endl;
	cout << "****TESTING QUEUE****" << endl;
	Event a("A");
	a.setTime(5);
	a.setLength(5);
	cout << a << endl;

	Event d("D");
	d.setTime(a.getTime() + a.getLength());

	Queue<Event> q;
	q.enqueue(a);
	q.enqueue(d);
	q.printQueue();

	q.dequeue();
	q.printQueue();

	if(q.isEmpty())
	{
		cout << "Empty" << endl;
	}
	else
	{
		cout << "Not empty" << endl;
	}

	cout << q.peek() << endl;
	cout << "size: " << q.getElementCount() << endl;

	q.dequeue();
	try
	{
		q.peek();
	}
	catch(EmptyDataCollectionException& e)
	{
		cout << e.what() << endl;
	}

	cout << "****TESTING PRIORITY QUEUE****" << endl;
	PriorityQueue<Event> pq;
	Event one("A");
	one.setTime(1);
	Event two("A");
	two.setTime(2);
	Event three("A");
	three.setTime(3);
	Event four("A");
	four.setTime(4);
	Event five("A");
	five.setTime(5);
	pq.enqueue(one);
	pq.enqueue(four);
	pq.enqueue(three);
	pq.enqueue(two);
	pq.printQueue();
	pq.dequeue();
	pq.dequeue();
	pq.dequeue();
	pq.printQueue();
	pq.enqueue(four);
	pq.printQueue();
	pq.enqueue(three);
	pq.printQueue();
	pq.enqueue(two);
	pq.printQueue();
	pq.enqueue(five);
	pq.printQueue();
	if(!pq.enqueue(five))
	{
		cout << "failed" << endl;
	}
	pq.printQueue();
	pq.dequeue();
	pq.dequeue();
	pq.dequeue();
	pq.dequeue();
	Event leave("D");
	leave.setTime(1);
	pq.enqueue(leave);
	pq.printQueue();

	cout << "****TESTING BANK PROGRAM****" << endl;
	cout << "Simulation Begins" << endl;
	PriorityQueue<Event> eventPriorityQueue;
	Queue<Event> bankLine;
	bool tellerAvailable = true;
	int customerCount = 0;

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
	eventPriorityQueue.printQueue();

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
			processDeparture(currentEvent, eventPriorityQueue, bankLine, tellerAvailable);
		}

		//Print
		if(currentEvent.getType() == "A")
		{
			cout << "Processing an arrival event at time:	" << currentTime << endl;
		}
		else
		{
			cout << "Processing a departure event at time:	" << currentTime << endl;
		}
	}
	cout << "Final Statistics:" << endl;
	cout << "		Total number of people processed:	" << customerCount << endl;
	cout << "		Average amount of time spent waiting:	" << endl;


	cout << "end" << endl;
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

void processDeparture(Event& dEvent, PriorityQueue<Event>& eventPriorityQueue, Queue<Event>& bankLine, bool& tellerAvailable)
{
	eventPriorityQueue.dequeue();

	//update bank line
	if(!bankLine.isEmpty())
	{
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

