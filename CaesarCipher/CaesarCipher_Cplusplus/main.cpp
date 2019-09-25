/////////////////////////////////////////////////////////////////////
/// main.cpp 
/// 
/// This file contains code for the main program which demonstrates
/// use of caesar cipher algorithm as a menu driven interactive program.
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include "cipher.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
	int shift;               // variable to read user input for shift value from keyboard
	CaesarCipher* cipher;    // instance of CaesarCipher to performing encryption/decryption
	int choice;              // variable to read menu choice from user keyboard
	bool exit;               // flag to indicate exit the program
	string plainText;        // plain text
	string cipherText;       // cipher text
	string filename;         // name of file to be encrypted

	// display welcome message of the program
	welcomeMessage();

	exit = false;
	shift = DEFAULT_SHIFT_VALUE;

	cipher = new CaesarCipher(shift);

	// loop of the user interaction
	while (!exit)
	{
		// display menu choice to user
		printMenu();

		// read menu choice from user
		cout << "Enter menu choice [0 - 5]: ";
		cin >> choice;
		getline(cin, plainText);

		// execute the menu choice action
		switch (choice)
		{
		case 0:
			exit = true;
			break;
		case 1:
			cout << "Enter plain text (only english alphabets): ";
			getline(cin,plainText);
			cipherText = cipher->encrypt(plainText);
			cout << "Encrypted Text:" << endl;
			cout << cipherText << endl;
			break;
		case 2:
			cout << "Enter cipher text (only english alphabets): ";
			getline(cin,cipherText);
			plainText = cipher->decrypt(cipherText);
			cout << "Decrypted Text:" << endl;
			cout << plainText << endl;
			break;
		case 3:
			cout << "Enter name of the text file to be encrypted: ";
			cin >> filename;
			plainText = readTextFileContent(filename);
			cout << "Original file content:" << endl;
			cout << plainText << endl;
			cipherText = cipher->encrypt(plainText);
			writeTextFile(filename + ".encrypted", cipherText);
			cout << "Encrypted file content:" << endl;
			cout << cipherText << endl;
			cout << "Encrypted file has been written to " << (filename + ".encrypted") << endl;
			break;
		case 4:
			cout << "Enter name of the text file to be decrypted: ";
			cin >> filename;
			cipherText = readTextFileContent(filename);
			cout << "Original file content:" << endl;
			cout << cipherText << endl;
			plainText = cipher->decrypt(cipherText);
			cout << "Decrypted file content:" << endl;
			cout << plainText << endl;
			writeTextFile(filename + ".decrypted", plainText);
			cout << "Decrypted file has been written to " << (filename + ".decrypted") << endl;
			break;
		case 5:
			cout << "Enter value of shift: ";
			cin >> shift;
			cipher->setShift(shift);
			break;
		default:
			cout << "Invalid menu choice!" << endl;
			break;
		}
	}

	return 0;
}
