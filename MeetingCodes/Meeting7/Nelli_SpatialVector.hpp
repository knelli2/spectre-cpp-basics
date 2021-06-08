#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

namespace Frame {
    struct Grid{};
    struct Inertial {};
} // namespace Frame

template <typename DataType, size_t VolumeDim, typename Fr>
class SpatialVector {
  public:
    static constexpr size_t volume_dim = VolumeDim;
    using frame = Fr;
    using data_type = DataType;

    SpatialVector(const std::array<DataType, VolumeDim>& data) noexcept
        : data_(data) {}

    const auto& get(const size_t i) const noexcept {
        if (i < VolumeDim) {
            return data_[i];
        } else {
            std::cout << "ERROR: index i = " << i << " out of bounds for VolumeDim = "
                      << volume_dim << "\n";
            exit(-1);
        }
    }

  private:
    std::array<DataType, VolumeDim> data_;
};

template <size_t Index, typename T>
const auto& get(const T& vector) noexcept {
    static_assert(Index < T::volume_dim, "Index should be less than VolumeDim");
    return vector.get(Index);
}

template <typename DataType, size_t VolumeDim, typename Fr>
DataType dot(const SpatialVector<DataType, VolumeDim, Fr>& vec_a,
             const SpatialVector<DataType, VolumeDim, Fr>& vec_b) noexcept {
    DataType result{get<0>(vec_a) * get<0>(vec_b)};
    for (size_t i=1; i< VolumeDim; ++i) {
        result += vec_a.get(i) * vec_b.get(i);
    }
    return result;
}

template <typename T>
std::string to_str(const T& container) noexcept {
    std::stringstream output_stream{};
    output_stream << "[";
    for (auto elem : container) {
        output_stream << elem << " ";
    }
    std::string output_string = output_stream.str();
    output_string.pop_back();

    return output_string + "]";
}

// to_string() for SpatialVectors
template <typename DataType, size_t VolumeDim, typename Fr>
std::string to_str(const SpatialVector<DataType, VolumeDim, Fr>& spatial_vector) noexcept {
    std::stringstream output_stream{};
    output_stream << "[";
    for (size_t i=0; i< VolumeDim; ++i) {
        output_stream << to_str(spatial_vector.get(i)) << " ";
    }
    std::string output_string = output_stream.str();
    output_string.pop_back();

    return output_string + "]";
}
