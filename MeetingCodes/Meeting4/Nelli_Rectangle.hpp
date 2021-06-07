#pragma once

#include "Nelli_Polygon.hpp"

class Rectangle : public Polygon {
  public:
    Rectangle(double length, double width) noexcept;

    double Perimeter() const noexcept override;

    double Area() const noexcept;

    double length() const {return length_;}
    double width() const {return width_;}

    static int number_of_sides() {return 4;}
  protected:
    double length_;
    double width_;
};
