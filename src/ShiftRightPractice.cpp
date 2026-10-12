#include <iostream>
using namespace std;

void ShiftRight(int info[], int len);

int main()
{
    return 0;
}

void ShiftRight(int info[], int len)
{
    if (len <= 1)
    {
        return;
    }
    
    int lastItem = info[len - 1];

    for (int k = len - 1; k > 0; --k)
    {
        info[k] = info[k - 1];
    }
    info[0] = lastItem;
    return;
}