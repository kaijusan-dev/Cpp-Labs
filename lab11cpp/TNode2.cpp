#include "TNode2.h"

TNode2::TNode2(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
};

int TNode2::getData() {
    return data;
};

void TNode2::setData(int value) {
    data = value;
};

TNode2* TNode2::getNext() {
    return next;
};

TNode2* TNode2::getPrev() {
    return prev;
};

void TNode2::setNext(TNode2* node) {
    next = node;
};

void TNode2::setPrev(TNode2* node) {
    prev = node;
};