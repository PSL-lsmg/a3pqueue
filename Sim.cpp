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

int main()
{
	cout << "start" << endl;
	Event a("A");
	a.setTime(5);
	a.setLength(5);
	cout << a << endl;

	Event d("D");
	d.setTime(a.getTime() + a.getLength());

	Queue <Event> q;
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

	cout << "end" << endl;
}
