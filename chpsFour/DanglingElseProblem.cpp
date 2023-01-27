// 4.22

#include <iostream>

using std::cout; using std::endl;

int main() {
    unsigned int x{ 5 };
    unsigned int y{ 8 };

    if (y % 2) {
        if (x % 2) {
            cout << "XxXxX" << endl;
        }
        else {
            cout << "OxOxO\n"
                << "YyYyY\n";
        }
    }

   cout << "-!-!-" << endl;
}