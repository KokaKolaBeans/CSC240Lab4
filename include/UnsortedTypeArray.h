#ifndef UNSORTEDTYPEARRAY_H
#define UNSORTEDTYPEARRAY_H
#include "ItemType.h"

const int MAX_ITEMS = 50;

class UnsortedTypeArray

{

public:
    UnsortedTypeArray();
    // Pre: Object doesn't exist
    // Post: Empty list and associated data members (length, currentPos) is initialized with no elements
    // Function: Default constructor
    void MakeEmpty();
    // Pre: object exists
    // Post: the backing array info is zero'd out; currentPos and length = 0
    bool IsFull() const;
    // Pre: Object has been initialized
    // Post: If list is full (50 items), returns true; if 0 < n < 50, returns false
    int GetLength() const;
    // Pre: Object and associated private data members are initailized
    // Post: int length is returned
    ItemType GetItem(ItemType &item, bool &found);
    // Pre: Object and members are initialized
    // Post: Found item is returned if it exists; bool argument tells us if item was or wasn't found
    ItemType GetCurrentItem();
    // Pre: Object and members are initialized
    // Post: Item at index currentPos is returned
    void PutItem(ItemType item);
    // Pre: Object and members are initialized; object exists in list
    // Post: Item is added to the end of the list and length is incremented by one.
    void DeleteItem(ItemType item);
    // Pre: Object and members are initialized; one or more objects matching target exist in list
    // Post: All objects matching target are removed; non-target objects to the right of the n target objects
    //      are shifted left n times.
    // Function: Gets the next element in list.
    // Pre:  List has been initialized and has not been changed since last call.
    //       Current position is defined.
    //       Element at current position is not last in list.
    //
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.
    ItemType GetNextItem();
    // Pre: currentPos points to an item
    // Post: currentPos points to the next item; that item is returned
    void Print();
    // Pre: Object and members exist
    // Post: Items at indices up to length are printed
    void SplitLists(UnsortedTypeArray list, ItemType item, UnsortedTypeArray &list1, UnsortedTypeArray &list2);
    // Pre: list, item, list1, list2 have been initialized
    // Post: list1 and list2 are filled with the appropriate values.

    void ShiftRight();

    void ResetList();

private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
    // ItemType *begin;
    // ItemType *end;

    // typedef int ItemType;
};

#endif
