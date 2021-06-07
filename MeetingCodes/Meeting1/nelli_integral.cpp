#include <iostream>
#include <iomanip>
#include <cmath>

/// function \f$ \sqrt(1-x^2) \f$ for
/// testing numerical integration
double f(const double x) noexcept {
    return sqrt(fabs(1.0 - x*x));
}

/// function to numerically integrate using left midpoint
double left(const double dx, const double a, const double b) {
    double result;
    for(double x=a; x<b; x+=dx) {
        result += dx*f(x);
    }
    return result;
}

int main() {
    constexpr double lower_bound = 0.0;
    constexpr double upper_bound = 1.0;
    constexpr double step_size   = 1.e-9;

    const double numerical_result = 
                    4*left(step_size,lower_bound,upper_bound);

    std::cout << std::setprecision(15);
    std::cout << numerical_result << std::endl;
    std::cout << M_PI << std::endl;
    std::cout << "Error: " << numerical_result - M_PI << std::endl;
}

