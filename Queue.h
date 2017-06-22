/*
* Queue.h
*
*/

#pragma once
#include <stdexcept>
#include <string>
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
using namespace std;
#define SIZE 100


template <class ElementType>
class Queue {
    
private:
    
    // We must complete this section.
    Event array[SIZE];
    int numOfEle;
    int front;
    int back;
    //string EmptyDataCollectionException = "Exception: The queue is empty.";
    
public:
    
    // Let's put our constructor(s) and destructor (if any) ***here***.
    Queue<ElementType>();
    
    /******* Public Interface - START - *******/
    
    // Description: Returns the number of elements in the Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;
    
    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Adds newElement to the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const ElementType& newElement);
    
    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();
    
    // Description: Returns (a copy of) the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(class EmptyDataCollectionException);
    
    /******* Public Interface - END - *******/
    
    // Let's feel free to add other private helper methods to our Queue class.

    
    bool dequeueAll();
    
    void printQueue();
    
    
}; // end Queue

template <class ElementType>
Queue<ElementType>::Queue()
{
	numOfEle = 0;
	front = -1;
	back = -1;
}

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int Queue<ElementType>::getElementCount() const
{
    return numOfEle;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return (numOfEle == 0);
}

// Description: Adds newElement to the "back" of this Queue
//              (not necessarily the "back" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& e)
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
    return true;
}

// Description: Removes the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::dequeue()
{
	if(numOfEle == 0)
	{
		return false;
	}
	front++;
	numOfEle--;
	return true;
}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType Queue<ElementType>::peek() const throw (EmptyDataCollectionException)
{
    if (numOfEle == 0) {
        throw EmptyDataCollectionException("Queue is empty");
    }
    return array[front];
}


template <class ElementType>
bool Queue<ElementType>::dequeueAll()
{
	if(numOfEle == 0)
	{
		return false;
	}
	numOfEle = 0;
	return true;
}

template <class ElementType>
void Queue<ElementType>::printQueue()
{
	cout << "****" << endl;
	for(int i = front; i <= back; i++)
	{
		cout << array[i] << endl;
	}
	cout << "****" << endl;
}
