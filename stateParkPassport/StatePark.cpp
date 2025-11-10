#include <string>
#include "StatePark.h"
#include "Passport.h"

using std::string, std::vector;

// TODO(student): implement constructor using member initializer list
StatePark::StatePark(std::string parkName, double entranceFee, double trailMiles) : parkName{parkName}, entranceFee{entranceFee}, trailMiles{trailMiles}, camperLog{} {}

string StatePark::getParkName() const {
    // TODO(student): implement getter

    return parkName;
}

double StatePark::getEntranceFee() const {
    // TODO(student): implement getter

    return entranceFee;
}

double StatePark::getTrailMiles() const {
    // TODO(student): implement getter

    return trailMiles;
}

void StatePark::addCamper(Passport* camper) {
    INFO(camper)

    // TODO(student): implement function
    camperLog.push_back(camper);
}

double StatePark::getRevenue() const {
    // TODO(student): (optional) implement function

    return {};
}
