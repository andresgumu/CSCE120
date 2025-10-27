#include <iostream>
#include <string>
#include <vector>


struct FruitBox {
    std::vector<std::string> fruits;
};

void fill_box(FruitBox& box) {
    box.fruits = {"apple", "orange"};
}

int main() {
    FruitBox box_1;
    FruitBox& box_2 = box_1;
    fill_box(box_2);
    std::cout << box_1.fruits[0] << " " << box_1.fruits[1] << std::endl;
}