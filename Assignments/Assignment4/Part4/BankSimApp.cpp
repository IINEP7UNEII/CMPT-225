/*   
 * BankSimApp.cpp
 *
 * Description: Bank simulation program which simulates a bank queue 
 *      using an underlying binary heap to simulate a priority queue.
 * Author: Daniel Tolsky
 * Date: Nov. 22
 */

#include <iostream>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"
using namespace std;

// Function which processes the arrival of customers
void arrive(Event&, Queue<Event>&, bool&, PriorityQueue<Event>&, unsigned int&);

// Function which processes the departure of customers
void depart(Event&, Queue<Event>&, bool&, PriorityQueue<Event>&, unsigned int&);

int main()
{
    cout << "Bank Simulation" << "\n***************\n\n";

    bool tellerOpen = true;
    unsigned int totalTime = 0;
    unsigned int numArrivals = 0;
    unsigned int arrivalCount = 0;
    unsigned int departureCount = 0;

    PriorityQueue<Event> pQueue = PriorityQueue<Event>();
    Queue<Event> bankQueue = Queue<Event>();
    Event newArrival;

    string line = "";
    string delimiter = " ";
    string arrivalTime = "";
    string lengthData = "";

    // Read data and enter it into the priority queue
    while (getline(cin, line))
    {
        arrivalTime = line.substr(0, line.find(delimiter));
        lengthData = line.substr(line.find(delimiter) + 1, line.length());
        newArrival = Event();
        newArrival.setLength(stoi(lengthData));
        newArrival.setTime(stoi(arrivalTime));
        pQueue.enqueue(newArrival);
        numArrivals++;
    }

    // Priority queue process of events
    while (!pQueue.isEmpty())
    {
        try
        {
            Event next = pQueue.peek();

            if (next.getType() == Event::ARRIVAL)
            {
                cout << "Processing arrival: " << arrivalCount << '\n';
                arrive(next, bankQueue, tellerOpen, pQueue, totalTime);
                cout << "Arrival: " << arrivalCount << " processed" << '\n' << '\n';
                ++arrivalCount;
            }
            else if (next.getType() == Event::DEPARTURE)
            {
                cout << "Processing Departure Event " << departureCount << '\n';
                depart(next, bankQueue, tellerOpen, pQueue, totalTime);
                cout << "Departure Event " << departureCount << " processed" << '\n' << '\n';
                ++departureCount;
            }
            else
            {
                return -1; // error
            }
        }
        catch (EmptyDataCollectionException &exeption)
        {
            cerr << "\n\n\nError: " << exeption.what() << '\n';
        }
    }

    // View statistics
    cout << "Bank simulation terminated" << '\n';
    cout << "Statistics:" << "\n\n";
    cout << "Total number processed: " << numArrivals << '\n';
    cout << "Average wait time: " << (double)totalTime / (double)numArrivals << '\n';

    system("pause");
    return 0;
}

void arrive(Event &next, Queue<Event> &bankQueue, bool &tellerOpen, PriorityQueue<Event> &pQueue, unsigned int totalTime)
{
    int cTime = next.getTime();
    cout << "Arrival at time: " << cTime << '\n';
    pQueue.dequeue();

    if (tellerOpen && bankQueue.isEmpty())
    {
        cTime = next.getTime();
        tellerOpen = false;
        Event departure = Event(Event::DEPARTURE, cTime + next.getLength());
        totalTime += cTime;
        pQueue.enqueue(departure);
    }
    else
    {
        bankQueue.enqueue(next);
    }
}

void depart(Event &next, Queue<Event> &bankQueue, bool &tellerOpen, PriorityQueue<Event> &pQueue, unsigned int totalTime)
{
    int cTime = next.getTime();
    int currentTime = next.getTime();
    cout << "Departure at time: " << cTime << '\n';
    pQueue.dequeue();
    totalTime += cTime;
    int departureTime = 0;

    if (!bankQueue.isEmpty())
    {
        try
        {
            Event newCustomer = bankQueue.peek();
            bankQueue.dequeue();
            totalTime = totalTime + cTime - newCustomer.getTime();
            departureTime = cTime + newCustomer.getLength();
            cTime = newCustomer.getTime();
            Event departure = Event(Event::DEPARTURE, departureTime);
            pQueue.enqueue(departure);
        }
        catch (EmptyDataCollectionException &exeption)
        {
            cerr << "\n\n\nError: " << exeption.what() << '\n';
        }
    }
    else
    {
        tellerOpen = true;
    }
}