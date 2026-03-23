#include <iostream>
#include "STL2Seq2.h"
#include "STL2Seq10.h"
#include "STL2Seq33.h"
#include "STL1Iter9.h"

int main() {
    using namespace std;

    int n;
    cout << "Enter a number of task (1 = STL2Seq2, 2 = STL2Seq10, 3 = STL2Seq33, 4 = STL1Iter9, 0 = exit): ";
    cin >> n;

    switch(n) {
        case 0: {
            cout << "You exited";
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
            cout << "You entered wrong number" << endl;
        }
    }


}