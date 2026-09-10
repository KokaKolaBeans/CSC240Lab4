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
    // cout << "line 23" << endl;
    classList.DeleteItem(ItemType(4)); // this is halting the program
    // cout << "line 25" << endl;
    cout << "(delete all 4s) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();

    classList.ShiftRight();
    cout << "(shift right) length: " << classList.GetLength() << endl;
    classList.ResetList();
    classList.Print();
    return 0;
}

// g++ -I include src/ItemType.cpp src/UnsortedTypeArray.cpp Lab4Driver.cpp -o lab4 && ./lab4