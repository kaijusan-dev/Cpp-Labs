// Дан список L, количество элементов которого делится на 3. Добавить в конец
// списка первую треть его исходных элементов в обратном порядке. Использовать один вызов
// функции-члена insert.

#include <iostream>
#include <list>
#include "io.h"
#include "STL2Seq10.h"

void STL2Seq10() {
    using namespace std;

    list<int> L;
    inputList(L);
    cout << endl;

    cout << "List: ";
    printList(L);

    int n = L.size() / 3;

    auto it = L.begin();
    advance(it, n);

    L.insert(L.end(), make_reverse_iterator(it), make_reverse_iterator(L.begin()));

    cout << "Modified List: ";
    printList(L);
}