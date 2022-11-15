/*
* Queue.cpp
* 
* Description: Queue ADT class with several simple public interface functions.         
* Author: Daniel Tolsky
* Date: Last modified: Nov. 2022
*/

#include "Queue.h"
using namespace std;

// Default constructor
template <class ElementType>
Queue<ElementType>::Queue()
{ }

// Copy constructor
template <class ElementType>
Queue<ElementType>::Queue(const Queue& other)
{ 
    data = other.data;
}

/******* Start of Queue Public Interface *******/

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return data.empty();
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement)
{
    unsigned int tempSize = data.size();
    data.push(newElement);

    if (tempSize != data.size())
    {
        return true;
    }
    return false;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue()
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException("Exception in dequeue(): Data collection is empty.");
    }
    data.pop();
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException("Exception in peek(): Data collection is empty.");
    }
    return data.front();
}

/******* End of Queue Public Interface *******/

// Destructor
template <class ElementType>
Queue<ElementType>::~Queue()
{ 
    // empty because no dynamic memory was allocated
}