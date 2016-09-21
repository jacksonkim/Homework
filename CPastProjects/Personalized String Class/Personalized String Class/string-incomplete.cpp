//
//  string.cpp
//  Simple C++ String
//
//  Created by Charles Hardnett on 3/5/12.
//  Copyright (c) 2012 Charles Hardnett. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "string.h"

namespace CIST2362 {
    
// friend prototypes
    bool operator==(const string&, const string&);
    bool operator!=(const string&, const string&);
    bool operator<(const string&, const string&);
    bool operator<=(const string&, const string&);
    bool operator>(const string&, const string&);
    bool operator>=(const string&, const string&);
    
    std::ostream& operator<<(std::ostream&, const string&);
    std::istream& operator>>(std::istream&, string&);
    
    
    
// constructors and destructors
    string::string() : strBuffer() {
        strBuffer.resize(1);
        strBuffer[0] = '\0';
    }
    
    
    string::string(const char* str){
        strBuffer.assign(str, str+strlen(str));
        strBuffer.push_back('\0');
    }
    
    string::string(const string& str){
        for (int i = 0; i < str.length(); i++) {
            strBuffer.push_back(str.strBuffer[i]);
        }
        strBuffer.push_back('\0');
    }
    
    string::~string(){}

// iterators
    string::iterator string::begin(){
        return strBuffer.begin();
    }
    
    string::iterator string::end(){
        return strBuffer.end();
    }
    

// methods
    bool string::empty(){
        return strBuffer[0] == '\0';
    }
    
    
    int string::find(const string& target, int start) {
        int targetLength = target.length();
        
        int stop = length() - targetLength;
        
        for (int i = start; i <= stop; i++) {
            if (substr(i, targetLength) == target)
                return i;
        }
        
        // no match
        return (int)strBuffer.size() + 1;

    }
    
    int string::find(char target, int start) const{
		// fill in this code
    }
    
    // find the first occurrence of any character from the match text
    int string::find_first_of(const string& matchText, unsigned int start){
        int position;
        
        for (int i = 0; i < matchText.length(); i++) {
            position = find(matchText.strBuffer[i], start);
            
            if (position < length())
                return position;
        }
        
        return position;
    }
    
    
    int string::find_first_not_of(const string& noMatchText, unsigned int start) {
		// fill in this code
    }
    
    // insert newText at position
    void string::insert(unsigned int position, const string& newText){
		// fill in this code
    }
    
    int string::length() const {
        return (int)strBuffer.size() - 1;
    }
    
    
    string string::substr(int start, int len){ 
        assert(start+len <= length());
        string sub; // create a new value
        
        sub.resize(len, '\0');
        
        for (int i = 0; i < len; i++) {
            sub.strBuffer[i] = strBuffer[start+i];
        }
        
        return sub;
    }
    
    // remove characters from a given range
    void string::remove(unsigned int start, unsigned int len){
	// HINT: don't forget to update the length
	// fill in this code
    }
    
    // replace start to start + len with new text
    void string::replace(unsigned int start, unsigned int len, const string& newText){
		// HINT: try using other methods instead of writing from scratch
		// fill in this code
    }
    
    void string::resize(unsigned int newsize, char pad){ 
        unsigned int oldSize = (unsigned int)strBuffer.size();
        
        strBuffer.pop_back();
        
        for (int i = 1; i <= newsize; i++) {
            strBuffer.push_back(pad);
        }
        strBuffer.push_back('\0');
    }
    
    // operators
    char& string::operator[] (int pos) {
        assert(pos <= length());
        return strBuffer[pos];
    }
    
    void string::operator= (string & str) {
        strBuffer = str.strBuffer;
    }
    
    void string::operator+= (string & right) {
        insert(length(), right);
    }
    
    
    // friends
    bool operator==(const string& lhs, const string& rhs) {
        if (lhs.length() != rhs.length())
            return false;
    
        // compare elements until a mismatch
        for (unsigned int i = 0; i < lhs.length(); i++) {
            if (lhs.strBuffer[i] != rhs.strBuffer[i]) {
                return false;
            }
        }
        
        // if no  mismatch lhs and rhs are the same
        return true;
    }
    
    
    bool operator!=(const string& lhs, const string& rhs) {
        return !(lhs == rhs);
    }
    
    
    bool operator<(const string& lhs, const string& rhs) {
        int pos = 0;
        
        // compare elements until mismatch
        for (unsigned int i = 0; i < lhs.length(); i++) {
            if (lhs.strBuffer[i] != rhs.strBuffer[i]) {
                pos = i;
            }
        }
        
        // mismatch characters determine if lhs < rhs
        if (lhs.strBuffer[pos] < rhs.strBuffer[pos])
            return true;
        
        return false;
    }
    
    
    bool operator<=(const string& lhs, const string& rhs) {
		// HINT: Use operators that have been already been defined
		// fill in this code		
    }
    
    
    bool operator>(const string& lhs, const string& rhs) {
		// HINT: Use operators that have already been defined
		// fill in this code		
    }
    
    
    bool operator>=(const string& lhs, const string& rhs) {
		// HINT: Use operators that have already been defined
		// fill in this code
    }

    
    std::ostream& operator<<(std::ostream& os, const string& str) {
 		// HINT: return os to allow chaining of << operators
		// fill in this code
    }
    
    
    std::istream& operator>>(std::istream& is, string& str) {
 		// HINT: return is to allow chaining of >> operators
		// fill in this code
    }
    
    
};