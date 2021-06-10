#include <iostream>
#include <vector>
#include <cstddef>
#include <gsl/gsl>

class BigScalar {
    public:
    std::vector<double> data{};

    BigScalar(const std::vector<double>& init_data) {
        data = init_data;
    };
};

int main() {
    constexpr size_t size = 100000000;
    std::vector<double> test_vector{};
    test_vector.resize(size);
    for (double& elem : test_vector) {
        elem = 0.0;
    }
    BigScalar big_scalar{test_vector};
    
    std::cout << big_scalar.data[size/2] << "\n";

    return 0;
}
