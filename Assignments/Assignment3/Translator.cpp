/*
 * Translator.cpp
 * 
 * Description: Simple translator which reads a dictionary file and 
 *              outputs the translations with simple commands.
 *
 * Author: Daniel Tolsky
 * Last Modification Date: Oct. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "Dictionary.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"

using std::cin;
using std::cout;
using std::ifstream;

// Displays the word and its translation
void display(WordPair& anElement)
{
    cout << anElement;
} 

// Main function
int main(int argc, char* argv[]) 
{
    BST* dictionary = new BST();
            
    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "myDataFile.txt";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;

    ifstream myfile (filename);
    if (myfile.is_open()) 
    {
        while (getline(myfile, aLine)) // Read from file and insert items into BST datastructure
        {
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            translationW = aLine;
            WordPair aWordPair(englishW, translationW);
            try
            {
                dictionary->insert(aWordPair);
            }
            catch (ElementAlreadyExistsException& exception) 
            {
                cout << exception.what() << " => " <<  aWordPair.getEnglish() << ":" << aWordPair.getTranslation() << endl;
            }
        }
        myfile.close(); // End reading of file and close file

        // If user entered "display" at the command line display all contents of dictionary with translations
        if ((argc > 1) && (strcmp(argv[1], "display") == 0)) 
        {
            dictionary->traverseInOrder(display);
        }
        else if (argc == 1) // Otherwise, look for words enetered in command line
        {
            // while user has not entered CTRL+D
            while (getline(cin, aWord)) // Read command line words and display their relative translations
            {   
                WordPair aWordPair(aWord);
                try 
                {
                    translated = dictionary->retrieve(aWordPair);
                    cout << translated.getEnglish() << ":" << translated.getTranslation() << endl;
                }
                catch (ElementDoesNotExistException& exception) 
                {
                    cout << "Translation for \"" << aWordPair.getEnglish() << "\" not found!" << endl;
                }
            }
        }
    }
    else // If file cannot be opened
    {
        cout << "Unable to open file"; 
    }

    system("pause");
    return 0;
}