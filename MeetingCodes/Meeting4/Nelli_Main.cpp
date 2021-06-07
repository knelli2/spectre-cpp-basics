#include <iomanip>
#include <iostream>

#include "Nelli_Rectangle.hpp"
#include "Nelli_Square.hpp"

int main() {
  const Rectangle rect{5.0, 3.0};
  Rectangle rect2(5.0, 6.0);

  std::cout << std::setprecision(15) << std::fixed;
  std::cout << "Length of rect: " << rect.length() << std::endl;
  std::cout << "Width of rect : " << rect.width() << std::endl;
  std::cout << "Perimeter of rect: " << rect.Perimeter() << std::endl;
  std::cout << "Number of sides: " << rect.number_of_sides() << std::endl;
  std::cout << "Area of rect: " << rect.Area() << std::endl;

  Square sq{4.0};

  std::cout << "Square perimeter : " << sq.Perimeter() << std::endl;
  std::cout << "Area of Square: " << sq.Area() << std::endl;

  return 0;
}
