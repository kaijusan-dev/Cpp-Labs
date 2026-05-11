#include <iostream>
#include "STL5Assoc2.h"
#include "STL5Assoc17.h"
#include "STL5Assoc21.h"
#include "io.h"
#include <vector>

int main() {
    using namespace std;

    int n;
    do {
        cout << "Enter a number of task (1 = STL5Assoc2, 2 = STL5Assoc17, 3 = STL5Assoc21, 0 = exit): ";
        cin >> n;
        switch(n) {
            case 0: {
                cout << "You exited";
                break;
            }
            case 1: {
                cout << "Getting vector V0" << endl;
                vector<int> V0 = getVector();

                cout << "Vector V0: ";
                printVector(V0);

                vector<vector<int>> VN;
                int N; 

                cout << "How much vectors in VN: ";
                cin >> N;

                if (N < 1) {
                    cout << "N must be > 0" << endl;
                    break;
                }

                cout << "How to get vectors in VN? (1 = Each vector in 3 ways, 2 = Random all vectors): ";
                int n1;
                cin >> n1;

                vector<int> VI;

                switch(n1) {
                    case 1: {
                        for (int i = 1; i <= N ; i++) {
                            VI = getVector();
                            cout << "Vector V" << i << ": ";
                            VN.push_back(VI);
                            printVector(VI);
                        }
                        STL5Assoc2(V0, VN);
                        break;
                    }
                    case 2: {
                        cout << "Enter size for all vectors: ";
                        int nn;
                        cin >> nn;
                        for (int i = 1; i <= N ; i++) {
                            VI = inputRandom(nn);
                            cout << "Vector V" << i << ": ";
                            VN.push_back(VI);
                            printVector(VI);
                        }
                        STL5Assoc2(V0, VN);
                        break;
                    }
                    default: {
                        cout << "You entered wrong number" << endl;
                    }
                }
                break;
            }
            // case 2: {
            //     STL5Assoc17();
            //     break;
            // }
            // case 3: {
            //     STL5Assoc21();
            //     break;
            // }
            default: {
                cout << "You entered wrong number" << endl;
            }
        }
    } while(n != 0);

}