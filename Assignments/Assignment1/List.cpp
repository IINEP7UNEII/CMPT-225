/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - The capacity of tatal elemrnts in the database in 5
 *
 * Author: Daniel Tolsky
 * Last modified: Sept. 2022
 */
#include <iostream>
#include <string>
#include "List.h"

void List::clear()
{
    List::~List();
    List();
}

// Default constructor
List::List()
: elementCount(0)
{ 
    elements = new Member[CAPACITY];
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    delete[] elements;
}

// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted in its proper place in List
//                and elementCount has been incremented.   
bool List::insert( Member& newElement )
{
    if (elementCount < 5)
    {
        elements[elementCount] = newElement;
        ++elementCount;
        return true;
    }
    else
    {
        return false;
    }
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
//                and elementCount has been decremented.	
bool List::remove( Member& toBeRemoved )
{
    for (unsigned int count = 0; count < elementCount; ++count)
    {
        if (elements[count] == toBeRemoved)
        {
            --elementCount;
            return true;
        }
    }
    return false;
}

// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll()
{
    clear();
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search( Member& target )
{
    for (unsigned int count = 0; count < elementCount; ++count)
    {
        if (elements[count] == target)
        {
            return &elements[count];
        }
    }
    return nullptr;
}

// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)
void List::printList()
{
    for (unsigned int count = 0; count < elementCount; ++count)
    {
        cout << elements[count].getName() << ", "
        << elements[count].getPhone() << ", "
        << elements[count].getEmail() << ", "
        << elements[count].getCreditCard() << endl;
    }
}
// end of List.cpp