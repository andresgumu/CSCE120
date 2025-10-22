#include <iostream>


int main() {
    using namespace std;
    int x {};
    cout << "Enter the radius of circle: ";
    cin >> x;
    double area = 3.142 * x * x;
    cout << "Area of circle with radius 7 is: " << area;

    std::cout << "Select shape (Circle : 1 , Triangle : 2, Square: 3) : ";

    int selection;
    std::cin >> selection;

    if (selection == 1){
        // Circle selected
        std::cout << "Enter radius of circle : ";
        float r;
        std::cin >> r;
        std::cout << "Area of circle : " << 3.142 * r * r << std::endl;
    }
    else if (selection == 2){
        // Triangle selected
        std::cout << "Enter base and height of triangle : ";
        float b, h;
        std::cin >> b >> h;
        std::cout << "Area of Triangle : " << 0.5 * b * h << std::endl;
    }
    else if(selection == 3){
        std::cout << "Enter side value of square : ";
        float q;
        std::cin >> q;
        std::cout << "Area of Square : " << q * q << std::endl;
    }
    else{
        // Invalid Selection
        std::cout << "Invalid selection." << std::endl;
    }

    // If we make a mistake and put both selections as 1. What would happen.
    // A) Both conditions will execute
    // B) Only Circle will run
    // C) Only Triangle will run
    // D) Invalid selection will run

    return 0;
}

class Complex {
    private:
        int r;
        int i;
    public:
        Complex(){}
        Complex(double r): r{r} {}
        Complex(double r, double i): r{r}, i{i} {}

        Complex operator+(const Complex& rhs){
            return Complex(this->r + rhs.r, this->i + rhs.i);
        };
        Complex operator-(const Complex& rhs){
            return Complex(this->r - rhs.r, this->i - rhs.i);
        }
        Complex operator/(const Complex& rhs){
            return Complex(this->r / rhs.r, this->i / rhs.i);
        }
        Complex operator*(const Complex& rhs){
            return Complex(this->r * rhs.r, this->i * rhs.i);
        }
        Complex operator==(const Complex& rhs){
            return Complex(this->r == rhs.r, this->i == rhs.i);
        }
        // stream input and output (didn't have enough time)

};