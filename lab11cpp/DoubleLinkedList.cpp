#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList& other) {
    head = nullptr;

    if (!other.head)
        return;

    TNode2* temp = other.head;

    while (temp != nullptr) {
        Push(temp->getData());
        temp = temp->getNext();
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    while (head != nullptr) {
        Pop(head);
    }
}

void DoubleLinkedList::Push(int value) {
    TNode2* newNode = new TNode2(value);

    if (!head) {
        head = newNode;
        newNode->setNext(nullptr);
        newNode->setPrev(nullptr);
        return;
    }

    TNode2* tail = head->getPrev();

    tail->setNext(newNode);
    newNode->setPrev(tail);
    newNode->setNext(nullptr);
}

TNode2* DoubleLinkedList::getHead() {
    return head;
}

void DoubleLinkedList::Pop(TNode2* node) {
    if (!head) return;

    if (head->getNext() == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    TNode2* prev = node->getPrev();
    TNode2* next = node->getNext();

    if (prev) prev->setNext(next);
    if (next) next->setPrev(prev);

    if (node == head) head = next;

    delete node;
}

void DoubleLinkedList::printList() {
    if (!head) return;

    TNode2* current = head;

    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
}