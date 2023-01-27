// 4.37 Exercise: Enforcing Privacy with Cryptography

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;  using std::swap;


string encrypts(string data) {

	string dataEncrypt{ "" };

	for (auto digit : data) {
 
		// Converts from string to int and from int to string again.
		dataEncrypt += ((static_cast<int>(digit -48) + 7) % 10) +48;
	}
	
	swap(dataEncrypt[0], dataEncrypt[2]),
		swap(dataEncrypt[1], dataEncrypt[3]);

	return dataEncrypt;
}

string decrypts(string data) {

	string dataDecrypt{ "" };

	for (auto digit : data) {

		// Converts from string to int and from int to string again.
		dataDecrypt += ((static_cast<int>(digit - 48) + 3) % 10) + 48;
	}
	
	swap(dataDecrypt[0], dataDecrypt[2]),
		swap(dataDecrypt[1], dataDecrypt[3]);

	return dataDecrypt;
}

int Crypthograpy() {

	
	string data{ "" };

	while(true) {

		cout << "Enter a four-digit number: ",
			cin >> data;

		if (data.size() == 4) {

			cout << "The encrypted integer is " << encrypts(data) 
				<< "\n" << endl;
			break;
		}
		else {
			cout << "The number must be have four digits\n" << endl;
		
		}
	}

	while(true) {

		cout << "Enter the four-digit number to decrypt: ",
			cin >> data;

		if (data.size() == 4) {
			cout << "The decrypted number is " << decrypts(data)
				<< "\n" << endl;
			break;
		}
		else {
			cout << "The number must be have four digits\n" << endl;
		}
	}


	return 0;
}
