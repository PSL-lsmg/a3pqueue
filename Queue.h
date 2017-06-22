/*
* Queue.h
*
*/

#pragma once
#include <stdexcept>
#include <string>
#include "Event.h"
#include "EmptyDataCollectionException.h"
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
    string EmptyDataCollectionException = "Exception: The queue is empty.";
    
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

    
    int getSize() const;
    
    bool dequeueAll();
    
    void printQueue();
    
    
}; // end Queue
