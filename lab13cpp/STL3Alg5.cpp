#include <iostream>
#include <algorithm>
#include <list>
#include "io.h"
#include "STL3Alg5.h"

// Дан список L, содержащий как отрицательные, так и положительные элементы.
// Вставить нулевой элемент после первого отрицательного элемента и перед последним
// положительным элементом. Использовать два вызова алгоритма find_if и два вызова функции-
// члена insert.

void STL3Alg5(std::list<int>& L) {
    using namespace std;

    cout << "Original list: ";
    printList(L);
    
    auto first_neg = find_if(L.begin(), L.end(), [](int x) {
        return x < 0;
    });

    if (first_neg != L.end()) {
        //позиция после первого отриц элемента, insert вставляет 0 перед следующим элементом, то есть после предыдущего
        L.insert(++first_neg, 0);
    }

    auto last_pos = find_if(L.rbegin(), L.rend(), [](int x) {
        return x > 0;
    });

    if (last_pos != L.rend()) {
        //позиция перед последним полож элементом (.base превращает обратный итератор в прямой и указывает на элемент после)
        L.insert(--last_pos.base(), 0);
    }

    cout << "Modified list: ";
    printList(L);

}
