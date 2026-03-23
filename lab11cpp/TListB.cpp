#include "TListB.h"
#include <iostream>
TListB::TListB() {
    barrier = new TNode2(0);
    barrier->setNext(barrier);
    barrier->setPrev(barrier);
    current = nullptr;
}

TListB::TListB(TListB& other) {
    barrier = nullptr;

    if (!other.barrier)
        return;

    TNode2* temp = other.barrier;

    do {
        LBInsertLast(temp->getData());
        temp = temp->getNext();
    }
    while (temp != other.barrier);
}

TListB::~TListB() {
    if (!barrier) return;

    TNode2* temp = barrier->getNext();

    while (temp != barrier) {
        TNode2* next = temp->getNext();
        delete temp;
        temp = next;
    }

    delete barrier;
}

void TListB::LBInsertLast(int value) {
    TNode2* newNode = new TNode2(value);

    TNode2* last = barrier->getPrev();

    newNode->setNext(barrier);
    newNode->setPrev(last);

    last->setNext(newNode);
    barrier->setPrev(newNode);

    current = newNode;
}

TNode2* TListB::getBarrier() {
    return barrier;
}

TNode2* TListB::getCurrent() {
    return current;
}

void TListB::Pop(TNode2* node) {
    if (node == barrier) return;

    TNode2* prev = node->getPrev();
    TNode2* next = node->getNext();

    prev->setNext(next);
    next->setPrev(prev);

    delete node;
}

void TListB::printList() {
    if (!barrier) return;

    TNode2* temp = barrier->getNext(); 

    while (temp != barrier) {
        std::cout << temp->getData() << " ";
        temp = temp->getNext();
    }
}