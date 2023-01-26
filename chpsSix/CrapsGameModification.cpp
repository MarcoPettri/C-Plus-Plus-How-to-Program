//6.47 Exercise: Craps Game Modification
/*
	Modify the craps program of Fig. 6.9 to allow wagering. 
	Package as a function the portion of the program that runs one game of craps. 
	Initialize variable bank-Balance to 1000 dollars. Prompt the player to enter a wager. 
	Use a while loop to check that wager is less than or equal to bankBalance and, if not, 
	prompt the user to reenter wager until a valid wager is entered. After a correct wager is entered,
	run one game of craps. If the player wins, increase bank-Balance by wager and print the new bankBalance. 
	If the player loses, decrease bankBalance by wager, print the new bankBalance, 
	check on whether bankBalance has become zero and, if so, print the message "Sorry. You busted!" 
	As the game progresses, print various messages to create some "chatter" such as "Oh, you're going for broke, huh?",
	"Aw cmon, take a chance!" or "You're up big. Now's the time to cash in your chips!".
*/

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time

bool crapsGame();
unsigned int rollDice(); // rolls dice, calculates and displays sum

int CrapsGameModificaction() {
    char answer{ ' ' };
    bool game{ crapsGame() };
  

    while ((answer != 'n') && game) {

        std::cout << "\nanother bet?(y/n): ",
            std::cin >> answer;

        if(answer == 'n') { 
            std::cout << "\nAw cmon, take a chance!"
                << "\nanother bet?(y/n): ",
                std::cin >> answer;
        }
        game = crapsGame();
    }

    return 0;
}

bool crapsGame() {
    // scoped enumeration with constants that represent the game status 
    enum class Status { CONTINUE, WON, LOST }; // all caps in constants

    // randomize random number generator using current time
    std::srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{ 0 }; // point if no win or loss on first roll
    Status gameStatus; // can be CONTINUE, WON or LOST


    static int bankBalance{ 1'000 };
    std::cout << "Initial Bank Balance: " << bankBalance << std::endl;
    int wager;
    do {
        std::cout << "\nEnter the wager : ",
            std::cin >> wager;
    } while (wager > bankBalance);

    unsigned int sumOfDice{ rollDice() }; // first roll of the dice
    // determine game status and point (if needed) based on first roll
    switch (sumOfDice) {
    case 7: // win with 7 on first roll
    case 11: // win with 11 on first roll           
        gameStatus = Status::WON;
        bankBalance += wager;
        break;
    case 2: // lose with 2 on first roll
    case 3: // lose with 3 on first roll
    case 12: // lose with 12 on first roll             
        gameStatus = Status::LOST;
        bankBalance -= wager;
        break;
    default: // did not win or lose, so remember point
        gameStatus = Status::CONTINUE; // game is not over
        myPoint = sumOfDice; // remember the point
        std::cout << "Point is " << myPoint << std::endl;
        break;  
    }

    // while game is not complete
    while (Status::CONTINUE == gameStatus) { // not WON or LOST
        sumOfDice = rollDice(); // roll dice again

        // determine game status
        if (sumOfDice == myPoint) { // win by making point
            gameStatus = Status::WON;
            bankBalance += wager;
           
        }
        else if (sumOfDice == 7) { // lose by rolling 7 before point
            gameStatus = Status::LOST;
            bankBalance -= wager;
        
        }
    }

    // display won or lost message
    if (Status::WON == gameStatus) {
        std::cout << "Player wins\n"
            << "You're up big. Now's the time to cash in your chips!" 
            << std::endl
            << "New Balance: " << bankBalance
            << std::endl;
        return true;
    }
    else {
        std::cout << "Player loses" << std::endl;
        std::cout << "New Balance: " << bankBalance 
            << std::endl;
        if (bankBalance > 0) { return true; }
        else {
            std::cout << "Sorry. You busted!";
            return false;
        }
    }
}

// roll dice, calculate sum and display results
unsigned int rollDice() {
    int die1{ 1 + rand() % 6 }; // first die roll
    int die2{ 1 + rand() % 6 }; // second die roll
    int sum{ die1 + die2 }; // compute sum of die values

    // display results of this roll
    std::cout << "Player rolled " << die1 << " + " << die2
        << " = " << sum << std::endl;
    return sum;
}