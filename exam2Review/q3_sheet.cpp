#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

void func(int* x, int& y, int** z) {
    (*x)--;
    y += 2;
    x = new int;
    *x = y;
    **z *= 2;
}
int main() {
    int a = 1;
    int b = 2;
    int* x = &a;
    int& y = b;
    int** z = &x;
    func(x, y, z);
    std::cout << a << " " << b << " " << **z << std::endl;
    return 0;
}