#include "CircularList.h"
#include "ListWork68.h"
#include <string>
#include <iostream>
#include <fstream>

void getListFromConsole(CircularList* list, int n) {
    int value;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> value;
        list->Push(value);
    }
}

void getListFromFile(CircularList* list, std::string filename) {
    std::ifstream in(filename);
    int number;
    while (in >> number) list->Push(number);
    in.close();
}

void generateList(CircularList* list, int n) {
    for (int i = 0; i < n; i++) {
        int random = rand() %101;
        list->Push(random);
    }
}

void inputList(CircularList* list) {
    using namespace std;
    cout << "\nHow to get list? (1 = from console, 2 = from file, 3 = generate random): ";
    int N;
    cin >> N;
    cout << endl;

    if (cin.fail()) {
        throw 1;
    }

    switch(N) {
        case 1: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;
            getListFromConsole(list, amount);
            break;
        }
        case 2: {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            getListFromFile(list, filename);
            break;
        }
        case 3: {
            cout << "Enter number of elements: ";
            int amount;
            cin >> amount;
            generateList(list, amount);
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
            break;
        }
    }
}

// Дано кольцо (односвязный циклический список) и указатель на первый
// элемент этого списка. Создать текстовый файл, в который вывести содержимое этого
// списка с шагом 4: сначала первый элемент списка, потом пятый, далее девятый и т.д. В
// общем случае: выводить i-й элемент, а за ним (i+4)-й элемент. Если список
// заканчивается, продолжать нумерацию с начала списка. После вывода очередного числа
// удалять его в списке. Вывод про должать до тех пор, пока в списке есть числа.

void ListWork68() {
    using namespace std;

    CircularList* list = new CircularList();
    inputList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    TNode* P1 = list->getHead();

    cout << "Enter filename to record list with step = 4: ";
    string filename;
    cin >> filename;

    ofstream out(filename);

    while(list->getHead() != nullptr) {
        out << P1->getData() << " ";
        TNode* next = P1->getNext();
        list->Pop(P1);
        P1 = next;
        for (int i = 0; i < 3; i++) P1 = P1->getNext();
    }

    out.close();

    getListFromFile(list, filename);

    cout << "Read list from file: ";
    list->printList();
    cout << endl;

    delete list;
}