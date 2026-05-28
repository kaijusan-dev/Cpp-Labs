#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "STL5Assoc17.h"
#include "io.h"

void STL5Assoc17() {
    using namespace std;

    cout << "Getting vector V" << endl;
    vector<string> V = getStringVector();

    cout << "Vector V: ";
    printStringVector(V);

    map<char, int> M;

    for (vector<string>::iterator it = V.begin(); it != V.end(); ++it) {
        M[(*it)[0]] += it->size();
    }

    for (map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}
