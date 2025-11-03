#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct Example {
    int value;
};

void function_one(int i, int& j);
void function_two(Example& example);
void function_three(int* k, int& l);
void function_four(int array[], int size, int& lowest, int& highest);

#endif  // FUNCTIONS_H_
