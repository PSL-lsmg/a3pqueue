/*
* Queue.cpp
*
*
*/

#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

Queue::Queue()
{
	numOfEle = 0;
	front = -1;
	back = -1;
}

void Queue::enqueue(const Event& e)
{
	if(numOfEle == 0)
	{
		front = 0;
		back = 0;
	}
	else
	{
		back++;
	}
	array[back] = e;
	numOfEle++;
}

bool Queue::dequeue()
{
	if(numOfEle == 0)
	{
		return false;
	}
	front++;
	numOfEle--;
	return true;
}

bool Queue::isEmpty() const
{
	return (numOfEle == 0);
}

int Queue::getSize() const
{
	return numOfEle;
}

Event Queue::peek() const //throw (EmptyQueueException);
{

	return array[front];
}

bool Queue::dequeueAll()
{
	if(numOfEle == 0)
	{
		return false;
	}
	numOfEle = 0;
	return true;
}

void Queue::printQueue()
{
	cout << "****" << endl;
	for(int i = front; i <= back; i++)
	{
		cout << array[i] << endl;
	}
	cout << "****" << endl;
}
