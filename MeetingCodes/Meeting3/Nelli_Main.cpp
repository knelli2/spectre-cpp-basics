#include <iostream>
#include <iomanip>

#include "Nelli_Rectangle.hpp"

int main() {
    const Rectangle rect{5.0, 3.0};
    Rectangle rect2(5.0, 6.0);

    double x{4.0};

    std::cout << std::setprecision(15) << std::fixed;
    std::cout << "Width of rect : " << rect.width() << std::endl;
    std::cout << "Height of rect: " << rect.height() << std::endl;
    std::cout << "Perimiter of rect: " << rect.perimeter() << std::endl;
    std::cout << "Number of sides: " << rect.number_of_sides() << std::endl;
}
