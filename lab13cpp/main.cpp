#include <iostream>
#include "STL3Alg5.h"
#include "STL3Alg26.h"
#include "STL3Alg40.h"
#include "STL3Alg60.h"
#include <list>
#include "io.h"

int main() {
    using namespace std;

    int n;
    list<int> L;

    do {
        cout << "Enter a number of task (1 = STL3Alg5, 2 = STL3Alg26, 3 = STL3Alg40, 4 = STL3Alg60, 0 = exit): ";
        cin >> n;
        switch(n) {
            case 0: {
                cout << "You exited";
                break;
            }
            case 1: {
                L = getList();
                STL3Alg5(L);
                break;
            }
            case 2: {
                L = getList();
                STL3Alg26(L);
                break;
            }
            case 3: {
                L = getList();
                STL3Alg40(L);
                break;
            }
            case 4: {
                L = getList();
                STL3Alg60(L);
                break;
            }
            default: {
                cout << "You entered wrong number" << endl;
            }
        }
    } while(n != 0);

}