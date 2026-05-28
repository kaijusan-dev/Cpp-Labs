#include "io.h"
#include <iostream>
#include <fstream>
#include <random>

std::list<int> inputFromConsole() {
    using namespace std;
    list<int> L;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        L.push_back(x);
        if (cin.fail()) {
            throw 1;
        }
    }

    return L;
}

std::list<int> inputFromFile(const std::string& filename) {
    using namespace std;
    list<int> L;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File open error!\n";
        return L;
    }

    int x;
    while (file >> x) {
        L.push_back(x);
    }

    file.close();
    return L;
}

std::list<int> inputRandom() {
    using namespace std;
    list<int> L;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    for (int i = 0; i < n; i++) {
        L.push_back(rand() % 21 - 11);
    }

    return L;
}

std::list<int> getList() {
    using namespace std;
    list<int> L;
    int n;

    cout << "How to get a List? (1 = Console, 2 = File, 3 = Random): ";
    cin >> n;
    if (cin.fail()) {
        throw 1;
    }

    switch(n) {
        case 1: {
            L = inputFromConsole();
            break;
        }
        case 2: {
            L = inputFromFile("list.txt");
            break;
        }
        case 3: {
            L = inputRandom();
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
        }
    }

    return L;
}

void printList(std::list<int>& L) {
    using namespace std;
    for (int value : L) {
        cout << value << " ";
    }
    cout << endl;
}
