#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <random>
#include "io.h"

void addToTree(Node*& root, int data) {
    if (!root) {
        root = new Node;
        root->key = data;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (data < root->key) addToTree(root->left, data);
    else addToTree(root->right, data);
}

int transform(std::string s) {
    if(s == "+") return -1;
    if(s == "-") return -2;
    if(s == "*") return -3;
    if(s == "/") return -4;
    if(s == "^") return -5;
    return stoi(s);
}

char printing(int x) {
    if(x == -1) return '+';
    if(x == -2) return '-';
    if(x == -3) return '*';
    if(x == -4) return '/';
    if(x == -5) return '^';
}

void printTree(Node*& root, int h) {
    if (!root) return;

    printTree(root->right, h+1);
    for (int i = 0; i <= h; i++) {
        std::cout << std::setw(4) << '  ';
    }
    if (root->key < 0) {
        std::cout << std::setw(4) << printing(root->key) << std::endl;
    } 
    else {
        std::cout << std::setw(4) << root->key << std::endl;
    }
    std::cout << root->key << std::endl;
    printTree(root->left, h+1);
}

int calculate(Node* root) {
    if(root->key >= 0) return root->key;
    switch (root->key) {
        case -1: return calculate(root->left) + calculate(root->right);
        case -2: return calculate(root->left) - calculate(root->right);
        case -3: return calculate(root->left) * calculate(root->right);
        case -4: return calculate(root->left) / calculate(root->right);
        case -5: return (int)pow(calculate(root->left), calculate(root->right));
    }
}

void del(Node* root) {
    if(!root) return;
    del(root->left);
    del(root->right);
    delete root;
}

int priority(char operation) {
    if(operation == '+' || operation == '-') return 1;
    if(operation == '*' || operation == '/' || operation == '%') return 1;
    if(operation == '+' || operation == '-' || operation == '-') return 1;
    if(operation == '+' || operation == '-') return 1;
}

//обратный обход (лев, кор, прав)
void printTreeInOrder(Node*& root) {
    if (!root) return;
    printTreeInOrder(root->left);
    std::cout << root->key << " ";
    printTreeInOrder(root->right);
}

void printKLevel(Node* root, int k) {
    if (!root) return;

    if (k == 0) {
        std::cout << root->key << " ";
        return;
    }

    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}

int countKLevel(Node* root, int k) {
    if (!root) return 0;

    if (k == 0) return 1;

    return countKLevel(root->left, k - 1) + countKLevel(root->right, k - 1);
}

Node* inputFromConsole() {
    using namespace std;
    Node* root = nullptr;;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        addToTree(root, x);
    }

    return root;
}

Node* inputFromFile(const std::string& filename) {
    using namespace std;
    Node* root = nullptr;;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File open error!\n";
        return root;
    }

    int x;
    while (file >> x) {
        addToTree(root, x);
    }

    file.close();
    return root;
}

Node* inputRandom() {
    using namespace std;
    Node* root = nullptr;;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        addToTree(root, rand() % 21 - 11);
    }

    return root;
}

Node* getTree() {
    using namespace std;
    Node* root = nullptr;;
    int n;

    cout << "How to get a Tree? (1 = Console, 2 = File, 3 = Random): ";
    cin >> n;
    switch(n) {
        case 1: {
            root = inputFromConsole();
            break;
        }
        case 2: {
            root = inputFromFile("tree.txt");
            break;
        }
        case 3: {
            root = inputRandom();
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
        }
    }

    return root;
}

