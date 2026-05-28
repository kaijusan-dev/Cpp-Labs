#include "tasks.h"
#include "io.h"

// Дан указатель P1 на корень непустого дерева. Листом дерева называется его
// вершина, не имеющая дочерних вершин. Вывести количество листьев для данного дерева.

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void TreeWork13() {
    using namespace std;
    
    Node* P1 = getTree();

    cout << "Tree: " << endl;
    printTree(P1, 0);

    cout << endl;

    cout << "Tree leaves count: " << countLeaves(P1) << endl;

}