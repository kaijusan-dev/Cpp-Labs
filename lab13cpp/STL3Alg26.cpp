#include <iostream>
#include <algorithm>
#include <list>
#include "io.h"
#include "STL3Alg26.h"

// Дан список L с четным количеством элементов. Скопировать в конец списка все
// элементы, расположенные в его первой половине, заменив при этом отрицательные элементы
// на нули и расположив скопированные элементы в обратном порядке. Использовать алгоритм
// replace_copy_if, итератор вставки и обратные итераторы, а также функцию advance.

void STL3Alg26(std::list<int>& L) {
    using namespace std;

    cout << "Original list: ";
    printList(L);
    
    if (L.size() % 2 != 0) {
        cout << "List must have an even number of elements\n";
        return;
    }

    auto mid = L.begin();
    //передвигаем до середины
    advance(mid, L.size() / 2);

    auto rbegin_half = make_reverse_iterator(mid);
    auto rend_half = make_reverse_iterator(L.begin());

    replace_copy_if(rbegin_half, rend_half, back_inserter(L), [](int x) {return x < 0;}, 0);

    cout << "Modified list: ";
    printList(L);

}