/////////////////////////////////////////////////////////////////////
/// cipher.hpp 
/// 
/// This file contains the definition of the class CaesarCipher
/// for encryption and decryption of simple texts with a given value
/// of shift/key.
/////////////////////////////////////////////////////////////////////
#ifndef __CIPHER_H
#define __CIPHER_H

#define DEFAULT_SHIFT_VALUE 5

#include <string>
#include <iostream>

using namespace std;

/**
 * Class definition that implements the encryption and decryption
 * of plain texts/files using caesar cipher algorithm.
 */
class CaesarCipher {
public:
	/**
	 * Class constructor that takes the value of shift
	 * as the parameter.
	 */
	CaesarCipher(int shift);

	/**
	 * Encrypt a given plain text and return the encrypted
	 * cipher text.
	 */
	string encrypt(string plain);

	/**
	 * Decrypt a given cipher text and return the decrypted
	 * plain text.
	 */
	string decrypt(string cipher);

	/*
	 * Change the shift value for the encryption/decryption
	 */
	void setShift(const int& shift);

private:
	int shift;
};
#endif
