#include <iostream>
#include <string>

template <typename T>
T square(const T& x) {
  return x * x;
}

template <typename T>
T add_to_self(const T& x) {
  return x + x;
}

template <typename T>
T halve(const T& x) {
  return x / 2;
}

template <>
double halve(const double& x) {
  return 0.5 * x;
}

int main() {
  std::cout << square(4.0) << std::endl;
  std::cout << add_to_self(5.0) << std::endl;
  std::cout << halve(3.0) << std::endl;

  std::cout << halve(3) << std::endl;

  std::cout << halve<double>(3) << std::endl;
  std::cout << halve<int>(3.0) << std::endl;

  const std::string somestring{"Hello"};
  std::cout << add_to_self(somestring) << std::endl;
  return 0;
}
