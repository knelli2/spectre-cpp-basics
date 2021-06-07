#include <cstddef>
#include <iostream>

int sum_numbers() noexcept {
    int result = 0;
    for (size_t i=0; i<100000; i++) {
        result += i;
    }
    return result;
}

constexpr int sum_numbers_constexpr() noexcept {
    int result = 0;
    for (size_t i=0; i<100000; i++) {
        result += i;
    }
    return result;
}

int main() {
    size_t result = 0;
    constexpr size_t maxit = 2000;
    for (size_t i=0; i<maxit; i++) {
        result = sum_numbers();
        //constexpr size_t result_constexpr = sum_numbers_constexpr();
        if (i ==maxit-1) {
        //    std::cout << result_constexpr << std::endl;
        }
    }
    std::cout << sum_numbers() << std::endl;
}

