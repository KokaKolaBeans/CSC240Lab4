#include "UnsortedTypeArray.h"
#include <iostream>
using namespace std;

int main()
{
    UnsortedTypeArray classList;
    classList.PutItem(ItemType(4));
    classList.PutItem(ItemType(5));
    classList.PutItem(ItemType(4));
    classList.PutItem(ItemType(4));
    classList.PutItem(ItemType(8));

    cout << "(original) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();

    classList.ShiftRight();
    cout << "(shifted right) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();
    classList.ResetList();

    classList.DeleteItem(ItemType(4)); // this is halting the program

    cout << "(delete all 4s) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();

    classList.ShiftRight();
    cout << "(shift right) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();

    // Run on list where every element 4:

    UnsortedTypeArray fourList;

    fourList.PutItem(ItemType(4));
    fourList.PutItem(ItemType(4));
    fourList.PutItem(ItemType(4));
    fourList.PutItem(ItemType(4));
    fourList.PutItem(ItemType(4));

    cout << "All-four list after ShiftRight:" << endl;

    fourList.ShiftRight();

    fourList.Print();

    cout << "All-four list after deleting 4" << endl;

    fourList.DeleteItem(4);

    fourList.Print();

    // Run on empty list:

    UnsortedTypeArray empty;

    cout << "Empty list after ShiftRight:" << endl;

    fourList.ShiftRight();

    fourList.Print();

    cout << "Empty list after deleting 4" << endl;

    fourList.DeleteItem(4);

    fourList.Print();

    // Delete an item not in the list

    cout << "classList:" << endl;

    classList.Print();

    classList.DeleteItem(25);

    cout << "classList after deleting an item (25) that doesn't exist" << endl;

    classList.Print();

    cout << endl;

    return 0;
}

// g++ -I include src/ItemType.cpp src/UnsortedTypeArray.cpp Lab4Driver.cpp -o lab4 && ./lab4