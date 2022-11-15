/*
 * BinaryHeap.h
 * 
 * Description: Min Binary Heap ADT class with several simple public interface functions.
 * Class Invariant: Always a minimum ADt binary heap
 * Author: Daniel Tolsky
 * Date: Last modified: Nov. 2022
 */  

#include <iostream>
#include "BinaryHeap.h"
using namespace std;

// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
: elements(new ElementType[10]), capacity(10), elementCount(0)
{ }

// Copy constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap& other)
{
   capacity = other.capacity;
   elementCount = other.elementCount;

   for (unsigned int count = 0; count < capacity; ++count)
   {
      elements[count] = other.elements[count];
   }
}

// Description: Returns whether the binary heap is empty
// Postconditions: No changes to the binary heap
// Time Efficiency: O(1)
template <class ElementType>
bool BinaryHeap<ElementType>::isEmpty()const
{
   if (elementCount == 0)
   {
      return true;
   }
   return false;
}

// Description: Resize the binary heap underlying array
// Postconditions: The binary heap capacity is doubled
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::resize()
{
   ElementType* newArr = new ElementType[capacity *= 2];

   for (int count = 0; count < elementCount; ++count)
   {
      newArr[count] = elements[count];
   }

   delete[] elements;
   elements = newElements;
}

// Description: Recursively enter the array into a min BinaryHeap
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) 
{
   unsigned int indexOfMinChild = indexOfRoot;

   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1)
   {
      return;
   } 

   // If we need to swap, select the smallest child
   if (elements[indexOfRoot] > elements[indexOfLeftChild])
   {
      indexOfMinChild = indexOfLeftChild;
   }

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) 
   {
      if (elements[indexOfMinChild] > elements[indexOfRightChild])
      {
         indexOfMinChild = indexOfRightChild;
      }
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) 
   {
      swap(elements[indexOfMinChild], elements[indexOfRoot]);
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Recursively enter the array into a max BinaryHeap
// Time Efficiency: O(log2 n)
template <class ElementType> 
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfRoot)
{
   if (indexOfRoot > 0)
   {
      unsigned int indexOfParent = (indexOfRoot - 1) / 2;

      if (elements[indexOfRoot] <= elements[indexOfParent])
      {
         swap(elements[indexOfParent], elements[indexOfRoot]);

         // Recursively put the array back into a heap
         reHeapUp(indexOfParent);
      }
   }
   return;
}

// Description: Swap two elements of any type
// Time Efficiency: O(1)
template <class ElementType> 
void BinaryHeap<ElementType>::swap(ElementType& a, ElementType& b)
{
   ElementType temp = a;
   a = b;
   b = temp;
}

// Description: return the element count of the Binary Heap
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{
   return elementCount;
}

// Description: Insert an element into the Binary Heap, return true if successful
//              and false otherwise
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement)
{
   if (elementCount == capacity)
   {
      resize();
   }

   elements[elementCount] = newElement;
   elementCount++;   
   reHeapUp(elementCount - 1);
   return true;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() 
{  
   if (elementCount == 0)
   {
      throw EmptyDataCollectionException("Exception in remove(): Data collection is empty.");
   }

   elements[0] = elements[elementCount - 1];
   elementCount--;
   reHeapDown(0);
   return;   
}

// Description: Retrieves the necessary element
// Precondition: This binary heap is not empty
// Postconditions: This binary heap is unchanged
// Time efficiency: O(1)
template <class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const
{
   if (elementCount == 0)
   {
      throw EmptyDataCollectionException("Exception in retrieve(): Data collection is empty.");
   }

   return elements[0];
}

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
   delete[] elements;
}