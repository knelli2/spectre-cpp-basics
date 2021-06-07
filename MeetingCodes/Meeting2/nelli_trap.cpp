#include <cmath>

#include "nelli_trap.hpp"

/// function to numerically integrate using trap midpoint
double trap(double (* const func)(const double), 
            const double step_size, const double lower_bound,
                                    const double upper_bound) noexcept {
    double result;
    for(double x=lower_bound; x<upper_bound; x+=step_size) {
        result += step_size*func(x);
        result += 0.5 * step_size * (func(x+step_size)-func(x));
    }
    return result;
}
