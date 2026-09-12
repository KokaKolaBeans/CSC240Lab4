#include "UnsortedTypeArray.h"
#include "ItemType.h"
#include <iostream>
#include <cassert>

UnsortedTypeArray::UnsortedTypeArray()
{
    length = 0;
    currentPos = 0;
}

// UnsortedTypeArray::~UnsortedTypeArray();

void UnsortedTypeArray::MakeEmpty() // sets all values to 0
{
    for (int k = 0; k < length; k++)
    {
        info[k].SetValue(0);
    }
    length = 0;
    currentPos = 0;
}

bool UnsortedTypeArray::IsFull() const // he might want this the other way around–check StudentType
{
    if (length == 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int UnsortedTypeArray::GetLength() const { return length; }

ItemType UnsortedTypeArray::GetItem(ItemType &item, bool &found)

{
    currentPos = 0;
    ItemType Match;

    found = false;

    int k = 0;

    while (currentPos < length - 1)
    {

        switch (item.ComparedTo(info[k]))
        {
        case LESS:
        case GREATER:
            break;
        case EQUAL:
            Match = info[k];
            found = true;
            break;
        }
        k++;
    }

    if (found)
    {
        return Match;
    }
    else
    {
        return NULL;
    }
}

void UnsortedTypeArray::PutItem(ItemType item) //
{
    if (length + 1 == 50)
    {
        std::cout << "List is Full" << std::endl;
        return;
    }
    info[length] = item;
    length++;
};

// =======================================
// Design and Documentation Question 1
// =======================================

/* DeleteItem invariant – At the start of each iteration of the loop over info[0... readIndex-1]:

1. The prefix info[0 ... writeIndex - 1] contains all non-target values encountered so far in their
original relative order.
2. writeIndex satisfies 0 <= writeIndex <= readIndex, where (readIndex - writeIndex) equals the number
of target values encountered so far.
*/
void UnsortedTypeArray::DeleteItem(ItemType item)
{

    int writeIndex = 0;

    for (int readIndex = 0; readIndex < length; readIndex++)
    {
        if (info[readIndex].ComparedTo(item) != EQUAL)
        {
            info[writeIndex] = info[readIndex];
            writeIndex++;
        }
    }
    length = writeIndex;
}

void UnsortedTypeArray::ResetList()
{
    currentPos = 0;
}

ItemType UnsortedTypeArray::GetNextItem()
{
    // Function: Gets the next element in list.
    // Pre:  List has been initialized and has not been changed since last call.
    //       Current position is defined.
    //       Element at current position is not last in list.
    //
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.

    return info[currentPos++];
}

void UnsortedTypeArray::Print() // Prints horiziontally with commas and braces
{
    currentPos = 0;
    std::cout << "{";
    while (currentPos < length)
    {

        int printValue = info[currentPos].GetValue();
        std::cout << printValue;
        if (currentPos < length - 1)
        {
            std::cout << ", ";
        }
        currentPos++;
    }
    std::cout << "}" << std::endl;
}

void UnsortedTypeArray::SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2)
{
    for (int k = 0; k < list.length; k++)
    {
        switch (list.info[k].ComparedTo(item)) // n == n^2
        {
        case LESS:
        case EQUAL:
            list1.PutItem(list.info[k]);
            break;
        case GREATER:
            list2.PutItem(list.info[k]);
            break;
        }
    }
}

ItemType UnsortedTypeArray::GetCurrentItem()
{
    return info[currentPos];
}

void UnsortedTypeArray::ShiftRight()
{
    if (length <= 1)
        return;

    ItemType lastItem = info[length - 1];

    for (int k = length - 1; k > 0; k--)
    {
        info[k] = info[k - 1];
    }
    info[0] = lastItem;
}