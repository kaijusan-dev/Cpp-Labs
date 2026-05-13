#include <string>
#include <vector>
#include <cmath>
#include "classes.h"

Point::Point(int x, int y) : x(x), y(y) {}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

std::string Point::toString() {
    return "{" + std::to_string(x) + ";" + std::to_string(y) + "}";
}

Polyline::Polyline() {}
Polyline::Polyline(std::vector<Point*> points): points(points) {}

void Polyline::addPoints(std::vector<Point*> newPoints) {
    for (Point* point : newPoints) {
        points.push_back(point);
    }
}

int Polyline::length() {

    double sum = 0;

    for (size_t i = 1; i < points.size(); i++) {

        int dx = points[i]->getX() - points[i - 1]->getX();

        int dy = points[i]->getY() - points[i - 1]->getY();

        sum += sqrt(dx * dx + dy * dy);
    }

    return sum;
}

std::string Polyline::toString() {

    std::string result = "Линия [";

    for (size_t i = 0; i < points.size(); i++) {

        result += points[i]->toString();

        if (i != points.size() - 1)
            result += ", ";
    }

    result += "]";

    return result;
}
