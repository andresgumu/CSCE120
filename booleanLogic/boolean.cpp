// THIS FILE IS PROVIDED.  DO NOT EDIT.

#include <iostream>
#include <limits>
#include "boolean_functions.h"

bool getBoolVal(std::string varName) {
    char boolChar = ' ';
    while (tolower(boolChar) != 't' && tolower(boolChar) != 'f') {
        std::cout << "Input T for true and F for false." << std::endl;
        std::cout << "Input value for " << varName << ": ";
        std::cin >> boolChar;
    }
    if (tolower(boolChar) == 't') {
        return true;
    }
    return false;
}

void processBooleanLogic1() {
    bool x = getBoolVal("x");
    bool y = getBoolVal("y");
    bool z = getBoolVal("z");
    booleanLogic1(x, y, z);
}

void processBooleanLogic2() {
    bool x = getBoolVal("x");
    bool y = getBoolVal("y");
    bool z = getBoolVal("z");
    booleanLogic2(x, y, z);
}

void processBooleanLogic3() {
    bool x = getBoolVal("x");
    bool y = getBoolVal("y");
    bool z = getBoolVal("z");
    booleanLogic3(x, y, z);
}

void processCountLetters() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, str);
    unsigned int cnt = countLetters(str);
    std::cout << "String : " << str << std::endl;
    std::cout << "Letters: " << cnt << std::endl;
}

void processMysteryFunction() {
    bool x = getBoolVal("x");
    bool y = getBoolVal("y");
    bool z = getBoolVal("z");
    bool value = f(x, y, z);
    std::cout << std::boolalpha << "f(" << x << ", " << y << ", " << z << ") = " << value << std::endl;
}

void processSetAssignments() {
    bool w, x, y, z;
    setAssignments(w, x, y, z);
    std::cout << "w (" << std::boolalpha << w << ")" << std::endl;
    std::cout << "x (" << std::boolalpha << x << ")" << std::endl;
    std::cout << "y (" << std::boolalpha << y << ")" << std::endl;
    std::cout << "z (" << std::boolalpha << z << ")" << std::endl;
    bool value = x && (w || y) && (!w || !z) && (!y || z);
    std::cout << "x AND (w OR y) AND (NOT w OR NOT z) AND (NOT y or z) = " << value << std::endl;
}

void processSelection(int selection) {
    switch (selection) { // tolower lets X or x be valid
        case 1: printNOT(); break;
        case 2: printOR(); break;
        case 3: printAND(); break;
        case 4: printXOR(); break;
        case 5: processBooleanLogic1(); break;
        case 6: processBooleanLogic2(); break;
        case 7: processBooleanLogic3(); break;
        case 8: processCountLetters(); break;
        case 9: processMysteryFunction(); break;
        case 10: processSetAssignments(); break;
        case 0: break;
        default: std::cout << selection << " is not a valid option." << std::endl;
    }
}

int getChoice() {
    int selection = -1;
    std::cout << "Input number of the boolean logic function to run (1 - 10)." << std::endl;
    std::cout << "Input 0 to exit." << std::endl;
    std::cout << "Choice: ";
    std::cin >> selection;
    return selection;
}

void print_functions() {
    std::cout << "List of Boolean Functions" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "1) printNOT" << std::endl;
    std::cout << "2) printOR" << std::endl;
    std::cout << "3) printAND" << std::endl;
    std::cout << "4) printXOR" << std::endl;
    std::cout << "5) booleanLogic1" << std::endl;
    std::cout << "6) booleanLogic2" << std::endl;
    std::cout << "7) booleanLogic3" << std::endl;
    std::cout << "8) countLetters" << std::endl;
    std::cout << "9) f" << std::endl;
    std::cout << "10) setAssignments" << std::endl;
}

int main() {
    print_functions();
    int selection = -1;
    while (tolower(selection) != 0) {
        selection = getChoice();
        processSelection(selection);
    }

}