#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Database.h"

using std::cout, std::cin, std::endl, std::string, std::ifstream,
      std::istringstream, std::vector;

int get_selection();
void task1(Database&);
void task2(Database&);
void task3(Database&);

int main() {
    // TODO(student): uncomment after completing Task 1
    Database db;

    try {
        // TODO(student): uncomment after completing Task 1
        task1(db);
    } catch (std::runtime_error const& err) {
        cout << err.what() << endl;
        return 1;
    }

    int selection = 0;

    // TODO(student): uncomment after completing Task 2
    // selection = get_selection();

    switch(selection) {
        // TODO(student): uncomment after completing Task 2
        // case 1: task2(db); break;

        // TODO(student): uncomment after completing Task 3
        // case 2: task3(db); break;
    }

    return 0;
}

int get_selection() {
    cout << "Welcome to the State Park Passport Database!\n";
    cout << "Please select from the following options:\n";
    cout << "1: Get all parks with revenue in range.\n";
    cout << "2: Get all hikers at or above a certain level.\n";
    cout << "Your Selection: ";
    int selection = 0;
    cin >> selection;
    return selection;
}

void task1(Database& db) {
    ifstream ifs_parks("park_data.txt");

    if (!ifs_parks.is_open()) {
        throw std::runtime_error("Error: could not open park data file");
    }

    while (!ifs_parks.eof()) {
        string park_name = "";
        string s_park_fee = "";
        string s_trail_length = "";
        getline(ifs_parks, park_name, ',');
        getline(ifs_parks, s_park_fee, ',');
        getline(ifs_parks, s_trail_length);
        db.addStatePark(park_name, stod(s_park_fee), stod(s_trail_length));
    }

    ifstream ifs_campers("camper_data.txt");

    if (!ifs_campers.is_open()) {
        throw std::runtime_error("Error: could not open camper data file");
    }

    while (!ifs_campers.eof()) {
        string line = "";
        getline(ifs_campers, line, '\n');
        if (line == "") break;
        string camper_name = "";
        string s_junior = "";
        istringstream iss_line(line);
        getline(iss_line, camper_name, ',');
        getline(iss_line, s_junior, ',');
        bool junior = static_cast<bool>(stoi(s_junior));
        db.addPassport(camper_name, junior);
        while (!iss_line.eof()) {
            string park = "";
            getline(iss_line, park, ',');
            park.erase(0, 1);
            db.addParkToPassport(camper_name, park);
        }
    }
}

void task2(Database& db) {
    double lower_bound = 0, upper_bound = 0;
    cout << "Enter Lower Bound then Upper bound: ";
    cin >> lower_bound >> upper_bound;
    vector<string> park_result = db.getParksInRevenueRange(lower_bound, upper_bound);

    cout << "These are all the parks with revenue in the range given" << endl;
    for (unsigned int i = 0; i < park_result.size(); ++i) {
        cout << park_result.at(i) << endl;
    }
}

void task3(Database& db) {
    int hiking_level = 0;
    cout << "Enter Hiking Level: ";
    cin >> hiking_level;
    vector<string> hiker_results = db.getHikersAtLeastLevel(hiking_level);

    cout << "These are all the campers with hiking level at least " << hiking_level << endl;
    for (unsigned int i = 0; i < hiker_results.size(); ++i) {
        cout << hiker_results.at(i) << endl;
    }
}
