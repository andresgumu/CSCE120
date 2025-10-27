#include <iostream>
using std::cout;
using std::endl;
int sideEffectSum(int c, int& d) {
    c *= 3;
    d /= 2;
    return c + d;
}

int swapIfEvenSum(int& a, int& b) { // pass by reference, actually changes z and y
    if ((a+b)%2 == 0) {
        int temp = a;
        a = b;
        b = temp;
}
    return sideEffectSum(a, b);
}

int heapSum(int* e, int* f) {
    return *e + *f;
}

int main()
{
    int z = 12;
    int y = 7;

    // new operator returns the memory address of the newly allocated storage
    int *w = new int(swapIfEvenSum(z, y)); // allocates heap memory
    z++; // z becomes 13
    int *v = new int(swapIfEvenSum(z, y)); // allocates heap memory

    int u = heapSum(w,v);

    cout << u << " " << *v << " " << *w << " ";
    cout << y << " " << z << endl;

    delete w; // need to delete whatever is allocated on heap
    delete v;

    return 0;

    cout << "-----------------------" << endl;
    
}

