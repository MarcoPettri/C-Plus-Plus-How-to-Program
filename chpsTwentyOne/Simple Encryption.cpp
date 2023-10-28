// Exercise 21.x: Simple Encryption
/*

		Some information on the Internet may be encrypted with a simple algorithm known as "rot13," 
		which rotates each character by 13 positions in the alphabet. Thus, 'a'
		corresponds to 'n', and 'x' corresponds to 'k'. rot13 is an example of symmetric key encryption.
		With symmetric key encryption, both the encrypter and decrypter use the same key.

		a) Write a program that encrypts a message using rot13.
		b) Write a program that decrypts the scrambled message using rot13 as the key.
*/

#include<iostream>
#include<string>

std::string encrypts(const std::string& str);
std::string decrypts(const std::string& str);

int SIMPLE_ENCRYPTION()
{
	std::string string{ "This is a test" };


	std::string encrypts_str{ encrypts(string) };


	std::cout << "String: " << string << std::endl;


	std::cout << "Encrypts str1: " << encrypts_str << std::endl;


	std::string decrypts_str{ decrypts(encrypts_str) };
	

	if (decrypts_str == string) { 
		std::cout << "True" << std::endl;
	}


	return 0;
}

std::string encrypts(const std::string& str)
{
	std::string encrypt;

	for (const auto& chr : str) {

		int encryptStr{ static_cast<int>(chr) };

		// 32 == ' '
		if (encryptStr != 32) {

			// A to Z -> range = [65, 90]; a to z -> range = [97, 122]
			if (encryptStr > 109 ||
				(encryptStr > 77 && encryptStr < 91)) {

				encrypt.push_back(static_cast<char>(encryptStr - 13));
			}
			else { encrypt.push_back(static_cast<char>(encryptStr + 13)); }
		}
		else { encrypt.push_back(chr); }
	}

	return encrypt;
}

std::string decrypts(const std::string& str) {

	std::string decrypt;

	for (const auto& chr : str) {

		int decryptStr{ static_cast<int>(chr) };

		// 32 == ' '
		if (decryptStr != 32) {

			// a to z -> range = [65, 90]; A to Z -> range = [97, 122]
			if (decryptStr > 109 ||
				(decryptStr > 77 && decryptStr < 91)) {

				decrypt.push_back(static_cast<char>(decryptStr - 13)); 
			}
			else { decrypt.push_back(static_cast<char>(decryptStr + 13)); }
		}
		else { decrypt.push_back(chr); }
	}

	return decrypt;
}