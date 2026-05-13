#include <string>
#include "classes.h"

Name::Name(std::string name, std::string surname, std::string patronymic): name(name), surname(surname), patronymic(patronymic) {}

std::string Name::getName() {
    return name;
}

std::string Name::getSurname() {
    return surname;
}

std::string Name::getPatronymic() {
    return patronymic;
}

void Name::setName(std::string name) {
    this->name = name;
}

void Name::setSurname(std::string surname) {
    this->surname = surname;
}

void Name::setPatronymic(std::string patronymic) {
    this->patronymic = patronymic;
}

std::string Name::toString() {
    std::string result;

    if (!surname.empty())
        result += surname + " ";

    result += name;

    if (!patronymic.empty())
        result += " " + patronymic;

    return result;
}

