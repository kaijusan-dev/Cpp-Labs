#include <iostream>
#include "ListWork68.h"
#include "ListWork42.h"
#include "ListWork64.h"
#include "ListWork47.h"
#include "5.h"

int main() {
    using namespace std;

    int n;
    cout << "Enter a number of task (1 = ListWork68, 2 = ListWork42, 3 = ListWork64, 4 = ListWork47, 5 = task5, 0 = exit): ";
    cin >> n;

    switch(n) {
        case 0: {
            cout << "You exited";
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
            cout << "You entered wrong number" << endl;
        }
    }


}