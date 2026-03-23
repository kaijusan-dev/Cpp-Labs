#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"

void File6() {
    using namespace std;
    cout << "\nEnter k (index of element that need to find), n (amount of numbers in file): ";
    int k, n;
    cin >> k >> n;

    string filename;
    cout << "\nEnter name of file: ";
    cin >> filename;

    ofstream out(filename, ios::binary);
    for (int i = 0 ; i < n; i++) {
        out << rand() % 101 << ' ';
    }
    cout << "\nGenerated vector with random numbers >= 0 and saved to file" << endl;
    out.close();

    ifstream in(filename, ios::binary);
    string line;
    while ( in >> line) cout << line;
    cout << endl;

    in.seekg(k , ios::beg);
    char ch; 
    in >> ch;
    cout << "\nElement with index = " << k << ": " << ch;

    in.close();
}

void File39() {
    using namespace std;
    cout << "\nEnter n (amount of numbers): ";
    int n;
    cin >> n;

    string filename;
    cout << "\nEnter name of file: ";
    cin >> filename;

    ofstream out(filename, ios::binary);
    vector<int> numbers;
    for (int i = 0 ; i < n; i++) {
        numbers.push_back(rand() % 51);
    }
    out.write((char*) numbers.data(), numbers.size() * sizeof(int));
    cout << "\nGenerated vector with random numbers in range(0-50) and saved to file" << endl;
    out.close();

    vector<int> modifiedNumbers;

    ifstream in(filename, ios::binary);
    int number, count = 1, result = -1;
    cout << "\nVector of numbers from file: ";
    while ( in.read( (char*)& number, sizeof(int)) ) {
        cout << number << " ";
        if (number >=5 && number <= 10) {
            modifiedNumbers.push_back(number);
            modifiedNumbers.push_back(number);
        }
        else modifiedNumbers.push_back(number);
    }
    cout << endl;
    in.close();

    cout << "\nModified vector where numbers in range (5-10) have doubled: ";
    for (auto& num : modifiedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    ofstream out2(filename, ios::binary);
    out2.write((char*) modifiedNumbers.data(), modifiedNumbers.size() * sizeof(int));
    cout << "\nModified vector have saved to file\n";
    out2.close();
}

void File48() {
    using namespace std;
    cout << "\nEnter n (amount of numbers): ";
    int n;
    cin >> n;

    ofstream out("SA.txt", ios::binary);
    ofstream out2("SB.txt", ios::binary);
    ofstream out3("SC.txt", ios::binary);

    for (int i = 0 ; i < n; i++) {
        int a = rand() % 101;
        int b = rand() % 101;
        int c = rand() % 101;

        out.write((char*)&a, sizeof(int));
        out2.write((char*)&b, sizeof(int));
        out3.write((char*)&c, sizeof(int));
    }
    cout << "\nGenerated 3 vectors with random numbers >= 0 and saved to files SA, SB, SC\n";
    out.close();
    out2.close();
    out3.close();

    ifstream in("SA.txt", ios::binary);
    ifstream in2("SB.txt", ios::binary);
    ifstream in3("SC.txt", ios::binary);
    ofstream out4("SD.txt", ios::binary);

    vector<int> numbersA, numbersB, numbersC;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        in.read((char*)&a, sizeof(int));
        in2.read((char*)&b, sizeof(int));
        in3.read((char*)&c, sizeof(int));

        numbersA.push_back(a);
        numbersB.push_back(b);
        numbersC.push_back(c);

        out4.write((char*)&a, sizeof(int));
        out4.write((char*)&b, sizeof(int));
        out4.write((char*)&c, sizeof(int));
    }

    cout << "\nFiles SA, SB, SC have merged to file SD\n";
    in.close();
    in2.close();
    in3.close();
    out4.close();

    cout << "\nVector of numbers from file SA: ";
    for (int i = 0; i < n; i++) cout << numbersA[i] << " ";
    cout << endl;

    cout << "\nVector of numbers from file SB: ";
    for (int i = 0; i < n; i++) cout << numbersB[i] << " ";
    cout << endl;

    cout << "\nVector of numbers from file SC: ";
    for (int i = 0; i < n; i++) cout << numbersC[i] << " ";
    cout << endl;

    ifstream in4("SD.txt", ios::binary);
    cout << "\nVector of numbers from file SD: ";
    for (int i = 0; i < n*3; i++) {
        int a;
        in4.read((char*)&a, sizeof(int));

        cout << a << " ";
    }
    in4.close();
}

// убрать пробелы из строки
std::string removeSpaces(const std::string& s) {
    std::string res;
    for (char c : s) if (c != ' ') res += c;
    return res;
}

// рекурсивная функция
bool eval(const std::string& s, int& pos) {
    if (s[pos] == 'T') {
        pos++;
        return true;
    }
    if (s[pos] == 'F') {
        pos++;
        return false;
    }

    if (s.substr(pos, 3) == "Not") {
        pos += 4; // пропускаем "Not("
        bool value = eval(s, pos);
        pos++; // пропускаем ')'
        return !value;
    }

    if (s.substr(pos, 3) == "And") {
        pos += 4; // пропускаем "And("
        bool result = true;
        while (true) {
            result = result && eval(s, pos);
            if (s[pos] == ')') { 
                pos++; 
                break; 
            }
            pos++; // пропускаем ','
        }
        return result;
    }

    if (s.substr(pos, 2) == "Or") {
        pos += 3; // пропускаем "Or("
        bool result = false;
        while (true) {
            result = result || eval(s, pos);
            if (s[pos] == ')') { 
                pos++; 
                break; 
            }
            pos++; // пропускаем ','
        }
        return result;
    }

    return false;
}

void Recur24() {
    using namespace std;

    cout << "\nEnter expression: ";
    string s;
    cin.ignore();
    getline(cin, s);
    s = removeSpaces(s);
    int pos = 0;
    bool ans = eval(s, pos);
    cout << "\nResult of expression: ";
    if (ans) cout << "True" << endl;
    else cout << "False" << endl;
}