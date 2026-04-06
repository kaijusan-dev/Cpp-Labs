#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include "io.h"
#include "STL3Alg60.h"

// Дан список L. Получить вектор V вещественных чисел, содержащий значения
// среднего арифметического для всех пар соседних элементов исходного списка (количество
// элементов вектора V должно быть на 1 меньше количества элементов списка L). Например,
// для исходного списка 1, 3, 4, 6 полученный вектор должен содержать значения 2.0, 3.5, 5.0.
// Использовать алгоритм adjacent_difference с итератором вставки и функциональным объектом,
// а также функцию-член erase для вектора V.

void STL3Alg60(std::list<int>& L) {
    using namespace std;

    cout << "Original list: ";
    printList(L);

    vector<double> V;

    adjacent_difference(L.begin(), L.end(), back_inserter(V), [](int prev, int current) {return (current + prev) / 2.0;});

    //adjacent_difference копирует первый элемент, удаляем
    if (!V.empty()) {
        V.erase(V.begin());
    }

    cout << "Vector: ";
    for (double x : V) {
        cout << x << " ";
    }
    cout << endl;

}