// 4.18 Exercise: Tabuler Output 

#include<iostream>

using std::cout; using std::cin; using std::endl;

int TabulerOutput() {


	cout << "N \t 5*N \t 10*N \t 15*N" << endl;


	for (int i = 1; i < 13; i++) {

		cout << i << " \t "
			<< i * 5 << " \t "
			<< i * 10 << " \t "
			<< i * 15 << " \t "
			<< endl;
	}
	return 0;
}