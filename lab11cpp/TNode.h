#pragma once

class TNode {
    private:
        int data;
        TNode* next;

    public:
        TNode(int value);

        int getData();
        void setData(int value);

        TNode* getNext();
        void setNext(TNode* node);
};