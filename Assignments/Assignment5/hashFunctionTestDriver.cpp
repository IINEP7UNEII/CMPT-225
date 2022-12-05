/*
 * hashFunctionTestDriver.cpp
 * Description: Test driver for hash functions.
 *
 * Author: Daniel Tolsky
 * Modification Date: Dec. 2022
 */

#include "List.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::__cxx11::stoul;

// Description: Creates "size" elements of "digitCount" digits.
//              and prints each element on its own line on stdout.
//              Each digit is randomly selected from the range [0..9].
void createRandomTestData(unsigned int size, unsigned int digitCount) 
{
    for (unsigned int count = 0; count < size; ++count) 
    {
        for (unsigned int count = 0; count < digitCount; ++count) 
        {
            cout << rand() % 10;
        }
        cout << endl;
    }
}	

// Hash Function #1
// Description: Implements the type of hash function called 
//              "modular arithmetic" in which we use the modulo 
//              operator to produce the "hash index".
unsigned int hashModulo(string indexingKey) 
{
    // stoul -> string-to-unsigned int function
    // "hashCode" is an intermediate result
    unsigned int hashCode = stoul(indexingKey);
    return hashCode % List::CAPACITY;
}

// For you to do:
// Hash Function #2
// Description: Implements the type of hash function called "Folding -> shift" 
//              in which we partition the indexing key into parts and combine 
//              these parts using arithmetic operation(s).
unsigned int hashFoldShift(string indexingKey) 
{
    // Implements the Folding -> shift hash function.
    // "hashCode" is an intermediate result
    unsigned int hashCode = 0;
    return hashCode;
}

// For you to do:
// Hash Function #3
// Description: Implements the type of hash function called "Folding -> boundary" 
//              in which we partition the indexing key into parts and combine 
//              these parts using arithmetic operation(s). In this type of folding,
//              the alternate parts (2nd, 4th ... parts) are reversed (i.e., flipped).
unsigned int hashFoldBoundary(string indexingKey)
{
    // Implements the Folding -> boundary hash function.
    // "hashCode" is an intermediate result
    unsigned int hashCode = 0;
    return hashCode;
}


int main(int argc, char *argv[]) 
{
    List* testingModulo = new List(hashModulo);
    string anIndexingKey = "";
    
    // If you enter the command: ./hftd 100 16
    // createRandomTestData( 100, 16 ) is called
    // and will create 100 elements and 
    // print each element on its own line on stdout.
    // Each of these elements will be made of 16 digits.
    // Each digit will be randomly selected from the range [0..9].
    // If you enter the command: ./hftd 100 16 > dataFile_100_16.txt
    // all of these 100 elements will be stored into 
    // the file dataFile_100_16.txt, which can be read later.
    if (argc == 3) 
    {
        createRandomTestData(stoul(argv[1]), stoul(argv[2]));
    }
    else 
    {
        // If you enter the command: ./hftd dataFile_100_16.txt
        // each element of dataFile_100_16.txt is read as 
        // an indexing key, which is then inserted into "testingModulo",
        // which is an object of the List class.
        // As part of inserting this newElement (i.e., anIndexingKey),
        // anIndexingKey is hashed and the produced hash index is
        // used to insert anIndexingKey into the hashTable. 
        // See the implementation of insert(...) in List.cpp.
        if (argc == 2) 
        {
            ifstream myfile (argv[1]);
            if (myfile.is_open()) 
            {
                while (getline(myfile, anIndexingKey)) 
                {      
                    // cout << "The indexing key read is " << anIndexingKey << endl; 
                    testingModulo->insert(anIndexingKey);
                } 
                myfile.close();
                
                // Print the content of the hashTable 
                // Print an histogram showing how well (or poorly) the hash indices
                // are distributed over the whole hashTable.
                cout << "***Experimenting with the modulo hash function***" << endl;
                testingModulo->printList();
                testingModulo->histogram();
                testingModulo->printStats();                
            }
            else
            {
                cout << "Unable to open file"; 
            } 
        }
        else
        {
            cout << "Forgot the file name? Try again!" << endl;
        }
    }

    delete testingModulo;
    testingModulo = nullptr;
    
    system("pause");
    return 0;
}