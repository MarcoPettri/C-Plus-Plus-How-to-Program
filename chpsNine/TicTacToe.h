// TicTacToe.H
/*
	TicTacToe Class for exercise 9.15: TicTacToe Class
*/


#ifndef TicTacToe_H
#define TicTacToe_H

#include<vector>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<random>
#include<chrono>
#include<thread>
#include<limits>

class TicTacToe
{
public:
	
	TicTacToe();

	void play();
	void display() const;

private:
	std::vector<int> table;
	std::vector<int> players;
	int player;
	int winner;

	bool check(int, int);
};


#endif // !TicTacToe_H
