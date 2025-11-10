#include <string>
#include <vector>
#include "Database.h"

using std::string, std::vector;

// TODO(student): implement constructor using member initializer list
Database::Database() : stateParkList{}, camperList{} {}

Database::~Database() {
    for (StatePark* park : stateParkList) {
        delete park;
    }
    for (Passport* camper : camperList) {
        delete camper;
    }
}

void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
    INFO(parkName)
    INFO(entranceFee)
    INFO(trailMiles)

    // TODO(student): implement function
    StatePark* state_park = new StatePark(parkName, entranceFee, trailMiles);
    stateParkList.push_back(state_park);
}

void Database::addPassport(string camperName, bool isJuniorPassport) {
    INFO(camperName)
    INFO(isJuniorPassport)

    // TODO(student): implement function
    Passport* passport = new Passport(camperName, isJuniorPassport);
    camperList.push_back(passport);
}

void Database::addParkToPassport(string const& camperName, string const& parkName) {
    INFO(camperName)
    INFO(parkName)

    // TODO(student): implement function

    // stateParkList and camperList are the member vectors
    bool parkNameMatch = false;
    bool camperNameMatch = false;
    StatePark* park = nullptr;
    Passport* passport = nullptr;
    
    for (size_t i = 0; i < stateParkList.size(); i++){
        if (stateParkList.at(i)->getParkName() == parkName){
            parkNameMatch = true;
            park = stateParkList.at(i);
        }
    }

    for (size_t j = 0; j < camperList.size(); j++){
        if (camperList.at(j)->getCamperName() == camperName){
            camperNameMatch = true;
            passport = camperList.at(j);

        }
    }

    if (parkNameMatch && camperNameMatch){
        passport->addParkVisited(park);
    }

}

vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) const {
    INFO(lowerBound)
    INFO(upperBound)

    // TODO(student): (optional) implement function

    return {};
}

vector<string> Database::getHikersAtLeastLevel(int level) const {
    INFO(level)

    // TODO(student): (optional) implement function

    return {};
}
