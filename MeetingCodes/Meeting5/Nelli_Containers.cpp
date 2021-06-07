#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
std::string print(const T& container) noexcept {
  std::stringstream result;
  result << "[";

  for (auto elem : container) {
    result << elem << " ";
  }

  std::string output = result.str();
  output.pop_back();

  return output + "]";
}

template <typename T>
T operator+(const T& lhs,
            const T& rhs) noexcept {
  T result{lhs};
  auto it_result = result.begin();
  auto it_rhs = rhs.begin();
  for (; it_result != result.end(); ++it_result, ++it_rhs) {
    *it_result += *it_rhs;
  }
  return result;
}

int main() {
  std::vector<double> vec{1.0, 4.0, 9.0};
  std::cout << print(vec) << std::endl;

  vec.push_back(16.0);
  std::cout << print(vec) << std::endl;

  vec.pop_back();
  vec.pop_back();

  std::cout << print(vec) << std::endl;

  std::array<double, 3> arr1{1.0, 2.0, 3.0};
  std::array<double, 3> arr2{2.0, 4.0, 6.0};

  std::cout << print(arr1) << std::endl;

  std::array<double, 3> sum = arr1 + arr2;
  std::cout << print(sum) << std::endl;

  //std::array<double, 2> short_arr{1.0, 4.0};
  //std::cout << print(arr1 + short_arr) << std::endl;

  return 0;
}
