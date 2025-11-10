#include <string>
#include "Passport.h"

using std::string, std::vector;

// TODO(student): implement constructor using member initializer list
Passport::Passport(string camperName, bool isJuniorPassport) : camperName{camperName}, isJuniorPassport{isJuniorPassport}, parksVisited{} {}

string Passport::getCamperName() const {
    // TODO(student): implement getter

    return camperName;
}

bool Passport::checkJuniorPassport() const {
    // TODO(student): implement getter

    return isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
    INFO(park)

    // TODO(student): implement function
    parksVisited.push_back(park);

    // addCamper() function used to add itself to the camperLog of that state park
    park->addCamper(this);
}

double Passport::getMilesHiked() const {
    // TODO(student): (optional) implement function

    return {};
}

int Passport::getHikerLevel() const {
    // TODO(student): (optional) implement function

    return {};
}
