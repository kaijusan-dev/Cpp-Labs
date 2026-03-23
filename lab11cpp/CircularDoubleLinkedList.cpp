#include "CircularDoubleLinkedList.h"
#include <iostream>
CircularDoubleLinkedList::CircularDoubleLinkedList() {
    head = nullptr;
}

CircularDoubleLinkedList::CircularDoubleLinkedList(CircularDoubleLinkedList& other) {
    head = nullptr;

    if (!other.head)
        return;

    TNode2* temp = other.head;

    do {
        Push(temp->getData());
        temp = temp->getNext();
    }
    while (temp != other.head);
}

CircularDoubleLinkedList::~CircularDoubleLinkedList() {
    while (head != nullptr) {
        Pop(head);
    }
}

void CircularDoubleLinkedList::Push(int value) {
    TNode2* newNode = new TNode2(value);

    if (!head) {
        head = newNode;
        newNode->setNext(head);
        newNode->setPrev(head);
        return;
    }

    TNode2* tail = head->getPrev();

    tail->setNext(newNode);
    newNode->setPrev(tail);

    newNode->setNext(head);
    head->setPrev(newNode);
}

TNode2* CircularDoubleLinkedList::getHead() {
    return head;
}

void CircularDoubleLinkedList::Pop(TNode2* node) {
    if (!head) return;

    if (head->getNext() == head) {
        delete head;
        head = nullptr;
        return;
    }

    TNode2* prev = node->getPrev();
    TNode2* next = node->getNext();

    prev->setNext(next);
    next->setPrev(prev);

    if (node == head) head = next;

    delete node;
}

void CircularDoubleLinkedList::printList()
{
    if (!head) return;

    TNode2* current = head;

    do {
        std::cout << current->getData() << " ";
        current = current->getNext();
    } while (current != head);
}

void CircularDoubleLinkedList::findMaxIncreasing() {
    if (!head) return;

    //размер списка
    int n = 1;
    TNode2* temp = head->getNext();
    while (temp != head) {
        n++;
        temp = temp->getNext();
    }

    int currLen = 1;
    int maxLen = 1;

    TNode2* currStart = head;
    TNode2* maxStart = head;

    TNode2* current = head;

    for (int i = 0; i < n; i++) {
        TNode2* next = current->getNext();

        if (current->getData() < next->getData()) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxStart = currStart;
            }
            currLen = 1;
            currStart = next;
        }

        current = next;
    }

    if (currLen > maxLen) {
        maxLen = currLen;
        maxStart = currStart;
    }

    std::cout << "Result: ";
    TNode2* p = maxStart;
    for (int i = 0; i < maxLen; i++) {
        std::cout << p->getData() << " ";
        p = p->getNext();
    }
}