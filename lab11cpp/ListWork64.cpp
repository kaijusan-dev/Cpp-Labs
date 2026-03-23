#include "DoubleLinkedList.h"
#include "ListWork64.h"
#include <string>
#include <iostream>
#include <fstream>

void getDoubleListFromConsole(DoubleLinkedList* list, int n) {
    int value;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> value;
        list->Push(value);
    }
}

void getDoubleListFromFile(DoubleLinkedList* list, std::string filename) {
    std::ifstream in(filename);
    int number;
    while (in >> number) list->Push(number);
    in.close();
}

void generateDoubleList(DoubleLinkedList* list, int n) {
    for (int i = 0; i < n; i++) {
        int random = rand() %101;
        list->Push(random);
    }
}

void inputDoubleList(DoubleLinkedList* list) {
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
            getDoubleListFromConsole(list, amount);
            break;
        }
        case 2: {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            getDoubleListFromFile(list, filename);
            break;
        }
        case 3: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;
            generateDoubleList(list, amount);
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
            break;
        }
    }
}

void ListWork64() {
    using namespace std;

    DoubleLinkedList* list = new DoubleLinkedList();
    inputDoubleList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    TNode2* P1 = list->getHead();

    if (!P1) {
        return;
    }

    cout << "Enter filename: ";
    string filename;
    cin >> filename;

    ofstream out(filename);

    do {
        TNode2* current = P1;

        out << current->getData() << " ";

        TNode2* temp = current;

        while (current->getNext() != nullptr) current = current->getNext();

        out << current->getData() << " " << endl;

        TNode2* temp2 = current;

        P1 = P1->getNext();

        list->Pop(temp);
        list->Pop(temp2);

    } while(P1 != nullptr && P1->getNext() != nullptr);

    delete list;
}