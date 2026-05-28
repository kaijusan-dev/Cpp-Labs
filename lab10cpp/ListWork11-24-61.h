#pragma once
#include <string>
#include "TNode.h"

class List {
    private:
        TNode* head;

    public:
        List();
        List(List& other);
        ~List();
        void Push(int D);
        int Pop();
        bool ListIsEmpty();
        int Peek();
        void printList();
        TNode* getHead();
        void setHead(TNode* newHead);
        void findByValue(int value);
};

void getListFromConsole(List* list, int n);
void getListFromFile(List* list, std::string filename);
void generateList(List* list, int n);

void inputList(List* list);

void ListWork11();
void ListWork24();
void insertSorted(List* list, int number);
void ListWork61();
