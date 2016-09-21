//
//  stringv.cpp
//  Simple C++ String
//
//  Created by Charles Hardnett on 3/15/12.
//  Copyright (c) 2012 SMART Academy. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <algorithm>
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
    string::iterator string::begin() {
        return strBuffer.begin();
    }
    
    string::iterator string::end() {
        return strBuffer.end();
    }
    
    
    // methods
    bool string::empty(){
        return strBuffer[0] == '\0';
    }
    
    // find the first occurrence of the string target in the string from the position start
    int string::find(const string& target, int start) {
        string temp = target;
        // HINT: uses std::search
		//yay! we fixed it together!
		//the temp.end has to be -1 because otherwise it'll include the null operator? was it null. it was \0
		iterator pos = std::search(strBuffer.begin()+start, strBuffer.end(), temp.begin(), temp.end()-1);

		//if it found it, it'll be at the position in array subscript, thus add one.
		if (pos == strBuffer.end())
			return (int)strBuffer.size()+1;

		return (int)(pos-strBuffer.begin()); // return index - if not found
    }
    
    
    // find the first occurrence of the character target in the string from the position start
    int string::find(char target, int start) {
        // HINT: uses std::find
		//this one seems to work fine.
		iterator pos = std::find(strBuffer.begin() + start, strBuffer.end(), target);

		if (pos == strBuffer.end())
			return (int)strBuffer.size()+1;

		return (int)(pos-strBuffer.begin()); // return index
    }
    
    
    
    // find the first occurrence of any character from the match text
    int string::find_first_of(const string& matchText, unsigned int start){
        
        string temp = matchText;
        iterator pos = std::find_first_of(strBuffer.begin() + start, strBuffer.end(), temp.begin(), temp.end());
        
        if (pos == strBuffer.end())
            return (int)strBuffer.size() + 1;        // no match
        
        return (int)(pos-strBuffer.begin()); // return index
    }
    
    
    // find the first occurrence of any character not from the match text
    int string::find_first_not_of(const string& noMatchText, unsigned int start) {
		int position = find(noMatchText, start);
       //the only ideas i had did not include the find method.
        //HINT: uses our string::find 
		return position;
        
    }
    
    // insert newText at position
    void string::insert(unsigned int position, const string& newText){
       // HINT: uses vector::insert
		string temp = newText; //this has to be done to prevent the const and & qualifier stuff from
		//preventing the newText iterators to break
		strBuffer.insert(strBuffer.begin()+position, temp.begin(), temp.end()-1);
    }
    
    // find the length of the string
    int string::length() const {
        return (int)strBuffer.size() - 1;
    }
    
    
    // retrieve a copy of the substring from position start of length len
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
    void string::erase(unsigned int start, unsigned int len){
        // HINT: uses vector::erase    
		//this took me ages to figure out, but i got it working. like the only thing.
		//well, this and find for char.
		strBuffer.erase(strBuffer.begin()+start, strBuffer.begin()+(start+len));
    }
    
    
    
    // replace start to start + len with new text
    void string::replace(unsigned int start, unsigned int len, const string& newText){
        erase(start, len);
        insert(start, newText); //i assume there is something wrong here, becuase it isn't adding the text in front
			//of the ded like the STD stuff is, it's just replacing it. i would say the STD must be wrong then, but
			//its the STD.
    }
    
    
    void string::resize(unsigned int newsize, char pad){ 
        strBuffer.pop_back();
        strBuffer.resize(newsize, pad);
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
        
        return std::equal(lhs.strBuffer.begin(), lhs.strBuffer.end(), rhs.strBuffer.begin());
    }
    
    
    bool operator!=(const string& lhs, const string& rhs) {
        return !(lhs == rhs);
    }
    
    
    bool operator<(const string& lhs, const string& rhs) {
        std::pair<std::vector<char>::iterator, std::vector<char>::iterator> mismatch;
        
        string tempLhs = lhs;
        string tempRhs = rhs;
        
        mismatch = std::mismatch(tempLhs.strBuffer.begin(), tempLhs.strBuffer.end(), tempRhs.strBuffer.begin());
        
        if (mismatch.first == tempLhs.strBuffer.end()) return false; // they are equal
        
        // mismatch characters determine if lhs < rhs
        if (*mismatch.first < *mismatch.second)
            return true;
        
        return false;
    }
    
    
    bool operator<=(const string& lhs, const string& rhs) {
        return (lhs < rhs && lhs == rhs);
        
    }
    
    
    bool operator>(const string& lhs, const string& rhs) {
        return !(lhs <= rhs);
    }
    
    
    bool operator>=(const string& lhs, const string& rhs) {
        return (lhs > rhs && lhs == rhs);
    }
    
     //friend ostream overloaded operator
    std::ostream& operator<<(std::ostream& os, const string& str) {
        
        for (int i = 0; str.strBuffer[i] != '\0'; i++) {
            os << str.strBuffer[i];
        }
        
        return os;
    }
    
    //friend istream overloaded operator
    std::istream& operator>>(std::istream& is, string& str) {
        char character;
        
        is.get(character);
        str.strBuffer.resize(0);
        
        while (character != ' ' && character != '\n' && character != '\t') {
            str.strBuffer.push_back(character);
            is.get(character);
        }
        str.strBuffer.push_back('\0');
        
        return is;
    }
    
    
};