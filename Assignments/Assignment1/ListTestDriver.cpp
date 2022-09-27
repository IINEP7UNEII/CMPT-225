/*
 * ListTestDriver.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System Test Driver
 *
 * Author: Daniel Tolsky
 * Last modified: Sept. 2022
 */
#include "List.h"
#include <iostream>
#include <cassert>

using namespace std;

int main ()
{
    List data; // creates database "data"
    Member member1("John Bart", "604-123-4567", "fakeemail@sfu.ca", "1234567890"); //create member1 
    Member member2("Fake Dude", "604-765-4321", "spammail@sfu.ca", "0987654321"); //create member2
    Member member3("Demarcus Cousins", "778-000-0000", "dcus@gmail.com", "00000000000"); //create member3

    // insert 3 members above into database
    data.insert(member1);
    data.insert(member2);
    data.insert(member3);

    cout << "Insert test:\n";
    cout << "Member member1(\"John Bart\", \"604-123-4567\", \"fakeemail@sfu.ca\", \"1234567890\");"
         << "\nMember member2(\"Fake Dude\", \"604-765-4321\", \"spammail@sfu.ca\", \"0987654321\");"
         << "\nMember member3(\"Demarcus Cousins\", \"778-000-0000\", \"dcus@gmail.com\", \"00000000000\");";
    cout << "\n\nPrint member data:\n";
    data.printList(); //prints the list of members in proper format for user to check over

    // Search test uses the asser function to test wheter the search function returns the proper result
    cout << "\n\nSearch test:\n";
    cout << "Search for member 2 and display its memmory address:\n";
    cout << data.search(member2) << "\n";
    assert(*data.search(member2) == member2);

    // Remove test uses the assert function to verify that member2 has been
    // removed from the database by using the return of the remove funciton
    cout << "\n\nRemove test:\n";
    cout << "Search for member 2 and remove it from database:\n";
    assert(data.remove(member2));
    cout << "\n\nPrint member data:\n";
    data.printList();

    // Remove all test uses the assert function to veritfy that no members
    // are left in the database after the funtion is called on the database.
    cout << "\n\nRemove all and get element count test:\n";
    data.removeAll();
    cout << "Removed all members from database!\n";
    assert(data.getElementCount() == 0);

    cout << "\n\n";
    system("pause"); //so terminal stays open for my machine
    return 0;
}