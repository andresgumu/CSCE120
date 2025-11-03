#include <iostream>
#include "functions.h"

void function_one(int i, int& j) {
    // TODO(student): implement function_one so that it
    //                * takes two integer arguments i and j
    //                * adds 2 to i
    //                * adds 1 to j
    //                such that only the change to j persist after the function returns
    i += 2;
    j += 1;

}

void function_two(Example& example) {
    // TODO(student): implement function_two so that it
    //                * takes an argument of type Example
    //                * increments its integer by 1
    //                such that the change persists after the function returns
    example.value += 1;

}

void function_three(int* k, int& l) {
    // TODO(student): implement function_three so that it
    //                * increments both variables by one
    //                such that both changes persist after the function returns
    //                throw a std::invalid_argument exception if any argument is invalid
    if(k ==nullptr){
        throw std::invalid_argument("invalid argument");
    }

    *k += 1;
    l += 1;
}

void function_four(int array[], int size, int& lowest, int& highest) {
    // TODO(student): implement function_four so that it
    //                * increments every value by two
    //                * sets lowest / highest to the min / max of the array
    //                such that all changes persist after the function returns
    //                throw a std::invalid_argument exception if any argument is invalid

    if (array == nullptr || size == 0){
        throw std::invalid_argument("invalid argument(s)");
    }

    highest = array[0] + 2;
    lowest = array[0] + 2;

    for (int i = 0; i < size; i++){
        array[i] += 2;
        if (highest < array[i]){ // search to find biggest
            highest = array[i];
        }

        if (lowest > array[i]){ // search to find smallest
            lowest = array[i];
        }
    }
}
