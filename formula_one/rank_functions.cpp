#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "rank_functions.h"

using namespace std;

// load data from standard input into a vector
//   input format := <time> <country> <number> <name>
//   examples:
//     32.7 AUS 81 Piastri
//     36.5 NED 1  Verstappen
//   rank should be initialized to 0 for each driver
// returns a vector of drivers, or an empty vector if any input is invalid

std::vector<driver> load_driver_data() {
    // TODO(student)

    driver new_driver {};
    //--------------enter loop that iterates over each driver line------------------

    vector<driver> drivers;
    while (cin >> new_driver.time >> new_driver.country >> new_driver.number){

        getline(cin, new_driver.lastname); // get the rest of the line (since last name has two "tokens")
        new_driver.lastname = trim(new_driver.lastname); // remove leading space seperating it from other values
        
        //-----------check if any input is invalid----------------

        // time must be positive
        if (new_driver.time < 0.0){
            return {}; // return empty vector
        }

        // country must be 3 letters long and have all capital letters
        if ((new_driver.country).size() == 3){
            for (int i = 0; i < 3; i++){
                if (!isupper(new_driver.country[i])){
                    return {};
                }
            }
        }
        else { return {}; }

        // car number must be in range [0,99]
        if (new_driver.number > 99 || new_driver.number < 0){
            return {};
        }

        // last name must contain only letters and spaces & contain at least two letters
        if ((new_driver.lastname).size() >= 2){
            for (int j = 0; j < ((new_driver.lastname)).size(); j++){
                if (!isspace(new_driver.lastname[j]) && !isalpha(new_driver.lastname[j])){
                    return {};
                }
            }
        } 
        else { return {}; }

        new_driver.rank = 0;

        // store into vector if valid
        drivers.push_back(new_driver);
    }

    return drivers;
}   

// returns a copy of the input vector with ranks set based on the time for each driver.
//   the fastest/minimum time is ranked 1
// the order of the elements in the vector should not be changed
std::vector<driver> set_rankings(std::vector<driver> withRanks) {
    // TODO(student)

    // read each time
    // for loop storing times into new vector
    vector<double> times {};
    for (int i = 0; i < withRanks.size(); i++){
        times.push_back(withRanks[i].time);
    }
    // compare times
    int rank = 1;
    int index = 0;
    int bestTime = 100000;
    vector<double> timesCopy = times;

    // set max to first index, check and swap index if next one is bigger (highest -> lowest)
    for(int j = 0; j < times.size(); j++){
        for (int k = 0; k < timesCopy.size(); k++){
            if (bestTime > timesCopy[k]){
                bestTime = times[k];
                index = k;
            }
            timesCopy.erase(timesCopy.begin() + k);
        }
        withRanks[index].rank = rank;
        rank++;
    }

    // assign correct rankings in correct indexes
    // return updated copy


    return {};
}

// returns a copy of the input string with whitespace removed from the front and back
std::string trim(std::string str) {
    // TODO(student)

    // iterative process to remove ALL whitespace

    while (isspace(str.front()) && !str.empty()){ // isspace() supposed to handle \t and \r
        str.erase(str.begin());
    }
    while (isspace(str.back()) && !str.empty()){
        str.pop_back(); 
    }
}

// print the results of the race
void print_results(const std::vector<driver>& drivers) {
    // get the fastest time
    double best_time;
    for (const driver& driver : drivers) {
        if (driver.rank == 1) {
            best_time = driver.time;
            break;
        }
    }

    std::cout << "Final results!";
    std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
    for (unsigned rank = 1; rank <= drivers.size(); rank++) {
        for (const driver& driver : drivers) {
            if (driver.rank == rank) {
                std::string rank_str = "["+std::to_string(rank)+"]";
                std::cout << std::setw(4) << std::left << rank_str << " " << driver.time << " " << std::setw(15) << std::left << driver.lastname << " (" << driver.country << ") +" << (driver.time - best_time) << std::endl;
            }
        }
    }
}
