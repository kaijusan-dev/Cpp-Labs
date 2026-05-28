#include <iostream>
#include <fstream>
#include <random>

struct Node {
    int key;
    Node *left, *right;
};
void addToTree(Node*& root, int data);
void printTree(Node*& root, int h = 0);

//обратный обход (лев, кор, прав)
void printTreeInOrder(Node*& root);

void printKLevel(Node* root, int k);
int countKLevel(Node* root, int k);

Node* inputFromConsole();
Node* inputFromFile(const std::string& filename);
Node* inputRandom();
Node* getTree();
