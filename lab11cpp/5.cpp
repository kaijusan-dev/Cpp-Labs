#include "CircularDoubleLinkedList.h"
#include "5.h"
#include "ListWork42.h"
#include <string>
#include <iostream>
#include <fstream>

// Создать циклический список. Определить непрерывную возрастающую
// последовательность максимальной длины. Так если в качестве элементов циклического
// списка введены значения:
// 12, 14, 23, 22, -2, -1, -8, -7, 9, -1, 2, 4.
// Последовательность отрицательных элементов максимальной длины будет содержать
// элементы: -1, 2, 4, 12, 14, 23

void task5() {
    using namespace std;

    CircularDoubleLinkedList* list = new CircularDoubleLinkedList();
    inputCircularDoubleList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    list->findMaxIncreasing();
}