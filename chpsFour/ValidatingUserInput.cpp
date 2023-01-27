// 4.40 exercise: Validate User Input

#include<iostream>

using std::cout; using std::cin; using std::endl;

int ValidateUserInput() {

    // initializing variables in declarations
    unsigned int passes{ 0 };
    unsigned int failures{ 0 };
    unsigned int studentCounter{ 1 };

    int result{ 0 };

    while (studentCounter <= 10) {

        cout << "Enter result (1 = pass, 2 = fail): ";
        cin >> result;
        cout << studentCounter << endl;
        if (result == 1) {
            passes++;
        }
	    else if (result == 2) {
            failures++;
        }
	    else {
            cout << "The result must be 1 or 2" << endl;
   
        }
        if (result == 1 || result == 2) {
            studentCounter++;
        }
	}
    
    cout << "Passed: " << passes << "\nFailed: " << failures << endl;

    // determine whether more than 8 students passed
    if (passes > 8) {
        cout << "Bonus to instructor!" << endl;
    }




	return 0;
}