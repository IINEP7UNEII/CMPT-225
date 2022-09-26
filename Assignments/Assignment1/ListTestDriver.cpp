#include "List.h"
#include <iostream>
#include <cassert>

using namespace std;

int main () 
{
    List data;
    Member member1("John Bart", "604-123-4567", "fakeemail@sfu.ca", "1234567890");
    Member member2("Fake Dude", "604-765-4321", "spammail@sfu.ca", "0987654321");
    Member member3("Demarcus Cousins", "778-000-0000", "dcus@gmail.com", "00000000000");

    // insert 3 members above
    data.insert(member1);
    data.insert(member2);
    data.insert(member3);

    cout << "Insert test:\n";
    cout << "Member member1(\"John Bart\", \"604-123-4567\", \"fakeemail@sfu.ca\", \"1234567890\");"
         << "\nMember member2(\"Fake Dude\", \"604-765-4321\", \"spammail@sfu.ca\", \"0987654321\");"
         << "\nMember member3(\"Demarcus Cousins\", \"778-000-0000\", \"dcus@gmail.com\", \"00000000000\");";
    cout << "\n\nPrint member data:\n";
    data.printList();

    cout << "\n\nSearch test:\n";
    cout << "Search for member 2 and display its memmory address:\n";
    cout << data.search(member2) << "\n";
    assert(*data.search(member2) == member2);

    cout << "\n\nRemove test:\n";
    cout << "Search for member 2 and remove it from database:\n";
    assert(data.remove(member2));
    cout << "\n\nPrint member data:\n";
    data.printList();

    cout << "\n\nRemove all and get element count test:\n";
    cout << "Remove all members from database:\n";
    data.removeAll();
    assert(data.getElementCount() == 0);

    cout << "\n\n";
    system("pause"); //so terminal stays open for my machine
    return 0;
}