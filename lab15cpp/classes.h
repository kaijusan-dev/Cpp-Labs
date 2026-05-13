#include <string>
#include <vector>

class Name {
    private:
        std::string name;
        std::string surname;
        std::string patronymic;

    public:
        Name(std::string name, std::string surname = "", std::string patronymic = "");
        std::string getSurname();
        std::string getName();
        std::string getPatronymic();
        void setName(std::string name);
        void setSurname(std::string surname);
        void setPatronymic(std::string patronymic);
        std::string toString();
};

class Person {
    private:
        Name name;
        int height;
        Person* father;
    public:
        Person(Name name, int height, Person* father = nullptr);
        Name getName();
        std::string toString();
};

class Point {
    private:
        int x;
        int y;
    public:
        Point(int x, int y);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        std::string toString();
};

class Polyline {
    private:
        std::vector<Point*> points;
    public:
        Polyline();
        Polyline(std::vector<Point*> points);
        void addPoints(std::vector<Point*> newPoints);
        int length();
        std::string toString();
};