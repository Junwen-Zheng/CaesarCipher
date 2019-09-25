/////////////////////////////////////////////////////////////////////
/// utils.hpp 
/// 
/// This file contains some utility helper methods which is used by the
/// main program (main.cpp)
/////////////////////////////////////////////////////////////////////
#ifndef __UTILS_H
#define __UTILS_H

#include <iostream>
#include <fstream>

using namespace std;

// Display welcome message to user console when program runs
// with details of what the program is about.
void welcomeMessage()
{
	cout << "*******************************************************" << endl;
	cout << "*   Welcome to Caesar Cipher Encryption/Decryption    *" << endl;
	cout << "*   ----------------------------------------------    *" << endl;
	cout << "* This program demonstrates the use of caesar cipher  *" << endl;
	cout << "* algorithm to encrypt and decrypt texts using shift. *" << endl;
	cout << "*******************************************************" << endl;
}

// Show menu options to user console screen for all the encryption
// decryption operations.
void printMenu()
{
	cout << "MENU:" << endl;
	cout << "1. Encrypt a plain text" << endl;
	cout << "2. Decrypt a cipher text" << endl;
	cout << "3. Encrypt a plain text file" << endl;
	cout << "4. Decrypt a cipher text file" << endl;
	cout << "5. Change value of shift/key" << endl;
	cout << "0. Exit" << endl;
}

// Read and return the content of a text file with given
// file name
string readTextFileContent(string filename)
{
	string content = "";
	string line;
	ifstream fin(filename);

	if (!fin.is_open())
	{
		cout << "File " << filename << " not found!" << endl;		
	}
	else
	{
		while (getline(fin, line))
		{			
			content += line + "\n";
		}
	}
	fin.close();
	return content;
}

// Write content to a text file with given file name
void writeTextFile(string filename, string content)
{
	ofstream fout(filename);
	if (fout.is_open())
	{
		fout << content;
	}
	fout.close();
}

#endif
