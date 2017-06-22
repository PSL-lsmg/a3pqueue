/*
* Queue.cpp
*
*
*/

#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

template <class ElementType>
Queue<ElementType>::Queue()
{
	numOfEle = 0;
	front = -1;
	back = -1;
}

template <class ElementType>
int Queue<ElementType>::getElementCount() const
{
    return getElementCount();
}

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

// need to figure out how to use exception???
template <class ElementType>
ElementType Queue<ElementType>::peek() const throw (class EmptyDataCollectionException)
{
    if (numOfEle == 0) {
        throw EmptyDataCollectionException;
    }
    return array[front];
}


template <class ElementType>
int Queue<ElementType>::getSize() const
{
	return numOfEle;
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
