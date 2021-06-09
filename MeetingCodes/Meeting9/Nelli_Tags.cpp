#include <iostream>
#include <tuple>
#include <utility>

template <typename T, size_t Extra>
T sum(const T& lhs, const T& rhs) noexcept {
  return lhs + rhs + static_cast<double>(Extra);
}

namespace Rect {
struct Width {};
struct Height {};
}  // namespace Rect

template <typename T>
double area(const T& box) noexcept {
  return std::get<std::pair<Rect::Width, double>>(box).second *
         std::get<std::pair<Rect::Height, double>>(box).second;
}

int main() {
  for (double x = 0.0; x < 1.0; x += 0.1) {
    std::cout << sum<double, 4>(x, x + 1.0) << "\n";
  }

  // std::pair example
  std::pair<Rect::Width, double> width{{}, 4.0};
  std::pair<Rect::Height, double> height{{}, 4.0};

  // std::tuple example
  std::tuple<std::pair<Rect::Width, double>, std::pair<Rect::Height, double>>
      box{{{}, 4.0}, {{}, 5.0}};
  std::cout << area(box) << "\n";

  return 0;
}
