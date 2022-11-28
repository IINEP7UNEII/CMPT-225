/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 *                    Based on the Hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing.             
 * Class Invariant: Data collection with the following characteristics:
 *                  - Each element is unique (no duplicates).
 *
 * Author: Daniel Tolsky
 * Date: Last modified: Dec. 2022
 */

#include "List.h"

// Constructor
List::List(unsigned int (*hFcn)(string))
{
    hashTable = new Member*[CAPACITY];
}

// Description: Returns the total element count currently stored in List.
// Postcondition: List remains unchanged.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// Description: Insert an element.
// NOTE: You do not have to expand the hashTable when it is full. 
// Precondition: newElement must not already be in in the List.  
// Postcondition: newElement inserted and elementCount has been incremented. 
// Exception: Throws UnableToInsertException if we cannot insert newElement in the List.
//            For example, if the operator "new" fails, or hashTable is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the List.  
void List::insert(Member& newElement)
{

}

// Description: Returns a pointer to the target element if found.
// Postcondition: List remains unchanged.
// Exception: Throws EmptyDataCollectionException if the List is empty.
// Exception: Throws ElementDoesNotExistException if newElement is not found in the List.
Member* List::search(Member& target) const
{
    if (elementCount == 0)
    {
        throw EmptyDataCollectionException("search(): List is empty");
    }
    if (elementCount >= CAPACITY)
    {
        throw ElementDoesNotExistException("search(): Unable to locate element in the List");
    }

    for (unsigned int count = 0; count < CAPACITY; ++count)
    {
        if (target = hashTable[count])
        {

        }
    }
}

// Description: Prints all elements stored in the List (unsorted).
// Postcondition: List remains unchanged.
void List::printList() const
{

}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    delete[] hashTable;
}
// end List.cpp