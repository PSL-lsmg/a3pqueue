/*
 * Queue.h
 *
 */

#pragma once
#include <stdexcept>
#include <string>
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Node.cpp"
#include <iostream>
using namespace std;
#define SIZE 100


template <class ElementType>
class Queue {
    
private:
    
    // We must complete this section.
    int numOfEle; // Num of elements in Queue
//    int front;
//    int back;
    Node *head; // Pointer to first node in queue
    Node *tail; // Pointer to last node in queue
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
    head = NULL;
    tail = NULL;
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
    Node* newNode = new Node(e);
    if(head == NULL)
    {
        // If no elements, insert node at beginning of linked list
        head = newNode;
    }
    else
    {
        Node* current = head; //anchor head
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = newNode;
        tail = newNode;
    }
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
    
    if (head != NULL){
        Node *nodeToDelete = head; //Anchor head
        head = head -> next;
        nodeToDelete -> next = NULL;
        delete nodeToDelete;
        nodeToDelete = NULL;
    }
    else {
        return false;
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


template <class ElementType>
bool Queue<ElementType>::dequeueAll()
{
    if(numOfEle == 0)
    {
        return false;
    }
    while (head != NULL){
        Node *nodeToDelete = head; //Anchor head
        head = head -> next;
        // Not sure if we need this in order to get it to traverse, otherwise it will stop after the first deleted node
//        nodeToDelete -> next = NULL;
        delete nodeToDelete;
        nodeToDelete = NULL;
    }
    
    numOfEle = 0;
    return true;
}

template <class ElementType>
void Queue<ElementType>::printQueue()
{
    cout << "****" << endl;
    Node *current = head;
    for (int i = 0; i < numOfEle; i++) {
        cout << current->data << endl;
        current = current->next;
    }
    delete current;
    current = NULL;
    cout << "****" << endl;
}
