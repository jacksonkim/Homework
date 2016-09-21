//
//  string.h
//  Simple C++ String
//
//  Created by Charles Hardnett on 3/5/12.
//  Copyright (c) 2012 Charles Hardnett. All rights reserved.
//

#ifndef Simple_C___String_string_h
#define Simple_C___String_string_h

#include <vector>
#include <iostream>

namespace CIST2362 {
    class string {
    private:
        std::vector<char> strBuffer; // vector implementation only
        
        char* buffer; // dynamic array implementation only
        unsigned int bufferLength; // dynamic array implementation only
    public:
        typedef std::vector<char>::iterator iterator;  // string iterator decl
        
        // constructors and destructors
        string();
        string(const char*);      // string s("abcd");
        string(const string&);    // copy contructor string s2(s);
        ~string();
        
        // iterators
        iterator begin();
        iterator end();
        
        // methods
        bool empty();
        int find(const string&, int);
        int find(char, int);
        int find_first_of(const string&, unsigned int);
        int find_first_not_of(const string&, unsigned int);
        void insert(unsigned int, const string&);
        int length() const;
        string substr(int, int);
        void erase(unsigned int, unsigned int);
        void replace(unsigned int, unsigned int, const string&);
        void resize(unsigned int, char);
        
        // operators
        char& operator[] (int);
        void operator= (string &);
        void operator= (const char*);
        void operator+= (string &);
        
        // friends
        friend bool operator==(const string&, const string&);
        friend bool operator!=(const string&, const string&);
        friend bool operator<(const string&, const string&);
        friend bool operator<=(const string&, const string&);
        friend bool operator>(const string&, const string&);
        friend bool operator>=(const string&, const string&);
        
        friend std::ostream& operator<<(std::ostream&, const string&);
        friend std::istream& operator>>(std::istream&, string&);
                
    };
}

#endif
