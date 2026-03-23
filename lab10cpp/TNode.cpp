#include "TNode.h"

struct TNode {
    int Data;
    TNode* next;
    TNode(int d, TNode* n = nullptr) : Data(d), next(n) {}
};


TNode::TNode(int d, TNode* n = nullptr) : Data(d), next(n) {}
