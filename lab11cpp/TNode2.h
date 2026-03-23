#pragma once

class TNode2 {
    private:
        int data;
        TNode2* next;
        TNode2* prev;
        
    public:
        TNode2(int value);

        int getData();
        void setData(int value);

        TNode2* getNext();
        void setNext(TNode2* node);

        TNode2* getPrev();
        void setPrev(TNode2* node);
};