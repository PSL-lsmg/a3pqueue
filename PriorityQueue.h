/*
 * PriorityQueue.h
 *
 */

#include "Event.h"
#include "EmptyDataCollectionException.h"
using namespace std;
#define SIZE 100


template <class ElementType>
class PriorityQueue {
    
private:
    
    // We must complete this section.
    Event array[SIZE];
    int numOfEle;
    int front;
    int back;
//    string EmptyDataCollectionException = "Exception: The queue is empty.";
    
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
    
    int getSize() const;
    
    bool dequeueAll();
    
    void printQueue();
    
}; // end PriorityQueue
