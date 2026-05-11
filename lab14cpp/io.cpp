#include "io.h"
#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> inputFromConsole() {
    using namespace std;
    vector<int> V;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }

    return V;
}

std::vector<int> inputFromFile(const std::string& filename) {
    using namespace std;
    vector<int> V;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File open error!\n";
        return V;
    }

    int x;
    while (file >> x) {
        V.push_back(x);
    }

    file.close();
    return V;
}

std::vector<int> inputRandom(int n = 0) {
    using namespace std;
    vector<int> V;

    if (n == 0) {
        cout << "Enter the number of elements: ";
        cin >> n; 
    }

    for (int i = 0; i < n; i++) {
        V.push_back(rand() % 21 - 11);
    }

    return V;
}

std::vector<int> getVector() {
    using namespace std;
    vector<int> V;
    int n;

    cout << "How to get a Vector? (1 = Console, 2 = File, 3 = Random): ";
    cin >> n;
    switch(n) {
        case 1: {
            V = inputFromConsole();
            break;
        }
        case 2: {
            V = inputFromFile("vector.txt");
            break;
        }
        case 3: {
            V = inputRandom();
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
        }
    }

    return V;
}

void printVector(std::vector<int>& V) {
    using namespace std;
    for (int value : V) {
        cout << value << " ";
    }
    cout << endl;
}
