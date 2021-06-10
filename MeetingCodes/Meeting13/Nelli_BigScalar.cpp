#include <iostream>
#include <vector>
#include <limits>
#include <cstddef>
#include <gsl/gsl>

class BigScalar {
    public:
    std::vector<double> data{};

    BigScalar(const gsl::not_null<std::vector<double>*> init_data) {
        data = *init_data;
    }

    BigScalar(std::vector<double>&& init_data) {
        data = std::move(init_data);
    }
};

int main() {
    constexpr size_t size = 100000000;
    std::vector<double> test_vector{};
    test_vector.resize(size);
    for (double& elem : test_vector) {
        elem = 0.0;
    }
    // BigScalar big_scalar{gsl::make_not_null(&test_vector)};
    BigScalar big_scalar{std::move(test_vector)};
    
    std::cout << gsl::at(big_scalar.data, size / 2) << "\n";
    
    double x = std::numeric_limits<double>::signaling_NaN();
    x = big_scalar.data[4];
    std::cout << x+ 7 << "\n";

    return 0;
}
