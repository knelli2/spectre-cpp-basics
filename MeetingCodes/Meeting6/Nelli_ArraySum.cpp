#include <array>
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
std::string to_str(const T& container) {
    std::stringstream stream{};
    auto it = container.begin();
    stream << "[";
    for (; it!= container.end(); it++) {
        stream << *it << " ";
    }
    std::string result = stream.str();
    result.pop_back();
    return result + "]";
}

template <typename T>
T operator+(const T& lhs, const T& rhs) noexcept {
    T result{lhs};

    auto it_rhs = rhs.begin();
    auto it_result = result.begin();

    for (; it_rhs != rhs.end(); ++it_rhs, ++it_result) {
        *it_result += *it_rhs;
    }

    return result;
}

int main() {
    std::array<double, 3> test_array{1.0, 4.0, 3.0};
    std::array<double, 3> test_array2{4.4, 4.4, 5.0};
    std::array<double, 2> test_array_short{1.0, 4.0};
    std::array<int, 2> test_array_short2{1, 4};

    std::cout << to_str(test_array + test_array2) << std::endl;
    // won't compile because different types
    //std::cout << to_str(test_array + test_array_short) << std::endl;
    //std::cout << to_str(test_array_short + test_array_short2) << std::endl;

    return 0;
}
