// 6.38 Exercise: Towers of Hanoi

#include<vector>
#include<iostream>



typedef  std::vector<std::vector<int>> vector;

void towerOfHanoi(int, vector&, vector&, vector&);

int Towers_Of_Hanoi() {
	std::cout << "peg 1 to peg 3" << std:: endl;

	vector peg1{ {1}, {3, 2, 1 } };
	vector peg2{ {2}, {} };
	vector peg3{ {3}, {} };
	
	towerOfHanoi(3, peg1, peg2, peg3);

	return 0;
}



void towerOfHanoi(int numDisk, vector&  fromPeg,
	vector& toPeg, vector& auxPeg) {

	if (numDisk > 0) {

		towerOfHanoi(numDisk - 1, fromPeg, auxPeg, toPeg);

		toPeg.at(1).push_back(fromPeg.at(1).back());
		fromPeg.at(1).pop_back();

		std::cout << fromPeg.at(0).at(0)
			<< " --> " << toPeg.at(0).at(0)
			<< std::endl;

		towerOfHanoi(numDisk - 1, auxPeg, toPeg, fromPeg);

	}

}