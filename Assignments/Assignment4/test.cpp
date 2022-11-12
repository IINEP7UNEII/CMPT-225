#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue q;
    q.enqueue("Test");
    q.enqueue("asdgasdg");
    q.enqueue("1234");
    q.enqueue(456);

    q.print();

    q.dequeue();
    q.dequeue();

    q.print();

    system("pause");
}