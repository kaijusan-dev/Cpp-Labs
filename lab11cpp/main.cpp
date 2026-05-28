#include <iostream>
#include <limits>
#include "ListWork68.h"
#include "ListWork42.h"
#include "ListWork64.h"
#include "ListWork47.h"
#include "5.h"

int main() {
    using namespace std;

    int n;

    do {

        cout << "\nEnter a number of task (1 = ListWork68, 2 = ListWork42, 3 = ListWork64, 4 = ListWork47, 5 = task5, 0 = exit): ";
        cin >> n;

        if (cin.fail()) {
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
                    ListWork68();
                    break;
                }

                case 2: {
                    ListWork42();
                    break;
                }

                case 3: {
                    ListWork64();
                    break;
                }

                case 4: {
                    ListWork47();
                    break;
                }

                case 5: {
                    task5();
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
    } while (n!=0);

}