/*
* Queue.h
*
*/

#pragma once
#include <stdexcept>
#include <string>
#include "Event.h"
using namespace std;
#define SIZE 100

class Queue
{
private:
	Event array[SIZE];
	int numOfEle;
	int front;
	int back;

public:
	Queue();
	void enqueue(const Event& e);
	bool dequeue();
	bool isEmpty() const;
	int getSize() const;
	Event peek() const; //throw (EmptyQueueException);
	bool dequeueAll();
	void printQueue();
};
