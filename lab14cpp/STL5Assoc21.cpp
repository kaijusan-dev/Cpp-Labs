#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "STL5Assoc21.h"
#include "io.h"

void STL5Assoc21() {
    using namespace std;

    cout << "Getting vector V" << endl;
    vector<int> V = getIntVector();

    cout << "Vector V: ";
    printIntVector(V);

    multimap<int, int> M;

    for (vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        int key = abs(*it % 10);

        M.insert(make_pair(key, *it));
    }

    for (multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}
