#include "TNode.h"

TNode::TNode(int value) {
    data = value;
    next = nullptr;
};

int TNode::getData() {
    return data;
};

void TNode::setData(int value) {
    data = value;
};

TNode* TNode::getNext() {
    return next;
};

void TNode::setNext(TNode* node) {
    next = node;
};