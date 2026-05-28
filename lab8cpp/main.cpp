#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "functions.h"
using namespace std;

int main() {
    int n = -1;
    while (n != 0) {
        cout << "\nEnter the number of task( 1 = BackRec9, 2 = HomeDyn3, 3 = HomeDyn13, 0 - Exit ): ";
        cin >> n;

        if (cin.fail()) {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a NUMBER.\n";
            continue;
        }

        switch (n) {
            case 0: {
                break;
            }
            case 1: {
                BackRec9();
                break;
            }
            case 2: {
                HomeDyn3();
                break;
            }
            case 3: {
                HomeDyn13();
                break;
            }
            default: {
                cout << "Incorrect number, try again" << endl;
                break;
            } 
        }
    }
    return 0;
}