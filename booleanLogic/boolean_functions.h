// THIS FILE IS PROVIDED.  DO NOT EDIT.

#ifndef BOOLEAN_FUNCTIONS_H
#define BOOLEAN_FUNCTIONS_H

#include <string>

// 1. [4 points] Print the truth table for NOT
void printNOT();
// 2. [4 points] Print the truth table for OR
void printOR();
// 3. [4 points] Print the truth table for AND
void printAND();
// 4. [4 points] Print the truth table for XOR
void printXOR();
// 5. [10 points] Compute x OR y OR z, given an assignment of truth values
bool booleanLogic1(bool x, bool y, bool z);
// 6. [10 points] Compute x AND y AND z, given an assignment of truth values
bool booleanLogic2(bool x, bool y, bool z);
// 7. [10 points] Compute x XOR y XOR z, given an assignment of truth values
bool booleanLogic3(bool x, bool y, bool z);
// 8. [3 points] debug the function
unsigned int countLetters(std::string str);
// 9. [5 points] find a boolean formula for the truth table
bool f(bool x, bool y, bool z);
// 10. [5 points] find truth values to satisfy a boolean formula
void setAssignments(bool& w, bool& x, bool& y, bool& z);

#endif