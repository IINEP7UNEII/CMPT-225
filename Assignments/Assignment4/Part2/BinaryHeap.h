/*
 * BinaryHeap.h
 * 
 * Description: Min Binary Heap ADT class with several simple public interface functions.
 * Author: Daniel Tolsky
 * Date: Last modified: Nov. 2022
 */ 

 #ifndef BINARYHEAP_H
 #define BINARYHEAP_H

 #include "EmptyDataCollectionException.h"

 template <class ElementType>
 class BinaryHeap
 {
    private:
        ElementType* elements; // array of elements in binary heap
        unsigned int capacity; // actual capacity of the binary heap
        unsigned int elementCount; // amount of elements in the binary heap

        // Description: Returns whether the binary heap is empty
        // Postconditions: No changes to the binary heap
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Resize the binary heap underlying array
        // Postconditions: The binary heap capacity is doubled
        // Time Efficiency: O(n)
        void resize();

        // Description: Recursively enter the array into a min BinaryHeap
        // Time Efficiency: O(log2 n)
        void reHeapDown(unsigned int indexOfRoot);

        // Description: Recursively enter the array into a max BinaryHeap
        // Time Efficiency: O(log2 n)
        void reHeapUp(unsigned int indexOfRoot);

        // Description: Swap two elements in the underlying array
        // Time Efficiency: O(1)
        void swap(ElementType&, ElementType&);

    public:
        // Default Constructor
        BinaryHeap();

        // Copy constructor
        BinaryHeap(const BinaryHeap&);

        /******* Start of Binary Heap  Public Interface *******/	

        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap. 
        //              It returns true if successful, otherwise false.      
        // Time Efficiency: O(log2 n)
        bool insert(ElementType& newElement);

        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Postcondition: This Binary Heap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(1) 
        ElementType& retrieve() const;

        /******* End of Binary Heap Public Interface *******/
        
        // Destructor
        ~BinaryHeap();
 };
 #endif