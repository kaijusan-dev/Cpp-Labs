#include <iostream>
#include <fstream>
#include "ListWork11,24,61.h"
#include "TNode.h"

class List {
    private:
        TNode* head;

    public:
        List() : head(nullptr) {}

        ~List() {
            while (head) {
                TNode* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void Push(int D) {
            TNode* newNode = new TNode(D, head);
            head = newNode;
        }

        int Pop() {
            TNode* temp = head;
            int value = temp->Data;
            head = head->next;
            delete temp;
            return value;
        }

        bool ListIsEmpty() {
            return head == nullptr;
        }

        int Peek() {
            if (head) {
                return head->Data;
            }
        }

        void printList() {
            TNode* current = head;
            while (current) {
                std::cout << current->Data << " ";
                current = current->next;
            }
        }

        TNode* getHead() {
            return head;
        }

        void setHead(TNode* newHead) {
            head = newHead;
        }
};

void generateList(List& list, int n) {
    for (int i = 0; i < n; ++i) {
        list.Push(i);
    }
}

TNode* ListWork11() {
    using namespace std;

    List* list = new List();
    generateList(*list, 10);

    cout << "List: ";
    list->printList();
    cout << endl;

    TNode* P1 = list->getHead();

    TNode* current = P1;
    while (current) {
        if (current->Data % 5 == 0) return current;
        current = current->next;
    }
    return nullptr;
}

void ListWork24() {
    using namespace std;

    List* list = new List();
    generateList(*list, 10);

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

    cout << "List: ";
    list->printList();
    cout << endl;
}