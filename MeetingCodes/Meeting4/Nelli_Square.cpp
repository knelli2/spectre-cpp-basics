#include "Nelli_Square.hpp"

Square::Square(const double length) noexcept : Rectangle(length, length) {}

double Square::Perimeter() const noexcept { return 4.0 * length_; }

double Square::Area() const noexcept { return length_ * length_; }