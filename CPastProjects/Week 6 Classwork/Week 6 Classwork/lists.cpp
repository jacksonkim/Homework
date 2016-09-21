#include <iostream>
#include <string>
#include <list> // Include the list header
using namespace std;

int main()
{
    int count;  // Loop counter
    string name;
    
    // Define a list object.
    list<string> aList;
    
    // Gets the number of elements in the list.
    cout << "aList starts with " << aList.size()
    << " elements.\n";
    
    // Use push_back to push values into the list.
    for (count = 0; count < 5; count++) {
        cout << "Enter a Name " << count+1 << " of 5: ";
        getline(cin, name);
        aList.push_back(name);
    }

    
    // Display the size of the aList now.
    cout << "Now aList has " << aList.size()
    << " elements. Here they are:\n";
    
    // Output the contents of the list (don't worry about itr, we will discuss
    // it later)
    for (list<string>::iterator itr = aList.begin(); 
         itr != aList.end(); 
         itr++)
        cout << *itr << " " << endl;
    
    cout << endl;
    
    // Use the pop_front member function.
    cout << "Popping the values out of aList...\n";
    aList.pop_front();
    aList.pop_front();
    
    // Display the size of the aList now.
    cout << "Now aList has " << aList.size() << " elements.\n";

    system("pause");
    return 0;
}