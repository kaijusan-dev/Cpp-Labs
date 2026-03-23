#include "TNode2.h"
#pragma once
class DoubleLinkedList {
    private:
        TNode2* head;
        TNode2* tail;
    public:
        DoubleLinkedList();
        DoubleLinkedList(DoubleLinkedList& other);
        ~DoubleLinkedList();

        void Push(int value);
        void Pop(TNode2* node);
        void printList();

        TNode2* getHead();
};
