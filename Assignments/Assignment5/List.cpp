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
: hashFcn(hFcn), hashTable(new Member*[CAPACITY])
{ }

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
    for (unsigned int count = 0; count < CAPACITY; ++count)
    {
        if (newElement == *hashTable[count])
        {
            throw ElementAlreadyExistsException("insert(): Unable to insert new elements as element already exists and the list");
        }
    }

    if (elementCount == 0) 
    {
        hashTable = new Member*[CAPACITY];
        if (hashTable == nullptr)
        {
            return; //throw 
        }

        collisions = new unsigned int[CAPACITY];
        if (collisions == nullptr)
        {
            return; //throw 
        } 

        for (unsigned int count = 0; count < CAPACITY; ++count) 
        {
            hashTable[count] = nullptr;  // Initialize array hashTable
            collisions[count] = 0;  // Initialize array collisions
        }
    }

    if (elementCount >= CAPACITY)
    {
        throw UnableToInsertException("insert(): Unable to insert new elements as list is at maximum capacity");
    }
    
    unsigned int hashIndex = (*hashFcn)(newElement);
    hashTable[hashIndex] = newElement;
    collisions[hashIndex]++; 
    elementCount++;
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

    for (unsigned int count = 0; count < CAPACITY; ++count)
    {
        if (target == *hashTable[count])
        {
            return hashTable[count];
        }
    }
    throw ElementDoesNotExistException("search(): Unable to locate element in the List");
    return nullptr;
}

// Description: Prints all elements stored in the List (unsorted).
// Postcondition: List remains unchanged.
void List::printList() const
{
    for (unsigned int count = 0; count < elementCount; ++count)
    {
        cout << hashTable[count] << '\n';
    }
}

// Description: Prints an histogram showing distribution of hash indices over the hash table.	
void List::histogram() 
{
    cout << endl << "Histogram showing distribution of hash indices over the hash table: " << endl;
    for (unsigned int count1 = 0; count1 < CAPACITY; ++count1) 
    {
        cout << "At hashTable[" << count1 << "]: ";
        for (unsigned int count2 = 0; count2 < collisions[count1]; ++count2) 
        {
            cout << "*";
            cout << endl;
        }
    } 
    return;
}

// Description: Prints various stats.	
void List::printStats() 
{
    unsigned int emptyCell = 0;
    unsigned int oneProbe = 0;
    unsigned int moreProbes = 0;

    cout << endl << "In the process of inserting " << this->elementCount << " elements, number of collisions ... " << endl;

    for (unsigned int count = 0; count < CAPACITY; ++count) 
    {
        if (collisions[count] == 0) 
        {
            emptyCell++;
        }
        else if (collisions[count] == 1)
        {
            oneProbe++;
        }
        else 
        {
            if (collisions[count] > 1) 
            {
                moreProbes++;
                cout << "at hashTable[" << count << "] = " << collisions[count] << endl;
            } 
        }
    }
        
    cout << endl << "There are " << emptyCell << " empty cells." << endl;
    cout << oneProbe << " elements inserted without collisions." << endl;
    cout << "There were " << oneProbe << " collisions." << endl;
    
    return;
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    if (hashTable != nullptr) 
    { 
        delete[] hashTable;
        hashTable = nullptr;
    }

    if (collisions != nullptr) 
    { 
        delete[] collisions;
        collisions = nullptr;
    }	
    hashFcn = nullptr;
}
// end List.cpp