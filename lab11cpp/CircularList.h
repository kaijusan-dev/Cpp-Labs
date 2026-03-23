#include "TNode.h"
#pragma once
class CircularList {
    private:
        TNode* head;

    public:
        CircularList();
        CircularList(CircularList& other);
        ~CircularList();

        void Push(int value);
        void Pop(TNode* node);
        void printList();

        TNode* getHead();
};
