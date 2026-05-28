#include "tasks.h"
#include "io.h"

// Дан указатель на корень дерева P1 и натуральное число K. Определите количество
// вершин на K-ом уровне. Считать, что нумерация уровней идет от корня сверху вниз и
// начинается с 0.

void TreeWork21() {
    using namespace std;
    
    Node* P1 = getTree();

    cout << "Tree: " << endl;
    printTree(P1, 0);

    cout << endl;

    int k, count;
    cout << "Enter k level: ";
    cin >> k;

    cout << "K level: ";
    printKLevel(P1, k);

    cout << endl;

    cout << "Elements at K level: " << countKLevel(P1, k) << endl;

}