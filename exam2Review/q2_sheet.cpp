#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

void func(int& x, int*& y, int* z) {
    x++;
    (*y)++;
    y = z;
    *y += 2;
}
int main() {
    int num1 = 8;
    int num2 = 14;
    int a = 5;
    int* b = &num1;
    int* c = &num2;
    func(a, b, c);
    std::cout << a << " " << *b << " " << *c << " " << std::endl;
    return 0;
}