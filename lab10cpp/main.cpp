#include <iostream>
#include <limits>
#include "TNode.h"
#include "Dynamic13.h"
#include "Dynamic14.h"
#include "ListWork11-24-61.h"

int main() {
    using namespace std;

    int n;

    do {

        cout << "\nEnter a number of task (0 = exit, 1 = Dynamic13, 2 = Dynamic14, 3 = ListWork11, 4 = ListWork24, 5 = ListWork61): ";
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
                    Dynamic13();
                    break;
                }

                case 2: {
                    Dynamic14();
                    break;
                }

                case 3: {
                    ListWork11();
                    break;
                }

                case 4: {
                    ListWork24();
                    break;
                }

                case 5: {
                    ListWork61();
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
    } while(n!=0);
    
}