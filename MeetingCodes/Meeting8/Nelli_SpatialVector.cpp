#include "Nelli_SpatialVector.hpp"

#include <cmath>
#include <cstddef>
#include <iostream>
#include <iomanip>

// stand-in for DataVector
// don't ever do this in SpECTRE
// just use spectre's DataVector

#include <valarray>
using DataVector = std::valarray<double>;

void print_2d_DataVector(const DataVector& vector) {
    size_t pts_per_row = static_cast<size_t>(sqrt(static_cast<double>(vector.size())));
    std::cout << std::setprecision(5) << std::fixed;
    for (size_t i = 0; i < vector.size(); ++i) {
        if (i % pts_per_row  == 0) {
            std::cout << "\n";
        }
        if (vector[i] < 0.0) {
            std::cout << vector[i] << " ";
        } else {
            std::cout << " " << vector[i] << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    DataVector axis_coords{1.0, -1.0, -3.0, 5.0};
    DataVector axis_coords2{4.0, -3.0, -5.0, 5.0};
    std::array<DataVector, 2> axis_array{axis_coords, axis_coords2};
    SpatialVector<DataVector, 2, Frame::Inertial> vec_1d{axis_array};
    std::cout << to_str(vec_1d) << std::endl;

    SpatialVector<double, 3, Frame::Inertial> vec{{1.0, 4.0, 9.0}};

    std::cout << get<0>(vec) << std::endl;

    // grid calculation
    constexpr size_t volume_dim = 2;
    constexpr size_t pts_per_dim = 9;
    const size_t num_of_pts = pow(pts_per_dim, volume_dim);
    constexpr double lower_bound = -4.0;
    constexpr double upper_bound =  4.0;
    constexpr double delta = (upper_bound - lower_bound) / 
        static_cast<double>(pts_per_dim - 1);

    DataVector x_coords(0.0, num_of_pts);
    DataVector y_coords(0.0, num_of_pts);

    size_t i = 0;
    for (double y = upper_bound; y >= lower_bound; y -= delta) {
        for (double x = lower_bound; x <= upper_bound; x += delta) {
            x_coords[i] = x;
            y_coords[i] = y;
            ++i;
        }
    }

    SpatialVector<DataVector, 2, Frame::Inertial> coords{{x_coords, y_coords}};
    std::cout << to_str(coords) << std::endl;

    print_2d_DataVector(x_coords);
    print_2d_DataVector(y_coords);

    print_2d_DataVector(exp(-0.25*dot(coords, coords)));

    return 0;
}
