/*
 * PriorityQueue.cpp
 *
 */

#include "PriorityQueue.h"
#include <string>
#include <iostream>

using namespace std;

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
    numOfEle = 0;
    front = -1;
    back = -1;
}
    
/******* Public Interface - START - *******/

// Description: Returns the number of elements in the Priority Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const
{
    return getElementCount();
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
    return (numOfEle == 0);
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement)
{
    //sort while entering?
    // arrival first, depature second if given same time
    
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::dequeue()
{
    if (numOfEle == 0) {
        return false;
    }
    front++;
    numOfEle--;
    return true;
    // if elements are sorted upon insert, they can just be dequeued in order here
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(class EmptyDataCollectionException)
{
//    if (numOfEle == 0){
//        throw EmptyDataCollectionException;
//    }
    // do we need this if we have the class?
    
    return array[front];
}

template <class ElementType>
int PriorityQueue<ElementType>::getSize() const
{
    return numOfEle;
}


template <class ElementType>
bool PriorityQueue<ElementType>::dequeueAll()
{
    if(numOfEle == 0)
    {
        return false;
    }
    numOfEle = 0;
    return true;
}

template <class ElementType>
void PriorityQueue<ElementType>::printQueue()
{
    cout << "****" << endl;
    for(int i = front; i <= back; i++)
    {
        cout << array[i] << endl;
    }
    cout << "****" << endl;
}

