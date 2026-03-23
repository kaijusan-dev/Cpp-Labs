#include "TNode2.h"
#pragma once
class TListB {
    private:
        TNode2* barrier;
        TNode2* current;
    public:
        TListB();
        TListB(TListB& other);
        ~TListB();

        void LBInsertLast(int value);
        void Pop(TNode2* node);
        void printList();

        TNode2* getBarrier();
        TNode2* getCurrent();
};
