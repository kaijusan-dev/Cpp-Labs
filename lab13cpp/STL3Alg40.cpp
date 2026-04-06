#include <iostream>
#include <algorithm>
#include <list>
#include "io.h"
#include "STL3Alg40.h"

// Дан список L. Определить количество четных и нечетных чисел в исходном
// списке (вначале вывести количество четных, затем количество нечетных чисел). Использовать
// алгоритм partition и два вызова функции distance для итераторов.

void STL3Alg40(std::list<int>& L) {
    using namespace std;

    cout << "Original list: ";
    printList(L);

    auto it = partition(L.begin(), L.end(), [](int x){return x % 2 == 0;});

    //partition возвращает итератор на первый элемент нечетных чисел (элементы, которые не прошли проверку предиката)
    int even_count = distance(L.begin(), it);
    int odd_count = distance(it, L.end());

    cout << "Modified list: ";
    printList(L);

    cout << "Even elements count: " << even_count << endl;
    cout << "Odd elements count: " << odd_count << endl;

}