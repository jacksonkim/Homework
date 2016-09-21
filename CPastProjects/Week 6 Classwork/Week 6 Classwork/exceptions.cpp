// This program demonstrates the bad_alloc exception.
#include <iostream>
#include <new>       // Needed for bad_alloc
using namespace std;

int main()
{
    double *ptr;   // Pointer to double

    try
    {
        int oursize;

        cout << "Enter Size: ";
        cin >> oursize;
        ptr = new double [oursize];
    }
    catch (bad_alloc)
    {
        cout << "Insufficient memory.\n";
    }


    system("pause");
    return 0;
};