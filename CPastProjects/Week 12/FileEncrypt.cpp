// FileEncrypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


//Function Prototypes.
void openFile(void);


int main()
{    
	 
	openFile();	

}

void openFile()
{     
	//Declare variables and stream.
	
	ifstream inputFile;
	ofstream outputFile; 

	char data;
	string encrypt;
	string Newencrypt;

	
	//Opening files for input and output. 
	inputFile.open("f:\\encrypt.dat");
	outputFile.open("f:\\Newencrypt.dat");	 
	
	while(inputFile)
	{
		inputFile.get(data);
	}
	while(inputFile)
		{
			data += 10;  //Adding 10 to the first character data in the original file.
			outputFile.put(data);  //Writing data character to the outputfile.
			inputFile.get(data); //Reading next character in from original file. Continue through loop till complete.

		}		
	system("pause");

}

