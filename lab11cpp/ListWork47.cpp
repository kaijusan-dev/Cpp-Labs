#include "TListB.h"
#include "ListWork47.h"
#include <string>
#include <iostream>
#include <fstream>

void getTListBFromConsole(TListB* list, int n) {
    int value;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> value;
        list->LBInsertLast(value);
    }
}

void getTListBFromFile(TListB* list, std::string filename) {
    std::ifstream in(filename);
    int number;
    while (in >> number) list->LBInsertLast(number);
    in.close();
}

void generateTListB(TListB* list, int n) {
    for (int i = 0; i < n; i++) {
        int random = rand() %101;
        list->LBInsertLast(random);
    }
}

void inputTListB(TListB* list) {
    using namespace std;
    cout << "\nHow to get list? (1 = from console, 2 = from file, 3 = generate random): ";
    int N;
    cin >> N;
    cout << endl;

    switch(N) {
        case 1: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;
            getTListBFromConsole(list, amount);
            break;
        }
        case 2: {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            getTListBFromFile(list, filename);
            break;
        }
        case 3: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;
            generateTListB(list, amount);
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
            break;
        }
    }
}

void ListWork47() {
    using namespace std;

    TListB* list = new TListB();

    inputTListB(list);

    cout << "Original list: ";
    list->printList();
    cout << endl;

    cout << "Enter N: ";
    int N;
    cin >> N;

    cout << "Enter numbers: ";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        list->LBInsertLast( x);
    }

    cout << "Modified list: ";
    list->printList();
    cout << endl;

    cout << "Current element address: " << list->getCurrent() << endl;

    delete list;
}