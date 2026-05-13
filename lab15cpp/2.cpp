#include <string>
#include "classes.h"

Person::Person(Name name, int height, Person* father): name(name), height(height), father(father) {
    if (father != nullptr) {

        if (this->name.getSurname().empty()) {
            this->name.setSurname(
                father->getName().getSurname()
            );
        }

        if (this->name.getPatronymic().empty()) {
            this->name.setPatronymic(
                father->getName().getName() + "ович"
            );
        }
    }
}

Name Person::getName() {
    return name;
}

std::string Person::toString() {
    return name.toString() + ", рост: " + std::to_string(height);
}
