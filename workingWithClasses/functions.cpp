// add more includes as necessary
#include "functions.h"
#include <iostream>
#include <sstream>

using namespace std;

// deobfuscate a sentence
// arg 1: obfuscated sentence
// arg 2: deobfuscation details
// returns the deobfuscated sentence
std::string deobfuscate(const std::string& sentence, const std::string& code) {
    // TODO(student)
    std::string new_code = "";
    size_t count = 0;
    std::string result = sentence;
    for(size_t i = 0; i < code.size(); i++) {
        int num = code[i] - '0';
        count = count + num;
        size_t position = count + i; //append at the count + the number of spaces already added
        if (i != code.size() - 1) {
            result.insert(position,1, ' ');
        }
    }
        return result;

    return "";
}

// replace filter word with octothorpes (#)
// arg 1: sentence
// arg 2: filter word
// returns the filtered sentence
std::string wordFilter(const std::string&, const std::string&) {
    // TODO(student)
    return "";
}

// convert a string to a secure password
// arg 1: text
// returns a secure password based on the text
std::string passwordConverter(const std::string& text) {
    // TODO(student)
    string newPass = text;
    for (int i = 0; i < text.length(); i++){
        if (text[i] == 'a'){
            newPass[i] = '@';
        }
        if (text[i] == 'e'){
            newPass[i] = '3';
        }
        if (text[i] == 'i'){
            newPass[i] = '!';
        }
        if (text[i] == 'o'){
            newPass[i] = '0';
        }
        if (text[i] == 'u'){
            newPass[i] = '^';
        }
    }
    string reversedNewPass = newPass;
    for (int j = 0; j < newPass.length(); j++){
        reversedNewPass.push_back(newPass[newPass.length() - 1 - j]);
    }


    return reversedNewPass;
}

// calculate the result of an arithmetic expression in words
// arg 1: expression using words
// returns an arithmetic equation using numerals and arithmetic symbols
std::string wordCalculator(const std::string&) {
    // TODO(student)
    return "";
}

// count the palindromes in the text
// arg 1: text
// returns the number of palindromes in the text
unsigned int palindromeCounter(const std::string&) {
    // TODO(student)
    return 0;
}
