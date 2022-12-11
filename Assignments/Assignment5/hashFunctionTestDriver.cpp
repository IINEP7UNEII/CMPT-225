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

// Description: Creates "size" elements of "digitCount (12)" digits.
//              and prints each element on its own line on stdout.
//              Each digit is randomly selected from the range [0..9].
void createRandomTestData(unsigned int size) 
{
    const unsigned int digitCount = 12;
    for (unsigned int count = 0; count < size; ++count) 
    {
        for (unsigned int count = 0; count < digitCount; ++count) 
        {
            cout << rand() % digitCount;
        }
        cout << '\n';
    }
}

void reverseString(string& s) 
{
    int size = s.length();
    for (int count = 0; count < size / 2; ++count)
    {
        swap(s[count], s[size - count - 1]);
    }
}

// Hash Function #1
// Description: Implements the type of hash function called 
//              "modular arithmetic" in which we use the modulo 
//              operator to produce the "hash index".
unsigned int hashFunc1(string indexingKey) 
{
    unsigned int hash = stoul(indexingKey);
    return hash % 100; // 100 is capacity of list
}

// Hash Function #2
// Description: Implements the type of hash function called "Folding -> shift" 
//              in which we partition the indexing key into parts and combine 
//              these parts using arithmetic operation(s).
unsigned int hashFunc2(string indexingKey) 
{
    string part;
    const unsigned int fold = 3;
    unsigned int value = 0;
    unsigned int sum = 0;
    unsigned int hash = 0;

    while (indexingKey.length() > 0)
    {
        part = indexingKey.substr(0, fold);
        value = stoi(part);
        sum += value;

        if (indexingKey.length() <= fold)
        {
            break;
        }
        indexingKey = indexingKey.substr(fold);
    }
    return hash % 100; // 100 is capacity of list
}

// Hash Function #3
// Description: Implements the type of hash function called "Folding -> boundary" 
//              in which we partition the indexing key into parts and combine 
//              these parts using arithmetic operation(s). In this type of folding,
//              the alternate parts (2nd, 4th ... parts) are reversed (i.e., flipped).
unsigned int hashFunc3(string indexingKey) 
{
    string part;
    const unsigned int fold = 3;
    unsigned int value = 0;
    unsigned int sum = 0;
    unsigned int hash = 0;
    bool reverse = false;

    while (indexingKey.length() > 0)
    {
        part = indexingKey.substr(0, fold);

        if (!reverse)
        {
            reverseString(part);
        }
        reverse = !reverse;
        value = stoi(part);
        sum += value;

        if (indexingKey.length() <= fold)
        {
            break;
        } 
        indexingKey = indexingKey.substr(fold);
    }
    return hash % 100; // 100 is capacity of list
}


int main(int argc, char *argv[]) 
{
    List* testingModulo1 = new List(hashFunc1);
    List* testingModulo2 = new List(hashFunc2);
    List* testingModulo3 = new List(hashFunc3);
    string anIndexingKey = "";
    
    if (argc == 3) 
    {
        createRandomTestData(stoul(argv[1]));
    }
    else 
    {
        if (argc == 2) 
        {
            ifstream myfile (argv[1]);
            if (myfile.is_open()) 
            {
                while (getline(myfile, anIndexingKey)) 
                {      
                    Member member(anIndexingKey);
                    testingModulo1->insert(member);
                    testingModulo2->insert(member);
                    testingModulo3->insert(member);
                } 
                myfile.close();
                
                cout << "***Experimenting with the hash functions***" << endl;
                testingModulo1->printList();
                testingModulo2->printList();   
                testingModulo3->printList();             
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

    delete[] testingModulo1;
    testingModulo1 = nullptr;
    delete[] testingModulo1;
    testingModulo2 = nullptr;
    delete[] testingModulo1;
    testingModulo3 = nullptr;
    
    system("pause");
    return 0;
}