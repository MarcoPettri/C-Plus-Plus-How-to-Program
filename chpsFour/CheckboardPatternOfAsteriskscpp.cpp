// 4.29 Exercise: CheckBoard Pattern Of Asterisks

#include<iostream>

using std::cout; using std::endl;

int pass() {

	for (int i = 0; i < 8; i++) {

		if (i % 2 == 0) {
			
			for (int x = 0; x < 8; x++) {
				cout << "* ";
			}
		}
		else {
			cout << " ";

			for (int x = 0; x < 8; x++) {
				cout << "* ";
			}
		}
		cout << endl;
	}

	return 0;
}