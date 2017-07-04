/*
 * Queue.h
 * Class Description: A double headed singly linked queue. First in first out.
 * Class Invariant: Elements are not sorted.
 *                  First element in, first element out
 *
 * Created on: June 2017
 * Last modified on: July 2017
 * Author: Jason Li, Priscilla (Fae Yein) Lee
 */

#pragma once
#include <string>
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Node.h"
#include <iostream>
using namespace std;

template <class ElementType>
class Queue {
    
private:
    
    // We must complete this section.
    int numOfEle; // Num of elements in Queue
    Node<ElementType> *head; // Pointer to first node in queue
    Node<ElementType> *tail; // Pointer to last node in queue
    
public:
    
    // Let's put our constructor(s) and destructor (if any) ***here***.
    Queue<ElementType>();
    ~Queue<ElementType>();
    
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
    
}; // end Queue

// Default Constructor
// Description: Create a queue with no element
template <class ElementType>
Queue<ElementType>::Queue()
{
    numOfEle = 0;
    head = NULL;
    tail = NULL;
}

// Destructor
template <class ElementType>
Queue<ElementType>::~Queue()
{
    while( head != NULL )
    {
        Node<ElementType>* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = NULL;
    numOfEle = 0;
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
    
    //add false condition
    
    //inserts node @ end
    Node<ElementType>* newNode = new Node<ElementType>(e);
    if(head == NULL)
    {
        // If no elements, insert node at beginning of linked list
        head = newNode;
    }
    else
    {
        tail -> next = newNode;
    }
    tail = newNode;
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
    //deletes node @ front
    Node<ElementType> *nodeToDelete;
    if (head == NULL){
        return false;
    }
    else {
        nodeToDelete = head;
        head = head -> next;
        nodeToDelete -> next = NULL;
        delete nodeToDelete;
        nodeToDelete = NULL;
    }
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
    if (head == NULL) {
        throw EmptyDataCollectionException("Queue is empty");
    }
    return head->data;
}
