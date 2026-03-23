// Дан список L с элементами A1, A2, A3, …, AN−1, AN (N — четное). Изменить
// порядок элементов в списке на следующий: AN, A1, AN−1, A2, AN−2, …, AN/2, AN/2−1. Для
// этого использовать два итератора i и r, связав их с первым и последним элементом списка. В
// цикле, который должен повторяться N/2 раз, вызывать функцию-член splice с первым
// параметром i++ и третьим параметром r--.

#include <iostream>
#include <list>
#include "io.h"
#include "STL2Seq33.h"

void STL2Seq33() {
    using namespace std;

    list<int> L;
    inputList(L);
    cout << endl;

    cout << "List: ";
    printList(L);

    auto i = L.begin();
    auto j = --L.end();

    int n = L.size() / 2;

    for (int k = 0; k < n; k++) {
        L.splice(i++, L, j--);
    }

    cout << "Modified List: ";
    printList(L);
}