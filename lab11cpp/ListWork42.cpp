#include "CircularDoubleLinkedList.h"
#include "ListWork42.h"
#include <string>
#include <iostream>
#include <fstream>

void getCircularDoubleListFromConsole(CircularDoubleLinkedList* list, int n) {
    int value;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> value;
        list->Push(value);
    }
}

void getCircularDoubleListFromFile(CircularDoubleLinkedList* list, std::string filename) {
    std::ifstream in(filename);
    int number;
    while (in >> number) list->Push(number);
    in.close();
}

void generateCircularDoubleList(CircularDoubleLinkedList* list, int n) {
    for (int i = 0; i < n; i++) {
        int random = rand() %101;
        list->Push(random);
    }
}

void inputCircularDoubleList(CircularDoubleLinkedList* list) {
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
            getCircularDoubleListFromConsole(list, amount);
            break;
        }
        case 2: {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            getCircularDoubleListFromFile(list, filename);
            break;
        }
        case 3: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;
            generateCircularDoubleList(list, amount);
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
            break;
        }
    }
}

void ListWork42() {
    using namespace std;

    CircularDoubleLinkedList* list = new CircularDoubleLinkedList();
    inputCircularDoubleList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    TNode2* P1 = list->getHead();

    if (!P1 || P1->getNext() == P1 || P1->getNext()->getNext() == P1) {
        cout << "List too small\n";
        return;
    }

    TNode2* current = P1;
    do {
        TNode2* prev = current->getPrev();
        TNode2* next = current->getNext();

        if (prev->getData() == next->getData()) {
            if (current == P1) P1 = next;

            prev->setNext(next);
            next->setPrev(prev);
            TNode2* next = current->getNext();
            delete current;
            current = next;
            continue;
        }
        current = current->getNext();
    } while(current != P1);

    cout << "Modified list: ";
    list->printList();
    cout << endl;

    cout << "Last element address: " << P1->getPrev();
    delete list;
}