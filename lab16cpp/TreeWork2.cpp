#include "tasks.h"
#include "io.h"

// Дано дерево поиска и указатель корень дерева P1. Необходимо вывести
// содержимое дерева в возрастающем порядке.

void TreeWork2() {
    using namespace std;
    
    Node* P1 = getTree();

    cout << "Tree: " << endl;
    printTree(P1, 0);

    cout << endl;

    cout << "Elements of tree in order: ";
    printTreeInOrder(P1);

    cout << endl;
}