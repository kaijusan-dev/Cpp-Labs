#include "io.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <random>

std::vector<int> inputIntVectorFromConsole() {
    using namespace std;
    vector<int> V;
    int n, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (cin.fail()) {
            throw 1;
        }
        V.push_back(x);
    }

    return V;
}

std::vector<int> inputIntVectorFromFile(const std::string& filename) {
    using namespace std;
    vector<int> V;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File open error!\n";
        return V;
    }

    int x;
    while (file >> x) {
        V.push_back(x);
    }

    file.close();
    return V;
}

std::vector<int> inputIntVectorRandom() {
    using namespace std;
    vector<int> V;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    for (int i = 0; i < n; i++) {
        V.push_back(rand() % 101 - 101);
    }

    return V;
}

std::vector<int> getIntVector() {
    using namespace std;
    vector<int> V;
    int n;

    cout << "How to get a vector? (1 = Console, 2 = File, 3 = Random): ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    switch(n) {
        case 1: {
            V = inputIntVectorFromConsole();
            break;
        }
        case 2: {
            V = inputIntVectorFromFile("vector.txt");
            break;
        }
        case 3: {
            V = inputIntVectorRandom();
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
        }
    }

    return V;
}

std::vector<std::vector<int>> getIntVectors() {
    using namespace std;

    vector<vector<int>> vectors;

    int N;

    cout << "Enter number of vectors: ";
    cin >> N;

    if (cin.fail()) {
        throw 1;
    }

    for (int i = 0; i < N; i++)
    {
        vectors.push_back(getIntVector());
    }

    return vectors;
}

void printIntVector(std::vector<int>& V) {
    using namespace std;
    for (int value : V) {
        cout << value << " ";
    }
    cout << endl;
}

void printIntVectors(std::vector<std::vector<int>>& vectors) {
    using namespace std;

    for (size_t i = 0; i < vectors.size(); i++)
    {
        cout << "V" << i + 1 << ": ";

        for (int value : vectors[i])
        {
            cout << value << " ";
        }

        cout << endl;
    }
}

std::vector<std::string> inputStringVectorFromConsole() {
    using namespace std;
    vector<string> V;
    int n;
    string x;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }

    return V;
}

std::vector<std::string> inputStringVectorFromFile(const std::string& filename) {
    using namespace std;
    vector<string> V;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File open error!\n";
        return V;
    }

    string x;
    while (file >> x) {
        V.push_back(x);
    }

    file.close();
    return V;
}

std::vector<std::string> inputStringVectorRandom() {
    using namespace std;

    vector<string> V;

    vector<string> words = {
        "APPLE", "ANT", "ANGLE",
        "BOOK", "BALL", "BREAD",
        "CAT", "CANDLE", "CLOUD",
        "DOG", "DRAGON", "DREAM",
        "EAGLE", "EARTH", "ENGINE",
        "FIRE", "FLOWER", "FROST",
        "GAME", "GHOST", "GOLD",
        "HOUSE", "HUNTER", "HEART",
        "ICE", "IMAGE", "ISLAND",
        "JOKER", "JUNGLE", "JACKET"
    };

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    for (int i = 0; i < n; i++) {

        int randomIndex = rand() % words.size();

        V.push_back(words[randomIndex]);
    }

    return V;
}

std::vector<std::string> getStringVector() {
    using namespace std;
    vector<string> V;
    int n;

    cout << "How to get a vector? (1 = Console, 2 = File, 3 = Random): ";
    cin >> n;

    if (cin.fail()) {
        throw 1;
    }

    switch(n) {
        case 1: {
            V = inputStringVectorFromConsole();
            break;
        }
        case 2: {
            V = inputStringVectorFromFile("vector.txt");
            break;
        }
        case 3: {
            V = inputStringVectorRandom();
            break;
        }
        default: {
            cout << "You entered wrong number" << endl;
        }
    }

    return V;
}

std::vector<std::vector<std::string>> getStringVectors() {
    using namespace std;

    vector<vector<string>> vectors;

    int N;

    cout << "Enter number of vectors: ";
    cin >> N;

    if (cin.fail()) {
        throw 1;
    }

    for (int i = 0; i < N; i++) {
        vectors.push_back(getStringVector());
    }

    return vectors;
}

void printStringVector(std::vector<std::string>& V) {
    using namespace std;
    for (string value : V) {
        cout << value << " ";
    }
    cout << endl;
}

void printStringVectors(std::vector<std::vector<std::string>>& vectors) {
    using namespace std;

    for (size_t i = 0; i < vectors.size(); i++)
    {
        cout << "V" << i + 1 << ": ";

        for (string value : vectors[i]) {
            cout << value << " ";
        }

        cout << endl;
    }
}