#include "TNode2.h"
#pragma once
class CircularDoubleLinkedList {
    private:
        TNode2* head;

    public:
        CircularDoubleLinkedList();
        CircularDoubleLinkedList(CircularDoubleLinkedList& other);
        ~CircularDoubleLinkedList();

        void Push(int value);
        void Pop(TNode2* node);
        void printList();

        TNode2* getHead();

        void findMaxIncreasing();
};
