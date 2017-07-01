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
#include "Event.h"

template <class ElementType>
class Node {
    
public:
    // Public data members - Why are the data members public?
    ElementType data;     // The data in the node
    Node<ElementType>* next;       // Pointer to next node
    
    // Constructors
    Node()
    {
    	next = NULL;
    }
    Node(ElementType theData)
    {
    	data = theData;
    	next = NULL;
    }
    Node(ElementType theData, Node* theNextNode)
    {
    	data = theData;
    	next = theNextNode;
    }
    
}; // end Node
