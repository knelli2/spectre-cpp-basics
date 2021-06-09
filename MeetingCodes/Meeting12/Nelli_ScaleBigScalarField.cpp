#include <chrono>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

class ScalarField {
 public:
  std::vector<double> x{};
  size_t size = 0;

  ScalarField(const size_t init_size) noexcept {
    x.resize(init_size);
    size = init_size;
  }

  void resize(const size_t new_size) noexcept {
    x.resize(new_size);
    size = new_size;
  }
};

ScalarField init_scalar_field(const size_t size,
                              const double init_value) noexcept {
  ScalarField field{size};
  std::iota(field.x.begin(), field.x.end(), init_value);
  return field;
}

void scale_scalar_field(ScalarField& field,
                        const double scale_factor) noexcept {
  for (auto it = field.x.begin(); it != field.x.end(); ++it) {
    *it *= scale_factor;
  }
}

ScalarField scale_scalar_field(ScalarField&& field,
                               const double scale_factor) noexcept {
  for (auto it = field.x.begin(); it != field.x.end(); ++it) {
    *it *= scale_factor;
  }
  return std::move(field);
}

int main() {
  constexpr size_t size = 1000000000;
  constexpr double init_value = 0.0;
  constexpr double scale_factor = 10.0;
  using clock = std::chrono::high_resolution_clock;
  auto start_time = clock::now();
  auto stop_time = clock::now();

  std::cout << "Initializing scalar field of size " << size << "\n";
  start_time = clock::now();

  ScalarField field_a = init_scalar_field(size, init_value);
  stop_time = clock::now();
  std::cout << field_a.x[size / 2] << " Time taken: "
            << std::chrono::duration_cast<std::chrono::microseconds>(stop_time -
                                                                     start_time)
                   .count()
            << "us\n\n";

  std::cout << "Scaling scalar field\n";
  start_time = clock::now();
  scale_scalar_field(field_a, scale_factor);

  stop_time = clock::now();
  std::cout << field_a.x[size / 2] << " Time taken: "
            << std::chrono::duration_cast<std::chrono::microseconds>(stop_time -
                                                                     start_time)
                   .count()
            << "us\n\n";

  std::cout << "Scaling scalar field using std::move\n";
  start_time = clock::now();
  ScalarField field_b = scale_scalar_field(std::move(field_a), scale_factor);

  stop_time = clock::now();
  std::cout << field_b.x[size / 2] << " Time taken: "
            << std::chrono::duration_cast<std::chrono::microseconds>(stop_time -
                                                                     start_time)
                   .count()
            << "us\n\n";

  return 0;
}
