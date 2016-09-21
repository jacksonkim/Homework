// ios::exceptions
#include <iostream>
#include <new>
using namespace std;

int main () {
    int Option = 0;
    try {
        cin.exceptions(std::ios_base::badbit   |
                      std::ios_base::failbit); 
        
        for(;;)
        {
            
            cout << "Enter option: ";
            cin >> Option;
            
            switch(Option)
            {
                case 1:
                    cout << "Selected 1" << endl;
                    break;
                case 2:
                    cout << "Selected 2" << endl;
                    break;
                case 3:
                    cout << "Selected 3" << endl;                
                    break;
                default:
                    cout <<"Please enter the valid input!";
            }
        }
    };


    catch (std::ios_base::failure& e) {
        cout << "reading input failed: " << e.what() << endl;
        
    }
    
    system("pause");

    return 0;
};