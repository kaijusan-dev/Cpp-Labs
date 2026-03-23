#include <iostream>
#include "functions.h"

int main() {
    using namespace std;

    int n;
    
    while (n != 0) {
        cout << "\nEnter number of task ( 0 = Exit, 1 = File6, 2 = File39, 3 = File48, 4 = Recur24 ): ";
        cin >> n;
        switch(n) {
            case 0: {
                break;
            }
            case 1: {
                File6();
                break;
            }
            case 2: {
                File39();
                break;
            }
            case 3: {
                File48();
                break;
            }
            case 4: {
                Recur24();
                break;
            }
            default: {
                cout << "\nWrong number of task" << endl;
                break;
            }
        }  
    }
}