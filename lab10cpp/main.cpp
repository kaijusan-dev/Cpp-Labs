#include <iostream>
#include "Dynamic13.h"
#include "Dynamic14.h"
#include "ListWork11,24,61.h"
#include "TNode.h"

int main() {
    using namespace std;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    switch(n) {
        case 1: {
            Dynamic13();
            break;
        }
        case 2: {
            Dynamic14();
            break;
        }
        case 3: {
            TNode* result;
            result = ListWork11();
            if (result != nullptr) cout << "Result is not nullptr" << endl;
            else cout << "Result is nullptr" << endl;
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
        default:
            cout << "You entered wrong number" << endl;
    }


}