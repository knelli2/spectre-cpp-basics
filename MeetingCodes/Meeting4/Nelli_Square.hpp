#pragma once

#include "Nelli_Rectangle.hpp"

class Square : public Rectangle {
 public:
  Square(double length) noexcept;

  double Perimeter() const noexcept;
  double Area() const noexcept;
};
