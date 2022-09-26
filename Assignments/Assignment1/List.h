/*
 * List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - The capacity of tatal elemrnts in the database in 5
 *
 * Author: AL
 * Last modified: Sept. 2022
 */

#ifndef LIST_H
#define LIST_H

#include <string>
#include "Member.h"

class List
{
/* You cannot change this file (i.e., the definition of this class). */

private:

    constexpr static const int CAPACITY = 5; 
    Member * elements = NULL;                // Data structure of elements
    unsigned int elementCount = 0;           // Number of elements in the data structure

    void clear();

public:

    // Default constructor
    List();
	
    // Destructor
    // Description: Destruct a List object, releasing heap-allocated memory.
    ~List();

    // Description: Returns the total number of elements currently stored in List.
    unsigned int getElementCount() const;

    // Description: Insert an element.
    // Precondition: newElement must not already be in data collection.  
    // Postcondition: newElement inserted in its proper place in List
    //                and elementCount has been incremented.   
    bool insert( Member& newElement );

    // Description: Remove an element. 
    // Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
    //                and elementCount has been decremented.	
    bool remove( Member& toBeRemoved );
	
    // Description: Remove all elements.
    // Postcondition: List is back to the state it was right after being constructed.
    void removeAll();
   
    // Description: Search for target element.
    //              Returns a pointer to the element if found,
    //              otherwise, returns NULL.
    Member* search( Member& target );
	
    // Description: Prints all elements stored in List by descending order of search key.
    // Time Efficiency: O(n)
    void printList();

}; // end List.h
#endif	