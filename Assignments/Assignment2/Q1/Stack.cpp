#include "Stack.h"
#include <stdexcept>
using namespace std;

Stack::Stack() // constructor
: size(0), head()
{ }

void Stack::push(int x)
{
    StackNode* newNode = new StackNode();
    newNode->data = x;
    newNode->next = nullptr;

    if (size == 0)
    {
        head = newNode;
    }
    else
    {
        StackNode* curr = head;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }
    ++size;
}

int Stack::pop()
{
    if (size <= 0)
    {
        logic_error("Must have at least one element in the stack to use the pop function!");
    }
    else
    {
        StackNode* curr = head;
        StackNode* prev;

        while(curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        int removedData = curr->data;
        delete curr;
        prev->next = nullptr;
        --size;

        return removedData;
    }
    return -1; //to get rid of warning during compilation
}

int Stack::peek() const
{
    if (size <= 0)
    {
        logic_error("Must have at least one element in the stack to use the peek function!");
    }

    StackNode* curr = head;
    while(curr->next != nullptr)
    {
        curr = curr->next;
    }

    return curr->data;
}

bool Stack::isEmpty() const
{
    if (size == 0)
    {
        return true;
    }
    return false;
}