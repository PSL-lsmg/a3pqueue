/*
 * Node.h
 *
 * Class Definition: a singly linked node
 *                   in which the data is of Profile data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: June 2017
 * Last modified on: July 2017
 * Author: Jun Wei(Jason) Li, Priscilla (Fae Yein) Lee
 */

#pragma once
#include "Event.h"

template <class ElementType>
class Node {
    
public:
    ElementType data;     // The data in the node
    Node<ElementType>* next;       // Pointer to next node
    
    // Default Constructors
    // Description: create an empty node
    // Postcondition: pointer to next node is NULL. No data
    Node()
    {
    	next = NULL;
    }

    // Parameterized Constructor
    // Description: Create a node with data
    // Postcondition: pointer to next node is NULL. Data is set based on argument
    Node(ElementType theData)
    {
    	data = theData;
    	next = NULL;
    }

    // Parameterized Constructor
    // Description: Create a node with data and direction to next node
    // Postcondition: pointer to next node is set to the node give. data is set based on arugment
    Node(ElementType theData, Node* theNextNode)
    {
    	data = theData;
    	next = theNextNode;
    }
    
}; // end Node
