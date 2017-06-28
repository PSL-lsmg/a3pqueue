/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list
 *                   in which the data is of Profile data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on:
 * Author:
 */

#pragma once
#include "Queue.h"
#include "Event.h"
#include "Node.cpp"

class Node {
    
public:
    // Public data members - Why are the data members public?
    Event data;     // The data in the node
    Node* next;       // Pointer to next node
    
    // Constructors
    Node();
    Node(Event theData);
    Node(Event theData, Node* theNextNode);
    
}; // end Node
