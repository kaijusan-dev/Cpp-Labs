#include "CircularList.h"
#include <iostream>
CircularList::CircularList() {
    head = nullptr;
}

CircularList::CircularList(CircularList& other) {
    head = nullptr;

    if (!other.head)
        return;

    TNode* temp = other.head;

    do {
        Push(temp->getData());
        temp = temp->getNext();
    }
    while (temp != other.head);
}

CircularList::~CircularList() {
    while (head != nullptr) {
        Pop(head);
    }
}

void CircularList::Push(int value) {
    TNode* newNode = new TNode(value);

    if (!head) {
        head = newNode;
        newNode->setNext(head);
        return;
    }

    TNode* temp = head;

    while (temp->getNext() != head) temp = temp->getNext();

    temp->setNext(newNode);
    newNode->setNext(head);
}

TNode* CircularList::getHead() {
    return head;
}

void CircularList::Pop(TNode* node) {
    if (!head) return;

    // если один элемент
    if (head->getNext() == head) {
        delete head;
        head = nullptr;
        return;
    }

    TNode* current = head;

    // ищем предыдущий элемент
    while (current->getNext() != node) current = current->getNext();

    current->setNext(node->getNext());

    if (node == head) head = node->getNext();

    delete node;
}

void CircularList::printList() {
    if (!head) return;
    TNode* current = head;
    while (current->getNext() != head) {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
    std::cout << current->getData() << " ";
}