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

    if (cin.fail()) {
        throw 1;
    }

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

// Даны указатели P1 и P2 на барьерный и текущий элементы двусвязного
// списка (о списке с барьерным элементом см. задание ListWork46). Также дано число N (>
// 0) и набор из N чисел. Описать тип TListB — запись с полями Barrier и Current типа PNode
// (поля указывают соответственно на барьерный и текущий элементы списка) — и
// процедуру LBInsertLast(L, D), которая добавляет новый элемент со значением D в конец
// списка L (L — входной и выходной параметр типа TListB, D — входной параметр целого
// типа). Добавленный элемент становится текущим. С помощью этой процедуры добавить
// в конец исходного списка данный набор чисел (в том же порядке) и вывести адрес
// текущего элемента полученного списка.

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

    if (cin.fail()) {
        throw 1;
    }

    cout << "Enter numbers: ";
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        list->LBInsertLast( x);

        if (cin.fail()) {
            throw 1;
        }
    }

    cout << "Modified list: ";
    list->printList();
    cout << endl;

    cout << "Current element address: " << list->getCurrent() << endl;

    delete list;
}