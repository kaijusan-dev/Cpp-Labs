// Дан набор целых чисел. Заполнить список L исходными числами и вывести
// элементы списка L вначале в исходном, а затем в обратном порядке.

#include <iostream>
#include <list>
#include "io.h"
#include "STL2Seq2.h"

void STL2Seq2() {
    using namespace std;

    list<int> L;
    inputList(L);
    cout << endl;

    cout << "List: ";
    printList(L);

    cout << "Reverse: ";
    for (list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); ++it) {
        cout << *it << " ";
    }
}