#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <numeric>

template <typename T>
void print_container(const T& container) noexcept {
  for (auto elem : container) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

double square(const double x) noexcept { return x * x; }

int main() {
  std::array<double, 20> data;
  std::iota(data.begin(), data.end(), 0.0);
  print_container(data);

  double power = 3.0;
  auto apply_math_op = [&power](const double x) { return pow(x, power); };
  std::transform(data.begin(), data.end(), data.begin(), apply_math_op);
  print_container(data);

  power = 1.0 / power;
  std::transform(data.begin(), data.end(), data.begin(), apply_math_op);
  print_container(data);

  const double other_power = 4.0;
  auto other_apply_math_op = [&other_power](const double x) noexcept {
    //other_power += 1;
    return pow(x, other_power);
  };
  std::transform(data.begin(), data.end(), data.begin(), other_apply_math_op);
  print_container(data);

  return 0;
}
