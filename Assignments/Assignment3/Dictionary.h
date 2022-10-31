/*
 * Dictionary.h
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Daniel Tolsky
 * Date of last modification: Oct. 2022
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "BST.h"

class Dictionary 
{
    private:
        /* You cannot change the following data member of this class. */
        BST* keyValuePairs = nullptr;                  
    
    public:
        /* You cannot change the prototype of the public methods of this class.
        Remember, if you add public methods to this class, our test driver 
        - the one we will use to mark this assignment - will not know about them
        since we will use these public method prototypes to create our test driver. */

        // Constructors and destructor:
        Dictionary();                             // Default constructor
        ~Dictionary();                            // Destructor 
        
        // Dictionary operations:

        // Description: Returns the number of elements currently stored in the binary search tree.   
        // Time efficiency: O(1)
        unsigned int getElementCount() const;
            
        // Description: Puts "newElement" (association of key-value) into the Dictionary.
        // Precondition: "newElement" does not already exist in the Dictionary.
        //               This is to say: no duplication allowed.
        // Exception: Throws ElementAlreadyExistsException if "newElement" already exists in the Dictionary.
        // Time efficiency: O(log2 n) 
        void put(WordPair& newElement);
        
        // Description: Gets "newElement" (i.e., the associated value of a given key) from the Dictionary.
        // Precondition: Dictionary is not empty.
        // Exception: Throws ElementDoesNotExistException if the key is not found in the Dictionary.
        // Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
        // Time efficiency: O(log2 n)
        WordPair & get(WordPair& targetElement) const;

        // Description: Prints the content of the Dictionary.
        // Precondition: Dictionary is not empty.
        // Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
        // Time efficiency: O(n)  
        void displayContent(void visit(WordPair&)) const;
}; // end Dictionary
#endif