#pragma once

struct TNode {
    int Data;
    TNode* next;
    TNode(int d, TNode* n = nullptr): Data(d), next(n) {};
};
