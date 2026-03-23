// Дан текстовый файл с именем name, содержащий строковые представления целых
// чисел. Вывести числа из исходного файла с нечетными порядковыми номерами (т. е. первое
// число, третье число и т. д.). Использовать алгоритм remove_copy_if.

#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "io.h"
#include "STL1Iter9.h"

void STL1Iter9() {
    using namespace std;

    cout << "Modified List: "; 

    ifstream file("numbers.txt");

    istream_iterator<int> in(file);
    istream_iterator<int> end;

    ostream_iterator<int> out(cout, " ");

    int index = 0;

    remove_copy_if(in, end, out,
        [&index](int) {return index++ % 2 == 1;}
    );
}