/*
* Queue.h
*
* Description: Queue ADT class with several simple public interface functions.
* Author: Daniel Tolsky
* Date: Last modified: Nov. 2022
*/ 

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include "Event.h"
#include "EmptyDataCollectionException.h"

// Class Invariant:  FIFO or LILO order
template <class ElementType>
class Queue
{
    private:
        std::queue <ElementType> data;

    public:
        // Default constructor
        Queue();

        // Copy constructor
        Queue(const Queue&);

        /******* Start of Queue Public Interface *******/

        // Description: Returns true if this Queue is empty, otherwise false.
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of this Queue's data structure) 
        //              and returns true if successful, otherwise false.
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newElement);
        
        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of this Queue's data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1)
        void dequeue(); 

        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of this Queue's data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() const;

        /******* End of Queue Public Interface *******/

        // Destructor
        virtual ~Queue();
};
#endif