#include <iostream>
#include <list>
#include <fstream>
#include "io.h"

void getListFromConsole(std::list<int>& L, int n) {
    using namespace std;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        L.push_back(value);

        if (cin.fail()) {
            throw 1;
        }
    }
}

void getListFromFile(std::list<int>& L, std::string filename) {
    using namespace std;
    ifstream in(filename);

    int number;
    while (in >> number) {
        L.push_back(number);
    }

    in.close();
}

void generateList(std::list<int>& L, int n) {
    using namespace std;
    for (int i = 0; i < n; i++) {
        int random = rand() % 101;
        L.push_back(random);
    }
}

void inputList(std::list<int>& L) {
    using namespace std;
    cout << "\nHow to get list? (1 = console, 2 = file, 3 = random): ";

    int choice;
    cin >> choice;

    if (cin.fail()) {
        throw 1;
    }

    switch (choice) {

        case 1: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;

            getListFromConsole(L, amount);
            break;
        }

        case 2: {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;

            getListFromFile(L, filename);
            break;
        }

        case 3: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;

            generateList(L, amount);
            break;
        }

        default:
            cout << "Wrong choice\n";
    }
}

void printList(std::list<int>& L) {
    using namespace std;
    for (auto it = L.begin(); it != L.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}