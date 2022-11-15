#include <iostream>
#include "Queue.h"
using std::cout;
using std::endl;

template <typename T>
void test();

int main()
{
    test<int>();
    system("pause");
}

template <typename T>
void test()
{
    Queue <T> q;

    int one = 123;
    int two = 345634;
    int three = 2345;
    q.enqueue(one);
    q.enqueue(two);
    q.enqueue(three);

    q.print();

    try
    {
        q.dequeue();
    }
    catch (EmptyDataCollectionException& exception) 
    {
        cout << exception.what() << endl;
    }

    try
    {
        q.dequeue();
    }
    catch (EmptyDataCollectionException& exception) 
    {
        cout << exception.what() << endl;
    }

    q.print();
}