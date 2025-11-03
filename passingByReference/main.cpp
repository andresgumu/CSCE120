#include <cassert>
#include <iostream>
#include "functions.h"

using std::cout, std::endl;

// simple helper function to print array
void print_array(int* arr, unsigned size) {
    cout << "[";
    for (unsigned i = 0; i < size; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << "]";
}

void test_function_one() {
    int i = 3;
    int j = 4;

    cout << "---function_one()---\n\n";
    cout << "Values before execution:\n";
    cout << "  i: " << i << '\n';
    cout << "  j: " << j << '\n';

	cout << "calling function_one...\n";

    function_one(i, j);

	cout << "returned from function_one\n";

    cout << "Values after execution:\n";
    cout << "  i: " << i << '\n';
    cout << "  j: " << j << '\n';
	cout << endl;

    assert(i == 3);
    assert(j == 5);
}

void test_function_two() {
    Example example{4};

    cout << "---function_two()---\n\n";
    cout << "Values before execution:\n";
    cout << "  example.value: " << example.value << '\n';

	cout << "calling function_two...\n";

    function_two(example);

	cout << "returned from function_two\n";

    cout << "Values after execution:\n";
    cout << "  example.value: " << example.value << '\n';
	cout << endl;

    assert(example.value == 5);
}

void test_function_three() {
    int a = 3;
    int b = 4;

    cout << "---function_three()---\n\n";
    cout << "Values before execution:\n";
    cout << "  a: " << a << '\n';
    cout << "  b: " << b << '\n';

	cout << "calling function_three...\n";

    function_three(&a, b);

	cout << "returned from function_three\n";

    cout << "Values after execution:\n";
    cout << "  a: " << a << '\n';
    cout << "  b: " << b << '\n';
	cout << endl;

    assert(a == 4);
    assert(b == 5);
}

void test_function_four() {
    int* array = new int[5]{0, 1, 2, 3, 4};
    int* original_array = array;
    int lowest = 0;
    int highest = 0;

    cout << "---function_four()---\n\n";
    cout << "Values before execution:\n";
    cout << "   lowest: " << lowest << '\n';
    cout << "  highest: " << highest << '\n';
    cout << "    array: "; print_array(array, 5);
	cout << '\n';

	cout << "calling function_four...\n";

    function_four(array, 5, lowest, highest);

	cout << "returned from function_three\n";

    cout << "Values after execution:\n";
    cout << "   lowest: " << lowest << '\n';
    cout << "  highest: " << highest << '\n';
    cout << "    array: "; print_array(array, 5);
	cout << endl;

    assert(array == original_array);
    assert(array[0] == 2);
    assert(array[1] == 3);
    assert(array[2] == 4);
    assert(array[3] == 5);
    assert(array[4] == 6);
    assert(lowest == 2);
    assert(highest == 6);

    delete [] array;
}

int main() {
    test_function_one();
    test_function_two();
    test_function_three();
    test_function_four();
}
