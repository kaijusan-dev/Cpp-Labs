#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "io.h"

// Дан вектор V0, целое число N (> 0) и набор векторов V1, …, VN. Известно, что
// размер вектора V0 не превосходит размера любого из векторов V1, …, VN. Найти количество
// векторов VI, I = 1, …, N, в которых содержатся все элементы вектора V0 (без учета их
// повторений). Использовать алгоритм includes, применяя его в цикле к двум множествам, одно
// из которых создано на основе вектора V0, а другое на очередной итерации содержит элементы
// очередного из векторов VI, I = 1, …, N.

void STL5Assoc2(std::vector<int>& V0, std::vector<std::vector<int>>& VN) {
    using namespace std;

    //множество из вектора V0 чтобы не учитывать повторяющиеся элементы и все элементы были по порядку для includes
    set<int> S0(V0.begin(), V0.end());

    int count = 0;

    for (auto& VI : VN) {
        set<int> SI(VI.begin(), VI.end()); // текущий вектор без повторов и отсортирован

        if (includes(SI.begin(), SI.end(), S0.begin(), S0.end())) {
            count++;
        }
    }

    cout << "Count of vectors that include V0: " << count << endl;
}
