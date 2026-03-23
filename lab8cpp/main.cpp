#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"
using namespace std;

int main() {
    int n = -1;
    while (n != 0) {
        cout << "Enter the number of task( 1 = BackRec9, 2 = HomeDyn3, 3 = HomeDyn13, 0 - Exit ): ";
        cin >> n;
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