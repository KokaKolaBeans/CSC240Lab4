#include <iostream>
using namespace std;

void DeleteItem(int arr[], int &len, int tar);

int main()
{
    int length = 5;
    int target = 4;
    int *numbers = new int[length]{4, 5, 4, 4, 8};

    cout << "Original list" << endl;
    for (int k = 0; k < length; ++k)
    {
        cout << numbers[k] << endl;
    }
    cout << "length = " << length << endl
         << endl;

    DeleteItem(numbers, length, target);

    cout << "New list" << endl;

    for (int k = 0; k < length; ++k)
    {
        cout << numbers[k] << endl;
    }

    cout << "length = " << length << endl
         << endl;

    delete[] numbers;
    return 0;
}

void DeleteItem(int arr[], int &len, int tar)
{
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < len; readIndex++)
    {
        if (arr[readIndex] != tar)
        {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }
    len = writeIndex;
}