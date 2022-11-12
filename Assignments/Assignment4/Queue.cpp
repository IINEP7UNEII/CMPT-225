#include "Queue.h"
#include <queue>
using namespace std;

template <typename ElementType>
class Queue
{
    // Default constructor
    Queue()
    { }

    // Copy constructor
    Queue(Queue& oldQueue)
    { 
        data = oldQueue;
    }

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const
    {
        return data.empty();
    }
    
    // Description: Inserts newElement at the "back" of this Queue 
    //              (not necessarily the "back" of this Queue's data structure) 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType& newElement)
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
    void dequeue()
    {
        if (isEmpty())
        {
            throw EmptyDataCollectionException("Data collection is empty.");
        }
        data.pop();
    }

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType& peek() const
    {
        if (isEmpty())
        {
            throw EmptyDataCollectionException("Data collection is empty.");
        }
        return data.front();
    }

    // Destructor
    ~Queue()
    { 
        // empty because no dynamic memory was allocated
    }
};