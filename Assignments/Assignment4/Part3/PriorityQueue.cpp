/*
* PriorityQueue.cpp
* 
* Description: Priority Queue class using the binary heap class in the previous section
* Class Invariant: Always a Priority Queue
* Author: Daniel Tolsky
* Date: Last modified: Nov. 2022
*/ 

#include "PriorityQueue.h"
using namespace std;

// Defualt Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{ }

// Copy constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(PriorityQueue& other)
{
    heap = BinaryHeap::BinaryHeap(other.heap);
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty()const
{
    if (heap.isEmpty())
    {
        return true;
    }
    return false;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType& newElement)
{
    return heap.insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue()
{
    if (heap.isEmpty())
    {
        throw EmptyDataCollectionException("Exception in dequeue(): Data collection is empty.");
    }
    else
    {
        heap.remove();
    }
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& PriorityQueue<ElementType>::peek()const
{
    if (heap.isEmpty())
    {
        throw EmptyDataCollectionException("Exception in peek(): Data collection is empty.");
    }
    else
    {
        return heap.retrieve();
    }
}

// Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
    heap.~BinaryHeap();
}