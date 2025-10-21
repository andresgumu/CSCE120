#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main() {
  std::string filename;
  std::cout << "Enter donation filename: ";
  std::cin >> filename;
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Failed to open file " << filename << "." << std::endl;
    return 1;
  }

  double max_total_donation = 0;
  int max_collector = 0;
  int maxNumDonations = 0;

  std::string line;
  while (std::getline(ifs, line)) {
    // TODO(student): use a stringstream to extract values from the line
    if (line.empty()){ // check for empty line
      continue;
    }

    std::stringstream ss(line);
    int current_ID = 0;
    double current_total = 0.0;
    int donation_count = 0;
    if (!(ss >> current_ID)) { // try to read ID
      continue;
    }

    double donation;

    while (ss >> donation) {
      if (donation >= 0.0){ // only process non-negative numbers
        current_total += donation;
        donation_count++;
      }
    }
    if (ss.fail() && !ss.eof()){
      std::string temp;
      ss.clear();
      // perform loop again
      while (ss >> donation) {
      if (donation >= 0.0){ 
        current_total += donation;
        donation_count++;
      }
    }
    }

    // TODO(student): use the data to determine the most
    if (donation_count >= 2){ // needs to have at least two donations
      if (max_collector == 0 || donation_count > maxNumDonations){ // checks current, and then the rest if needed
        maxNumDonations = donation_count;
        max_collector = current_ID;
      }
    }

  }

  if (max_collector != 0) {
    std::cout << "Most donations: " << maxNumDonations << std::endl;
    std::cout << "-- collected by id: " << max_collector << std::endl;
  } else {
    std::cout << "No winner." << std::endl;
  }

  return 0;
}