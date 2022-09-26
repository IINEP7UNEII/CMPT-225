/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: Daniel Tolsky
 * Last modified: Sept. 2022
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;

void add(List*);
void remove(List*);
void search(List*);
void modify(List*);
void print(List*);
string infoInputHandle();

int main() 
{
    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (!done) 
    {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
		switch(input) {
            case 'a': add(Members); break;
            case 'r': remove(Members); break;
            case 's': search(Members); break;
            case 'm': modify(Members); break;
            case 'p': print(Members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    system("pause");
}

void add(List* data)
{
    cout << "\n\n" << "Add new element in database.";

    cout << "\n" << "Enter the phone number: ";
    Member member(infoInputHandle());
    cout << "\n" << "Enter the name of the member: ";
    member.setName(infoInputHandle());
    cout << "\n" << "Enter the email of the member: ";
    member.setEmail(infoInputHandle());
    cout << "\n" << "Enter the credit card of the member: ";
    member.setCreditCard(infoInputHandle());
    cout << "\n\nMember info has been recorded!\n";

    bool success = data->insert(member);

    if (success)
    {
        cout << "Member has been added to the database!" << endl;
    }
    else
    {
        cerr << "Member has not been added to the database! Try again later!" << endl;
    }
}

void remove(List* data)
{
    cout << "\n\n" << "Remove element from database.";

    cout << "\n" << "Enter the phone number: ";
    Member member(infoInputHandle());
    cout << "\n" << "Enter the name of the member: ";
    member.setName(infoInputHandle());
    cout << "\n" << "Enter the email of the member: ";
    member.setEmail(infoInputHandle());
    cout << "\n" << "Enter the credit card of the member: ";
    member.setCreditCard(infoInputHandle());
    cout << "\n\nMember info has been recorded!\n";

    bool success = data->remove(member);

    if (success)
    {
        cout << "Member has been removed from the database!" << endl;
    }
    else
    {
        cerr << "Member has not been removed from the database! Try again later!" << endl;
    }
}

void search(List* data)
{
    cout << "\n\n" << "Search for element in database.";

    cout << "\n" << "Enter the phone number: ";
    Member member(infoInputHandle());
    cout << "\n" << "Enter the name of the member: ";
    member.setName(infoInputHandle());
    cout << "\n" << "Enter the email of the member: ";
    member.setEmail(infoInputHandle());
    cout << "\n" << "Enter the credit card of the member: ";
    member.setCreditCard(infoInputHandle());
    cout << "\n\nMember info has been recorded!\n";

    Member* address = data->search(member);

    if (address != nullptr)
    {
        cout << "Member has been found int the database!" << endl;
    }
    else
    {
        cerr << "Member has not been found in the database! Try again later!" << endl;
    }
}

void modify(List* data)
{
    cout << "\n\n" << "Modify credit card number for element in database.";

    cout << "\n" << "Enter the phone number: ";
    Member member(infoInputHandle());
    cout << "\n" << "Enter the name of the member: ";
    member.setName(infoInputHandle());
    cout << "\n" << "Enter the email of the member: ";
    member.setEmail(infoInputHandle());
    cout << "\n" << "Enter the old credit card of the member: ";
    member.setCreditCard(infoInputHandle());
    cout << "\n\nMember info has been recorded!\n";

    Member* updatedMember = data->search(member);

    if (updatedMember->getName() != "")
    {
        cout << "Member has been found in the database!" << endl;
    }
    else
    {
        cerr << "Member has not been found in the database! Try again later!" << endl;
    }

    cout << "\n" << "\n\nEnter the new credit card of the member: ";
    updatedMember->setCreditCard(infoInputHandle());
    data->remove(member);
    data->insert(*updatedMember);
    cout << "\n\nMember's credit card has been updated!";
}

void print(List* data)
{
    cout << "\n\n" << "Print contents of entire database.\n";

    data->printList();
}

string infoInputHandle() //handle input of interger for menu selection
{
    string tempString;
    cin >> tempString;
    while (cin.fail()) 
    {
        cerr << "ERROR: Enter string again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tempString;
    }
    cin.ignore(10000, '\n');
    return tempString;
}