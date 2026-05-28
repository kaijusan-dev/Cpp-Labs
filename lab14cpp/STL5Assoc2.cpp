#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "STL5Assoc2.h"
#include "io.h"

void STL5Assoc2() {
    using namespace std;

    cout << "Getting vector V0" << endl;
    vector<int> V0 = getIntVector();

    cout << "Getting vectors V1...VN" << endl;
    vector<vector<int>> vectors = getIntVectors();

    set<int> baseSet(V0.begin(), V0.end());

    int count = 0;

    for (vector<vector<int>>::iterator it = vectors.begin(); it != vectors.end(); ++it)
    {
        set<int> currentSet(it->begin(), it->end());

        if (includes(
            currentSet.begin(),
            currentSet.end(),
            baseSet.begin(),
            baseSet.end())
        ) {
            count++;
        }
    }

    cout << "Vector V0: ";
    printIntVector(V0);

    cout << "Vectors V1...N: " << endl;
    printIntVectors(vectors);

    cout << "Count of vectors that contain all elements of V0: " << count << endl;
}
