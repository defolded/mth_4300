#include <iostream>

auto& calculateMax(double& num1, double& num2) {
    if (num1 == num2) return num1;
    return (num1 > num2) ? num1 : num2;
}

bool checkNumber(double& num) {
    return ((5 < num && num < 15) || (95 < num && num < 202));
}

int main() {
    std::cout << "Hi\n";
    std::cout << "Please, enter the first number for comparison: ";
    double j,k;
    std::cin >> j;
    std::cout << "Enter the second number: ";
    std::cin >> k;
    std::cout << "The bigger number is: " << calculateMax(j, k) << "\n\n";

    double i;
    std::cout << "Please enter a real number: ";
    std::cin >> i;
    std::cout << (checkNumber(i) ? "Yes" : "No") << "\n\n";

    while(true) {
        double d;
        std::cout << "Please enter a number: ";
        std::cin >> d;
        if (d > 100) {
            std::cout << "Congratulations! You know about big numbers!" << std::endl;
            break;
        }
        d = 0.0;
        std::cout << "Try again with a bigger number." << std::endl;
    }

    return 0;
}
