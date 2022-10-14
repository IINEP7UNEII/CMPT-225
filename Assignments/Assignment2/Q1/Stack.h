/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Daniel Tolsky
 * Date: 13/10/2022
 */
 
class Stack 
{

    private:
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode 
        {
            public:
                int data;
                StackNode* next;
        };
        unsigned int size; // size of linked list
        StackNode* head = new StackNode(); // first element (bottom of stack)

    public:
        // Desc:  Object constructor
        // Post:  sets size to 0
        Stack();

        // Desc:  Insert element x to the top of the stack.
        // Post:  pushes all included elements up one index and adds x to index 0
        void push(int x);

        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  size > 0
        // Post:  moves all elements of stack down one index and returns the old first value at index 0
        int pop();

        // Desc:  Return the topmost element of the stack.
        //  Pre:  size > 0
        // Post:  returns first index of array
        int peek() const;

        // Desc:  Returns true if the size of the stack is 0, otherwise return false
        // Post:  returns whether there are elements in the stack
        bool isEmpty() const;
};
