/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Daniel Tolsky
 * Date of last modification: Oct. 2022
 */
#include <iostream>
#include "Dictionary.h"
using namespace std;

Dictionary::Dictionary() // Default constructor
: keyValuePairs(nullptr)
{ }

Dictionary::~Dictionary() // Destructor 
{
    keyValuePairs->~BST();
}

// Dictionary operations:
unsigned int Dictionary::getElementCount() const
{
    return keyValuePairs->getElementCount();
}
    
// Description: Puts "newElement" (association of key-value) into the Dictionary.
// Precondition: "newElement" does not already exist in the Dictionary.
//               This is to say: no duplication allowed.
// Exception: Throws ElementAlreadyExistsException if "newElement" already exists in the Dictionary.
void Dictionary::put(WordPair& newElement)
{
    keyValuePairs->insert(newElement);
}

// Description: Gets "newElement" (i.e., the associated value of a given key) from the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws ElementDoesNotExistException if the key is not found in the Dictionary.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
WordPair& Dictionary::get(WordPair& targetElement) const
{
    return keyValuePairs->retrieve(targetElement);
}

// Description: Prints the content of the Dictionary.
void Dictionary::displayContent(void visit(WordPair&)) const
{
    cout << "\n\n";
    keyValuePairs->traverseInOrder(visit); //gigure our printing
}