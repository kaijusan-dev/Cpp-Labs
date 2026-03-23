#include <iostream>
#include <fstream>
#include "ListWork11-24-61.h"
#include "TNode.h"

List::List() {
    head = nullptr;
}

List::List(List& other) : head(nullptr) {
    if (other.head == nullptr)
        return;

    TNode* current = other.head;
    int count = 0;

    while (current) {
        count++;
        current = current->next;
    }

    int* temp = new int[count];
    current = other.head;

    for (int i = count - 1; i >= 0; i--) {
        temp[i] = current->Data;
        current = current->next;
    }

    for (int i = 0; i < count; i++) {
        Push(temp[i]);
    }

    delete[] temp;
}

List::~List() {
    while (head) {
        TNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::Push(int D) {
    TNode* newNode = new TNode(D, head);
    head = newNode;
}

int List::Pop() {
    TNode* temp = head;
    int value = temp->Data;
    head = head->next;
    delete temp;
    return value;
}

bool List::ListIsEmpty() {
    return head == nullptr;
}

int List::Peek() {
    if (head) {
        return head->Data;
    }
    return 0;
}

void List::printList() {
    TNode* current = head;
    while (current) {
        std::cout << current->Data << " ";
        current = current->next;
    }
}

TNode* List::getHead() {
    return head;
}

void List::setHead(TNode* newHead) {
    head = newHead;
}

void List::findByValue(int value) {
    using namespace std;
    int count= 0;
    if (!ListIsEmpty()) {
        TNode* current = head;
        while (current && current->Data != value) {
            current = current->next;
            count++;
        }
        if (current) {
            cout << "Element found: " << endl;
            cout << "\tIndex of element: " << count;
            cout << "\tAddress of element: " << current;
        }
        else {
            cout << "Element is not found" << endl;
        }
    }
}

void getListFromConsole(List* list, int n) {
    int value;
    for (int i = 0 ; i < n ; i++) {
        std::cin >> value;
        list->Push(value);
    }
}

void getListFromFile(List* list, std::string filename) {
    std::ifstream in(filename);
    int number;
    while (in >> number) list->Push(number);
    in.close();
}

void generateList(List* list, int n) {
    for (int i = 0; i < n; i++) {
        int random = rand() %101;
        list->Push(random);
    }
}

void inputList(List* list) {
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

void ListWork11() {
    using namespace std;

    List* list = new List();
    inputList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    TNode* P1 = list->getHead();

    TNode* current = P1;
    while (current) {
        if (current->Data % 5 == 0);
        current = current->next;
    }

    if (current) cout << "Result is not nullptr" << endl;
    else cout << "Result is nullptr" << endl;
}

void ListWork24() {
    using namespace std;

    List* list = new List();
    inputList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    TNode* P1 = list->getHead();

    cout << "Enter M: ";
    int M;
    cin >> M;

    TNode* current = P1;
    int count = 0;

    while (current) {
        count++;
        if (count %4 == 0) {
            TNode* newNode = new TNode(M, current->next);
            current->next = newNode;
            current = newNode->next;
        } else {
            current = current->next;
        }
    }

    TNode* P2 = P1;
    while(P2->next) P2 = P2->next;

    cout << "Last element address (P2): " << P2 << endl;

    cout << "New List: ";
    list->printList();
    cout << endl;
}

void insertSorted(List* list, int number) {
    TNode* newNode = new TNode(number);

    TNode* head = list->getHead();

    if (!head || number < head->Data) {
        newNode->next = head;
        list->setHead(newNode);
        return;
    }

    TNode* current = head;

    while (current->next && current->next->Data < number) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void ListWork61() {
    using namespace std;

    cout << "Enter filename: ";
    string filename;
    cin >> filename;

    ifstream in(filename);
    string line;

    int N;
    in >> N;

    List* list = new List();
    for (int i = 0; i < N; i++) {
        int number;
        in >> number;
        insertSorted(list, number);
    }
    in.close();

    cout << "Sorted List: ";
    list->printList();
    cout << endl;
}