#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "classes.h"

void task1() {
    using namespace std;

    cout << "\n===== ЗАДАЧА 1.3 =====\n";

    Name name1("Клеопатра");
    Name name2("Александр", "Пушкин", "Сергеевич");
    Name name3("Владимир", "Маяковский");

    cout << name1.toString() << endl;
    cout << name2.toString() << endl;
    cout << name3.toString() << endl;

    cout << endl;
}

void task2() {
    using namespace std;
    
    cout << "\n===== ЗАДАЧА 2.2 =====\n";

    Person person1(Name("Клеопатра"), 152);
    Person person2(Name("Александр", "Пушкин", "Сергеевич"), 167);
    Person person3(Name("Владимир", "Маяковский"), 189);

    cout << person1.toString() << endl;
    cout << person2.toString() << endl;
    cout << person3.toString() << endl;

    cout << "\n===== ЗАДАЧА 2.3 =====\n";

    Person ivan(Name("Иван", "Чудов"), 180);

    Person petr(Name("Петр"), 175, &ivan);

    Person boris(Name("Борис"), 170, &petr);

    cout << ivan.toString() << endl;
    cout << petr.toString() << endl;
    cout << boris.toString() << endl;

    cout << endl;
}

void task3() {
    using namespace std;

    cout << "\n===== ЗАДАЧА 3.2 =====\n";

    Point* point1 = new Point(1, 5);
    Point* point2 = new Point(2, 8);
    Point* point3 = new Point(5, 3);

    Polyline line1({point1, point2, point3});

    Point* point4 = new Point(2, -5);
    Point* point5 = new Point(4, -8);

    Polyline line2({point1, point4, point5, point3});

    cout << line1.toString() << endl;
    cout << line2.toString() << endl;

    point1->setX(100);
    point1->setY(100);

    cout << "\nПосле изменения общей точки:\n";

    cout << line1.toString() << endl;
    cout << line2.toString() << endl;

    cout << endl;
}

void task5() {
    using namespace std;

    cout << "\n===== ЗАДАЧА 5.7 =====\n";

    Polyline line({new Point(1,5), new Point(2,8), new Point(5,3)});

    cout << line.toString() << endl;

    cout << "Длина этой линии: " << line.length() << endl;

    line.addPoints({new Point(5,15), new Point(8,10)});

    cout << "\nПосле добавления точек:\n";

    cout << line.toString() << endl;

    cout << "Длина линии стала: " << line.length() << endl;

    cout << endl;
}

int main() {
    using namespace std;

    int n;
    do {
        cout << "Enter a number of task (1, 2, 3, 5, or 0 = exit): ";
        cin >> n;
        switch(n) {
            case 0: {
                cout << "You exited";
                break;
            }
            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            case 3: {
                task3();
                break;
            }
            case 5: {
                task5();
                break;
            }
            default: {
                cout << "You entered wrong number" << endl;
            }
        }
    } while(n != 0);
}