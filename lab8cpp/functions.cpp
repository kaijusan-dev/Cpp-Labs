#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "functions.h"

void findAnswer(int a[15][15], int cnt[15][15], int k, int w, std::vector<int>& weights, std::vector<int>& result) {
    if (k == 0 || w == 0) return;

    if (a[k][w] == a[k-1][w] && cnt[k][w] == cnt[k-1][w]) {
        findAnswer(a, cnt, k-1, w, weights, result);
    }
    else {
        result.push_back(k);
        findAnswer(a, cnt, k-1, w - weights[k], weights, result);
    }
}

void printMatrix(int a[15][15], int number, int weight) {
    using namespace std;

    cout << "k\\w" << '\t';
    for (int i = 0; i <= weight; i++)
        cout << i << '\t';
    cout << endl;

    for (int i = 0; i <= number; i++) {
        cout << i << '\t';
        for (int j = 0; j <= weight; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

void BackRec9() {
    using namespace std;

    int a[15][15];
    int cnt[15][15];
    int weight, number;

    vector<int> weights, volumes;

    cout << "\nEnter filename: ";
    string filename;
    cin >> filename;
    cout << endl;

    ifstream in(filename);

    in >> number >> weight; // N и B
    in.ignore();

    weights.push_back(0);
    volumes.push_back(0);

    for (int i = 0; i < number; i++) {
        int w;
        in >> w;
        weights.push_back(w);
    }

    for (int i = 0; i < number; i++) {
        int v;
        in >> v;
        volumes.push_back(v);
    }

    in.close();

    // заполнение нулями первой строки и первого столбца
    for (int i = 0; i <= weight; i++) {
        a[0][i] = 0;
        cnt[0][i] = 0;
    }

    for (int i = 0; i <= number; i++) {
        a[i][0] = 0;
        cnt[i][0] = 0;
    }

    // заполнение таблицы динамического программирования
    for (int k = 1; k <= number; k++) {
        for (int s = 1; s <= weight; s++) {

            a[k][s] = a[k-1][s];
            cnt[k][s] = cnt[k-1][s];

            if (s >= weights[k]) {

                int newWeight = a[k-1][s - weights[k]] + weights[k];
                int newCount  = cnt[k-1][s - weights[k]] + 1;

                if (newWeight > a[k][s] || (newWeight == a[k][s] && newCount > cnt[k][s])) {
                    a[k][s] = newWeight;
                    cnt[k][s] = newCount;
                }
            }
        }
    }

    int bestWeight = a[number][weight];

    printMatrix(a, number, weight);

    vector<int> result;

    findAnswer(a, cnt, number, bestWeight, weights, result);

    cout << "Indexes of artefacts: ";
    for (int i : result)
        cout << i << " ";
    cout << endl;

    int totalVolume = 0;

    for (int i : result)
        totalVolume += volumes[i];

    cout << "Total weight: " << bestWeight << endl;
    cout << "Total volume: " << totalVolume << endl;
}

void HomeDyn3() {
    using namespace std;
    int a[80][80], N;

    cout << "\nEnter filename: ";
    string filename;
    cin >> filename;

    ifstream in(filename);
    in >> N;
    in.ignore();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> a[i][j];
        }
    }

    in.close();

    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }


    int m[80][80];

    m[N-1][N-1] = a[N-1][N-1];

    for (int i = N-2; i >= 0; i--) {
        m[i][N-1] = m[i+1][N-1] + a[i][N-1];
    }

    for (int j = N-2; j >= 0; j--) {
        m[N-1][j] = m[N-1][j+1] + a[N-1][j];
    }

    for (int i = N-2; i >= 0; i--) {
        for (int j = N-2; j >= 0; j--) {
            m[i][j] = max(m[i+1][j], m[i][j+1]) + a[i][j];
        }
    }

    int i = 0, j = 0;
    string path = "";

    while (i < N-1 || j < N-1) {

        if (i == N-1) {
            path += "L";
            j++;
        }
        else if (j == N-1) {
            path += "U";
            i++;
        }
        else if (m[i+1][j] > m[i][j+1]) {
            path += "U";
            i++;
        }
        else {
            path += "L";
            j++;
        }
    }

    reverse(path.begin(), path.end());

    cout << "\nPath: " << path << endl;
    cout << "Max sum: " << m[0][0] << endl;
    cout << "Result Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nEnter filename for result: ";
    cin >> filename;

    ofstream out(filename);

    out << m[0][0] << endl;
    out << path << endl;

    out.close();
    cout << "Result was saved to file " << filename << endl;
}

void HomeDyn13() {
    using namespace std;
    int i, k, n;
    cout << "\nEnter k (base) and n (digits amount): ";
    cin >> k >> n;

    double nz, _nz, oz, _oz;

    nz = k - 1;
    oz = 0;

    for (i = 2; i <= n; i++) {
        _nz = nz * (k - 1) + oz * (k - 1);
        _oz = nz;

        nz = _nz;
        oz = _oz;

    }   
    cout << "\nAmount of numbers without two zero in a row: " << nz + oz << endl;
}