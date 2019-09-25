/////////////////////////////////////////////////////////////////////
/// cipher.cpp 
/// 
/// This file contains the implmentation of the class CaesarCipher
/// for encryption and decryption of simple texts with a given value
/// of shift/key.
/////////////////////////////////////////////////////////////////////
#include "cipher.hpp"

CaesarCipher::CaesarCipher(int shift)
{
	this->shift = shift;
}

string CaesarCipher::encrypt(string plain)
{
	string cipher = "";

	for (int i = 0; i < plain.length(); i++)
	{
		if (isupper(plain[i]))
		{
			cipher += (char)((((int)plain[i] + shift - 65) % 26) + 65);
		}
		else if(islower(plain[i]))
		{
			cipher += (char)((((int)plain[i] + shift - 97) % 26) + 97);
		}
		else
		{
			cipher += plain[i];
		}
	}
	return cipher;
}

string CaesarCipher::decrypt(string cipher)
{
	string plain = "";
	for (int i = 0; i < cipher.length(); i++)
	{
		if (isupper(cipher[i]))
		{
			plain += (char)((((int)cipher[i] + (26 - shift) - 65) % 26) + 65);
		}
		else if (islower(cipher[i]))
		{
			plain += (char)((((int)cipher[i] + (26 - shift) - 97) % 26) + 97);
		}
		else
		{
			plain += cipher[i];
		}
	}
	return plain;
}

void CaesarCipher::setShift(const int& shift)
{
	this->shift = shift;
}
