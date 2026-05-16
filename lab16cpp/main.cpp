#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "tasks.h"

int main() {
    using namespace std;

    int n;
    do {
        cout << "Enter a number of task (1 = TreeWork2, 2 = TreeWork13, 3 = TreeWork21, 0 = exit): ";
        cin >> n;
        switch(n) {
            case 0: {
                cout << "You exited";
                break;
            }
            case 1: {
                TreeWork2();
                break;
            }
            case 2: {
                TreeWork13();
                break;
            }
            case 3: {
                TreeWork21();
                break;
            }
            default: {
                cout << "You entered wrong number" << endl;
            }
        }
    } while(n != 0);

}