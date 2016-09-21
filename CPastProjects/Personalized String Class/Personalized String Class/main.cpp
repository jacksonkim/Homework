//
//  main.cpp
//  Simple C++ String
//
//  Created by Charles Hardnett on 3/5/12.
//  Copyright (c) 2012 Charles Hardnett. All rights reserved.
//

#include <iostream>
#include "string.h"
#include <string>

using namespace CIST2362;


int main (int argc, const char * argv[])
{
    string s0 ("Initial string");
    string s1;
    string s2 (s0);
    
    std::string st0 ("Initial string");
    std::string st1;
    std::string st2 (st0);
    
    
    std::cout << "CIST2362:\ns0: " << s0 << "\ns1: " << s1 << "\ns2: " << s2 << std::endl;
    std::cout << "STD:\ns0: " << st0 << "\ns1: " << st1 << "\ns2: " << st2 << std::endl;
    
    s1 = s2; // CIST2362
    st1 = st2; // std

    
    std::cout << "CIST2362:\ns0: " << s0 << "\ns1: " << s1 << "\ns2: " << s2 << std::endl;
    std::cout << "STD:\ns0: " << st0 << "\ns1: " << st1 << "\ns2: " << st2 << std::endl;
    
    std::cin >> s0;
    std::cin >> st0;
    
    std::cout << "CIST2362:\ns0: " << s0 << "\ns1: " << s1 << "\ns2: " << s2 << std::endl;
    std::cout << "STD:\ns0: " << st0 << "\ns1: " << st1 << "\ns2: " << st2 << std::endl;
    
    s1.resize(20, 'x');  // CIST2362
    st1.resize(20, 'x'); // std

    std::cout << "CIST2362:\ns0: " << s0 << "\ns1: " << s1 << "\ns2: " << s2 << std::endl;
    std::cout << "STD:\ns0: " << st0 << "\ns1: " << st1 << "\ns2: " << st2 << std::endl;
    
    string s4(" Just added"); // CIST2362
    s0 += s4; 
    
    std::string st4(" Just added"); // std
    st0 += st4;
    
    std::cout << "CIST232:\ns0: " << s0 << "\ns1: " << s1 << "\ns2: " << s2 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "STD:\ns0: " << st0 << "\ns1: " << st1 << "\ns2: " << st2 << std::endl;
    std::cout << "s4: " << st4 << std::endl;
    
    std::cout << "CIST232:\ns4.substr(1,4) = " << s4.substr(1, 4) << std::endl;
    std::cout << "STD:\ns4.substr(1,4) = " << st4.substr(1, 4) << std::endl;
    
    std::cout << "CIST232:\ns4.find(\"Just\",0) => " << s4.find("Just", 0) << std::endl;
    std::cout << "STD:\ns4.find(\"Just\",0) => " << st4.find("Just", 0) << std::endl;
    
    s4.erase(1, 4);
    std::cout << "CIST232:\ns4.remove(\"Just\",0) => " << s4 << std::endl;
    st4.erase(1, 4);
    std::cout << "STD:\ns4.remove(\"Just\",0) => " << st4 << std::endl;
    
    s4.replace(1, 3, "sub");
    std::cout << "CIST2362:\ns4.replace(1, 3, \"sub\") => " << s4 <<std::endl;
    st4.replace(1, 3, "sub");
    std::cout << "STD:\ns4.replace(1, 3, \"sub\") => " << st4 <<std::endl;
    
    
    string s5("0123456789");
    std::cout << "CIST2362:\n5 found at " << s5.find("5", 0) << std::endl;
    
    std::cout << "6 found at " << s5.find('6', 0) << std::endl;
    
    std::cout << "5 or 6 found at " << s5.find_first_of("56", 0) << std::endl;
    
    std::cout << "first of 012a not found at " << s5.find_first_not_of("012a", 0) << std::endl;
    
    std::string st5("0123456789");
    std::cout << "STDHell:\n5 found at " << st5.find("5", 0) << std::endl;
    
    std::cout << "6 found at " << st5.find('6', 0) << std::endl;
    
    std::cout << "5 or 6 found at " << st5.find_first_of("56", 0) << std::endl;
    
    std::cout << "first of 012a not found at " << st5.find_first_not_of("012a", 0) << std::endl;
    
    
    
        
    
    
    
    
    
    return 0;
}

