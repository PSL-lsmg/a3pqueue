/*
 * PriorityQueue.h
 * 
 * Class Description: Model a priority queue with high priority element to leave first.
 *                     It is a circular array based priority queue.
 * Class Invariant: It is no expandable. Higher priority elements are at the front.
 *                  Lower priority elements are at the back.
 * 
 * Created on: June 2017
 * Last modified on: July 2017
 * Author: Jason Li, Priscilla (Fae Yein) Lee
 */

#include "Event.h"
#include "EmptyDataCollectionException.h"
#include <string>
#include <iostream>

using namespace std;
#define SIZE 100

template <class ElementType>
class PriorityQueue {
    
private:
    
    // We must complete this section.
    ElementType array[SIZE];
    int numOfEle; //element count
    int front;
    int back;

    // Description: enqueue the element when the front is greater/equal to back. Necessary because it is circular
    // Postcondition: New element is added. Elements are sorted.
    void enqueueFrontGEBack(const ElementType& newElement); //enqueue when front is great/equal to back

    // Description: enqueue when the front is less than back. Necessary because it is circular
    // Postcondition: New element is added. Elements are sorted.
    void enqueueFrontLTBack(const ElementType& newElement); //enqueue when front is less than back
    
public:
    
    // Let's put our constructor(s) and destructor (if any) ***here***.
    PriorityQueue<ElementType>();
    
    /******* Public Interface - START - *******/
    
    // Description: Returns the number of elements in the Priority Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;
    
    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const ElementType& newElement);
    
    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();
    
    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(class EmptyDataCollectionException);
    
    /******* Public Interface - END - *******/
    
    // Let's feel free to add other private helper methods to our Priority Queue class.
    
}; // end PriorityQueue

// Default Constructor
// Description: Create an empty priority queue
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
    return numOfEle;
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
    //check if queue is full
    if(numOfEle == SIZE)
    {
        return false;
    }

    //initial when queue is empty
    if(front == -1 && back == -1)
    {
        front++;
        back++;
        array[back] = newElement;
    }
    else
    { 
        if(back == SIZE-1) //back is at the end of the array
        {
            enqueueFrontLTBack(newElement);
        }
        else //back is anywhere else other than end of the array
        {
            if(front <= back)
            {
                enqueueFrontLTBack(newElement);
            }
            else
            {
                enqueueFrontGEBack(newElement);
            }
        }
    }

    numOfEle++;
    return true;
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
    if(front == SIZE)
    {
        front = 0;
    }
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
    if (numOfEle == 0){
        throw EmptyDataCollectionException("Queue is empty");
    }
    
    return array[front];
}

// Description: enqueue the element when the front is less than to back. Necessary because it is circular
// Postcondition: New element is added. Elements are sorted.
template <class ElementType>
void PriorityQueue<ElementType>::enqueueFrontLTBack(const ElementType& newElement)
{
    //Find the best position for the new element.
    int position = front;
    for(int i = back; i >= front; i--)
    {   
        if(array[i] > newElement) 
        {
            position = i+1;
            break;
        }
    }
    //Set new the back position depending on where the current back position is
    if(back == SIZE-1)  //back is at the end of the array
    {
        back = 0;
        array[back] = array[SIZE-1];
    }
    else   //back is not at the end of the array
    {
        back++;
    }
    //shift elements to the right
    for(int j = back; j > position; j--)
    {
        array[j] = array[j-1];
    }
    array[position] = newElement;
}

// Description: enqueue when the front is greater/equal to back. Necessary because it is circular
// Postcondition: New element is added. Elements are sorted.
template <class ElementType>
void PriorityQueue<ElementType>::enqueueFrontGEBack(const ElementType& newElement)
{
    //Find the best position for the new element.
    int position = front;
    bool found = false; //use to prevent further scanning if position is found in back -> 0
    //scan from back -> 0
    for(int i = back; i >= 0; i--)
    {
        if(array[i] > newElement)
        {
            position = i+1;
            found = true;
            break;
        }
    }
    //scan from end of array -> front
    for(int j = SIZE-1; j >= front && found == false; j--)
    {
        if(array[j] > newElement)
        {
            if(j == SIZE-1)
            {
                position = 0;
            }
            else
            {
                position = j+1;
            }
            break;
        }
    }
    //shift the elements depending on where the position is.
    back++;
    if(position < back)
    {
        //shift elements in [position, back]
        for(int j = back; j > position; j--)
        {
            array[j] = array[j-1];
        }
    }
    else
    {
        //shift elements in [0, back] then shift [position, end]
        for(int j = back; j > 0; j--)
        {
            array[j] = array[j-1];
        }
        array[0] = array[SIZE-1];
        for(int k = SIZE-1; k > position; k--)
        {
            array[k] = array[k-1];
        }
    }
    array[position]= newElement;
}