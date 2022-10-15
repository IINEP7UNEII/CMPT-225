/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Daniel Tolsky
 * Date: 14/10/2022
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue()
{
    elements = new int[INITIAL_CAPACITY];
}

// Description: Inserts element x at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int x) 
{
    if (elementCount >= capacity)
    {
        expand();
    }

    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;    
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() 
{
    unsigned int tempCount = elementCount;
    if ((elementCount <= (capacity / 4)) && ((capacity / 4) > INITIAL_CAPACITY))
    {
        shrink();
    }

    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const 
{
    return elements[frontindex];
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const 
{
    return elementCount == 0;
}

Queue::~Queue()
{
    delete[] elements;
}

void Queue::expand()
{
    unsigned int newCap = capacity * 2;
    int* copy = new int[newCap];

    for (int count = 0; count < elementCount; ++count) 
    {
        int index = (frontindex + count) % capacity;
        copy[count] = elements[index];
    }

    frontindex = 0; //maybe problem
    backindex = elementCount - 1; //maybe problem
    delete[] elements;
    elements = copy;
    capacity = newCap;
}

void Queue::shrink()
{
    unsigned int newCap = capacity / 2;
    int* copy = new int[newCap];

    for (int count = 0; count < elementCount; ++count) 
    {
        int index = (frontindex + count) % capacity;
        copy[count] = elements[index];
    }

    frontindex = 0; //maybe problem
    backindex = elementCount - 1; //maybe problem
    delete[] elements;
    elements = copy;
    capacity = newCap;
}
// continue 5, 6 review 4