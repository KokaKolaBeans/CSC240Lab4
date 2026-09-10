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

void UnsortedTypeArray::DeleteItem(ItemType item)
{
    int writeIndex = 0;

    int readIndex = 0;

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

    currentPos++;
    return info[currentPos++];
};

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
    currentPos = 0;
    while (currentPos < length) // n
    {
        switch (item.ComparedTo(list.info[currentPos])) // n == n^2
        {
        case LESS:
        case EQUAL:
            list2.PutItem(info[currentPos]);
            break;
        case GREATER:
            list1.PutItem(info[currentPos]);
            break;
        }
        currentPos++;
    }
}

ItemType UnsortedTypeArray::GetCurrentItem()
{
    return info[currentPos];
}

void UnsortedTypeArray::ShiftRight()
{
    ItemType lastItem = info[length - 1];

    for (int k = length; k >= 0; k--)
    {
        info[k] = info[k - 1];
    }
    info[0] = lastItem;
}