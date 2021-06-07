#pragma once

class Rectangle {
  public:
    Rectangle(const double width, const double height) :
        width_(width), height_(height) {}

    double perimeter() const;

    double width() const {return width_;}
    double height() const {return height_;}

    static int number_of_sides() {return 4;}
  private:
    double width_;
    double height_;
};
