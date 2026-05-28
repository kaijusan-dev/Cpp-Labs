#include <iostream>
#include <limits>
#include "STL5Assoc2.h"
#include "STL5Assoc17.h"
#include "STL5Assoc21.h"

int main() {
    using namespace std;

    int n;
    do {
        cout << "\nEnter a number of task (1 = STL5Assoc2, 2 = STL5Assoc17, 3 = STL5Assoc21, 0 = exit): ";

        if (!(cin >> n)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a NUMBER.\n";
            continue;
        }

        try {

            switch(n) {

                case 0: {
                    cout << "You exited\n";
                    break;
                }

                case 1: {
                    STL5Assoc2();
                    break;
                }

                case 2: {
                    STL5Assoc17();
                    break;
                }

                case 3: {
                    STL5Assoc21();
                    break;
                }

                default: {
                    cout << "You entered wrong number\n";
                }
            }

        }
        catch (...) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Input error. Returning to menu...\n";
        }

    } while (n != 0);

}