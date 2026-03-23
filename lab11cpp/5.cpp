#include "CircularDoubleLinkedList.h"
#include "5.h"
#include "ListWork42.h"
#include <string>
#include <iostream>
#include <fstream>


void task5() {
    using namespace std;

    CircularDoubleLinkedList* list = new CircularDoubleLinkedList();
    inputCircularDoubleList(list);

    cout << "List: ";
    list->printList();
    cout << endl;

    list->findMaxIncreasing();
}