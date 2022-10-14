#include <iostream>
#include <stdexcept>
#include "Stack.h"
using namespace std;

int main() 
{
    Stack * stk = new Stack();

    // push 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) 
    {
        stk->push(i);
        cout << "push " << i << endl;
    }

    // pop top two
    int x = stk->peek();
    stk->pop();
    int y = stk->peek();
    stk->pop();
    cout << "top 1: " << x << ", top 2: " << y << endl;

    // push 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) 
    {
        stk->push(i);
        cout << "push " << i << endl;
    }

    // pop all
    while (!stk->isEmpty()) 
    {
        int x = stk->peek();
        stk->pop();
        cout << "pop " << x << endl;
    }

    delete stk;
    stk = nullptr;
    
    system("pause");
}

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