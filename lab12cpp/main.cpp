#include <iostream>
#include <limits>
#include "STL2Seq2.h"
#include "STL2Seq10.h"
#include "STL2Seq33.h"
#include "STL1Iter9.h"

int main() {
    using namespace std;

    int n;

    do {
        cout << "Enter a number of task (1 = STL2Seq2, 2 = STL2Seq10, 3 = STL2Seq33, 4 = STL1Iter9, 0 = exit): ";

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
                    STL2Seq2();
                    break;
                }

                case 2: {
                    STL2Seq10();
                    break;
                }

                case 3: {
                    STL2Seq33();
                    break;
                }

                case 4: {
                    STL1Iter9();
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